#include <iostream>
#include <fstream>   // Darbui su failais (ifstream, ofstream)
#include <vector>    // Dinaminiam masyvui (užsakymui saugoti)
#include <iomanip>   // Išvesties formatavimui (setw, setprecision)
#include <string>

using namespace std;

// Struktūra aprašanti vieną meniu elementą
struct menuItemType {
    string menuItem;     // Patiekalo pavadinimas
    double menuPrice;    // Kaina
};

// Struktūra skirta saugoti kliento pasirinkimą (patiekalas + kiekis)
struct OrderItem {
    menuItemType item;   // Įdedame visą patiekalo informaciją
    int quantity;        // Kiek porcijų užsakė
};

// Funkcijų prototipai (deklaracijos)
int getData(menuItemType menuList[]);
void showMenu(menuItemType menuList[], int count);
void printCheck(vector<OrderItem>& order);

int main() {
    // Lietuviškų simbolių palaikymas konsolėje
    setlocale(LC_ALL, "Lithuanian");

    menuItemType menuList[50]; // Masyvas, kuriame saugosime visą restorano meniu
    int itemCount = getData(menuList); // Užpildome masyvą duomenimis iš failo

    // Patikriname, ar failas nebuvo tuščias
    if (itemCount == 0) {
        cout << "Klaida: Nepavyko nuskaityti meniu failo!" << endl;
        return 1;
    }

    showMenu(menuList, itemCount); // Parodome vartotojui meniu

    // Naudojame vector, nes nežinome iš anksto, kiek skirtingų patiekalų vartotojas užsisakys
    vector<OrderItem> customerOrder;
    int choice, qty;

    cout << "\nĮveskite patiekalo numerį (arba 0, jei norite baigti): " << endl;

    // Ciklas užsakymų rinkimui
    while (cin >> choice && choice != 0) {
        if (choice > 0 && choice <= itemCount) {
            cout << "Kiek porcijų? ";
            cin >> qty;
            if (qty > 0) {
                // .push_back prideda naują įrašą į vektoriaus galą
                customerOrder.push_back({menuList[choice - 1], qty});
            }
        } else {
            cout << "Neteisingas pasirinkimas!" << endl;
        }
        cout << "Kitas pasirinkimas (0 - baigti): ";
    }

    // Jei klientas kažką užsisakė, generuojame sąskaitą
    if (!customerOrder.empty()) {
        printCheck(customerOrder);
    } else {
        cout << "Užsakymas nebuvo sukurtas." << endl;
    }

    return 0;
}

// Funkcija nuskaityti duomenis iš "menu.txt"
int getData(menuItemType menuList[]) {
    ifstream file("menu.txt"); // Atidarome failą skaitymui
    int i = 0;
    if (file.is_open()) {
        // Skaitome pavadinimą ir kainą, kol pasiekiame failo pabaigą
        while (file >> menuList[i].menuItem >> menuList[i].menuPrice) {
            i++;
        }
        file.close(); // Uždarome failą
    }
    return i; // Grąžiname, kiek patiekalų pavyko nuskaityti
}

// Funkcija rodyti meniu ekrane
void showMenu(menuItemType menuList[], int count) {
    cout << "--- RESTORANO MENIU ---" << endl;
    for (int i = 0; i < count; i++) {
        string name = menuList[i].menuItem;
        // Pakeičiame apatinius brūkšnius tarpais, kad gražiau atrodytų
        for (size_t j = 0; j < name.length(); j++) if (name[j] == '_') name[j] = ' ';

        // setw(30) rezervuoja vietą pavadinimui, kad kainos būtų lygiuotos
        cout << i + 1 << ". " << left << setw(30) << name
             << fixed << setprecision(2) << menuList[i].menuPrice << "€" << endl;
    }
}

// Funkcija skaičiavimams ir sąskaitos išvedimui
void printCheck(vector<OrderItem>& order) {
    double subtotal = 0;      // Suma be PVM
    const double VAT = 0.21;  // 21% PVM tarifas

    ofstream outFile("receipt.txt"); // Sukuriame/atidarome failą čekio įrašymui

    // Lambda funkcija 'output' leidžia rašyti kodą vieną kartą,
    // bet išvesti duomenis ir į ekraną (cout), ir į failą (outFile)
    auto output = [&](ostream& os) {
        os << "\n--- SĄSKAITA ---" << endl;
        for (const auto& entry : order) {
            string name = entry.item.menuItem;
            for (size_t j = 0; j < name.length(); j++) if (name[j] == '_') name[j] = ' ';

            double lineTotal = entry.item.menuPrice * entry.quantity; // Kaina * kiekis
            subtotal += lineTotal; // Pridedame prie bendros sumos

            os << entry.quantity << " x " << left << setw(25) << name
               << fixed << setprecision(2) << lineTotal << "€" << endl;
        }

        double tax = subtotal * VAT; // PVM skaičiavimas
        double total = subtotal + tax; // Galutinė suma

        os << "\n----------------------------" << endl;
        os << left << setw(28) << "Mokesčiai (21%):" << tax << "€" << endl;
        os << left << setw(28) << "Galutinė suma:" << total << "€" << endl;
    };

    output(cout);    // Spausdiname į ekraną
    output(outFile); // Įrašome į failą

    outFile.close();
    cout << "\nSąskaita įrašyta į receipt.txt" << endl;
}
