#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struktūra valiūtų kursams saugoti
struct Kursai {
    double bendras;
    double pirkti;
    double parduoti;
};

int main() {
    // 1. Duomenų paruošimas
    Kursai GBP = {0.8729, 0.8600, 0.9220};
    Kursai USD = {1.1793, 1.1460, 1.2340};
    Kursai INR = {104.6918, 101.3862, 107.8546};

    int pasirinkimas;
    string valiutosKodas;
    double kiekis, rezultatas;
    Kursai pasirinktaValiuta;
    bool testi = true; // Kintamasis ciklo valdymui
    char arTesti;

    while (testi) { // Ciklo pradžia
        cout << "--- Valiutos Keitykla ---" << endl;
        cout << "1. Valiutos kurso palyginimas" << endl;
        cout << "2. Pirkti valiuta (is EUR i kita)" << endl;
        cout << "3. Parduoti valiuta (is kitos i EUR)" << endl;
        cout << "4. Baigti darba" << endl;
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 4) {
            testi = false;
            break;
        }

        cout << "Iveskite valiutos koda (GBP, USD, INR): ";
        cin >> valiutosKodas;

        // Valiutos pasirinkimas
        if (valiutosKodas == "GBP")
            pasirinktaValiuta = GBP;
        else if (valiutosKodas == "USD")
            pasirinktaValiuta = USD;
        else if (valiutosKodas == "INR")
            pasirinktaValiuta = INR;
        else {
            cout << "Klaida: Neteisingas valiutos kodas!" << endl;
            continue; // Griztame i ciklo pradzia
        }

        cout << fixed << setprecision(2);

        // 2. Logika pagal pasirinkima
        switch (pasirinkimas) {
            case 1:
                cout << "1 EUR bendras kursas yra: " << pasirinktaValiuta.bendras << " " << valiutosKodas << endl;
                break;
            case 2:
                cout << "Kiek EUR norite konvertuoti i " << valiutosKodas << "? ";
                cin >> kiekis;
                rezultatas = kiekis * pasirinktaValiuta.pirkti;
                cout << "Gausite: " << rezultatas << " " << valiutosKodas << endl;
                break;
            case 3:
                cout << "Kiek " << valiutosKodas << " norite parduoti? ";
                cin >> kiekis;
                rezultatas = kiekis / pasirinktaValiuta.parduoti;
                cout << "Gausite: " << rezultatas << " EUR" << endl;
                break;
            default:
                cout << "Klaida: Neteisingas pasirinkimas!" << endl;
        }

        cout << "-------------------------" << endl;
        cout << "Ar norite testi? (y/n): ";
        cin >> arTesti;
        if (arTesti != 'y' && arTesti != 'Y') {
            testi = false;
        }
    }

    return 0;
}
