#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Konstantos
const int MAX_MENU = 20; // Maksimalus meniu áraðø kiekis

// Privaloma struktûra
struct menuItemType {
    string menuItem;     // patiekalo pavadinimas
    double menuPrice;    // patiekalo kaina
};

// Papildoma struktûra uþsakymui sekti
struct orderType {
    int menuIndex; // Kuris patiekalas ið menuList
    int count;     // Kiek porcijø
};

// Funkcijø prototipai
void getData(menuItemType menuList[], int &itemCount);
void showMenu(menuItemType menuList[], int itemCount);
void printCheck(menuItemType menuList[], orderType userOrders[], int orderCount);

int main() {
    menuItemType menuList[MAX_MENU];
    orderType userOrders[MAX_MENU];
    int itemCount = 0;
    int orderCount = 0;

    // 1. Nuskaitome duomenis
    getData(menuList, itemCount);

    if (itemCount == 0) {
        cout << "Klaida: Nepavyko nuskaityti meniu!" << endl;
        return 1;
    }

    // 2. Rodome meniu
    showMenu(menuList, itemCount);

    // 3. Uþsakymo procesas
    int choice;
    cout << "\nIveskite patiekalo numeri (arba 0, kad baigti): ";
    while (cin >> choice && choice != 0) {
        if (choice > 0 && choice <= itemCount) {
            int qty;
            cout << "Kiek porciju? ";
            cin >> qty;

            if (qty > 0) {
                userOrders[orderCount].menuIndex = choice - 1; // -1, nes masyvas prasideda nuo 0
                userOrders[orderCount].count = qty;
                orderCount++;
            }
        } else {
            cout << "Tokio patiekalo nera!" << endl;
        }
        cout << "Kitas pasirinkimas (0 - baigti): ";
    }

    // 4. Sàskaitos generavimas
    if (orderCount > 0) {
        printCheck(menuList, userOrders, orderCount);
    } else {
        cout << "Uzsakymu nebuvo." << endl;
    }

    return 0;
}

void getData(menuItemType menuList[], int &itemCount) {
    ifstream file("menu.txt");
    if (file.is_open()) {
        while (itemCount < MAX_MENU && file >> menuList[itemCount].menuItem >> menuList[itemCount].menuPrice) {
            // Pakeièiame pabraukimo brûkðnius á tarpus dël graþaus rodymo
            for (int i = 0; i < menuList[itemCount].menuItem.length(); i++) {
                if (menuList[itemCount].menuItem[i] == '_') {
                    menuList[itemCount].menuItem[i] = ' ';
                }
            }
            itemCount++;
        }
        file.close();
    }
}

void showMenu(menuItemType menuList[], int itemCount) {
    cout << "Sveiki atvyke i restorana \"Skanu\"" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << i + 1 << ". " << left << setw(35)
             << menuList[i].menuItem << " "
             << fixed << setprecision(2) << menuList[i].menuPrice << " EUR" << endl;
    }
    cout << "-----------------------------------" << endl;
    cout << "Iveskite skaiciu ir spauskite Enter." << endl;
}

void printCheck(menuItemType menuList[], orderType userOrders[], int orderCount) {
    ofstream outFile("receipt.txt");
    double subtotal = 0;
    double taxRate = 0.21;

    // Antraðtë ekrane
    cout << "\nJUSU SASKAITA:" << endl;
    cout << "-----------------------------------" << endl;

    // Antraðtë faile
    outFile << "JUSU SASKAITA:" << endl;
    outFile << "-----------------------------------" << endl;

    for (int i = 0; i < orderCount; i++) {
        int idx = userOrders[i].menuIndex;
        int qty = userOrders[i].count;
        double linePrice = menuList[idx].menuPrice * qty;
        subtotal += linePrice;

        // Iðvedimas á ekranà
        cout << qty << " " << left << setw(30) << menuList[idx].menuItem
             << fixed << setprecision(2) << linePrice << " EUR" << endl;

        // Iðvedimas á failà
        outFile << qty << " " << left << setw(30) << menuList[idx].menuItem
                << fixed << setprecision(2) << linePrice << " EUR" << endl;
    }

    double pvm = subtotal * taxRate;
    double total = subtotal + pvm;

    // Galutinës sumos á ekranà
    cout << "\n" << left << setw(32) << "Mokesciai (21%)" << pvm << " EUR" << endl;
    cout << left << setw(32) << "Galutine suma" << total << " EUR" << endl;

    // Galutinës sumos á failà
    outFile << "\n" << left << setw(32) << "Mokesciai (21%)" << pvm << " EUR" << endl;
    outFile << left << setw(32) << "Galutine suma" << total << " EUR" << endl;

    outFile.close();
    cout << "\nSaskaita issaugota receipt.txt faile." << endl;
}
