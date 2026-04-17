#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_MENU = 20;

struct menuItemType {
    string menuItem;
    double menuPrice;
};

struct orderType {
    int menuIndex;
    int count;
};

// Funkcijų prototipai
void getData(menuItemType menuList[], int &itemCount);
void showMenu(menuItemType menuList[], int itemCount);
void printCheck(menuItemType menuList[], orderType userOrders[], int orderCount);

int main() {
    menuItemType menuList[MAX_MENU];
    orderType userOrders[MAX_MENU];
    int itemCount = 0;
    int orderCount = 0;

    getData(menuList, itemCount);

    if (itemCount == 0) {
        cout << "Klaida: Nepavyko nuskaityti meniu!" << endl;
        return 1;
    }

    showMenu(menuList, itemCount);

    int choice;
    cout << "\nIveskite patiekalo numeri (arba 0, kad baigti): ";
    while (cin >> choice && choice != 0) {
        if (choice > 0 && choice <= itemCount) {
            int qty;
            cout << "Kiek porciju? ";
            cin >> qty;

            if (qty > 0 && orderCount < MAX_MENU) {
                userOrders[orderCount].menuIndex = choice - 1;
                userOrders[orderCount].count = qty;
                orderCount++;
            }
        } else {
            cout << "Tokio patiekalo nera!" << endl;
        }
        cout << "Kitas pasirinkimas (0 - baigti): ";
    }

    if (orderCount > 0) {
        printCheck(menuList, userOrders, orderCount);
    } else {
        cout << "Uzsakymu nebuvo." << endl;
    }

    return 0;
}

// SUTVARKYTA FUNKCIJA (Pirmakursio lygis)
void getData(menuItemType menuList[], int &itemCount) {
    itemCount = 0;
    ifstream file("menu.txt");

    if (!file.is_open()) return;

    while (itemCount < MAX_MENU) {
        string name = "";
        char c;

        // 1. Skaitome raides po vieną, kol sutiksime skaičių (kainos pradžią)
        while (file.get(c)) {
            // Jei simbolis yra skaičius (nuo 0 iki 9)
            if (c >= '0' && c <= '9') {
                // "Grąžiname" skaičių atgal į failą, kad galėtume jį nuskaityti kaip double
                file.putback(c);
                break;
            }
            name += c;
        }

        // Jei pasiekėme failo pabaigą ir nieko nenuskaitėme - baigiam
        if (file.eof()) break;

        // 2. Dabar saugiai nuskaitome kainą
        double price;
        if (file >> price) {
            menuList[itemCount].menuItem = name;
            menuList[itemCount].menuPrice = price;
            itemCount++;
        }

        // Išvalome likusius tarpus ar naujas eilutes iki kito patiekalo
        while (file && (file.peek() == ' ' || file.peek() == '\n' || file.peek() == '\r')) {
            file.ignore();
        }
    }
    file.close();
}

void showMenu(menuItemType menuList[], int itemCount) {
    cout << "\nRESTORANO MENIU" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << i + 1 << ". " << left << setw(35)
             << menuList[i].menuItem << " "
             << fixed << setprecision(2) << menuList[i].menuPrice << " EUR" << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

void printCheck(menuItemType menuList[], orderType userOrders[], int orderCount) {
    ofstream outFile("receipt.txt");
    double subtotal = 0;

    cout << "\n--- CEKIS ---" << endl;
    for (int i = 0; i < orderCount; i++) {
        int idx = userOrders[i].menuIndex;
        double kaina = menuList[idx].menuPrice * userOrders[i].count;
        subtotal += kaina;

        cout << userOrders[i].count << " x " << left << setw(30)
             << menuList[idx].menuItem << kaina << " EUR" << endl;

        outFile << userOrders[i].count << " x " << left << setw(30)
                << menuList[idx].menuItem << kaina << " EUR" << endl;
    }

    double pvm = subtotal * 0.21;
    double viso = subtotal + pvm;

    cout << "-----------------------------------------------" << endl;
    cout << "PVM (21%): " << pvm << " EUR" << endl;
    cout << "VISO: " << viso << " EUR" << endl;

    outFile << "-----------------------------------------------" << endl;
    outFile << "PVM (21%): " << pvm << " EUR" << endl;
    outFile << "VISO: " << viso << " EUR" << endl;

    outFile.close();
}

