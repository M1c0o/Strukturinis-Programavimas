#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_MOKINIAI = 100;
    const int MAX_PAZYMIAI = 10;

    string vardai[MAX_MOKINIAI];
    int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI];
    int kiekis_pazymiu[MAX_MOKINIAI] = {0}; // Kiek paþymiø turi kiekvienas mokinys
    int mokiniu_skaicius = 0;
    int pasirinkimas;

    while (true) {
        cout << "\n--- MOKINIU VALDYMO SISTEMA ---\n";
        cout << "1. Ivesti nauja mokini ir jo pazymius\n";
        cout << "2. Perziureti visus mokinius\n";
        cout << "3. Perziureti konkretaus mokinio pazymius\n";
        cout << "4. Atnaujinti konkretu pazymi\n";
        cout << "5. Pasalinti mokini is saraso\n";
        cout << "0. Iseiti\n";
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 0) break;

        switch (pasirinkimas) {
            case 1: { // Ávedimas
                if (mokiniu_skaicius < MAX_MOKINIAI) {
                    cout << "Iveskite mokinio varda: ";
                    cin >> vardai[mokiniu_skaicius];

                    int n;
                    cout << "Kiek pazymiu ivesite (iki 10)? ";
                    cin >> n;
                    if (n > MAX_PAZYMIAI) n = MAX_PAZYMIAI;

                    kiekis_pazymiu[mokiniu_skaicius] = n;
                    for (int i = 0; i < n; i++) {
                        cout << "Iveskite " << i + 1 << "-aji pazymi: ";
                        cin >> pazymiai[mokiniu_skaicius][i];
                    }
                    mokiniu_skaicius++;
                } else {
                    cout << "Sarasas pilnas!\n";
                }
                break;
            }
            case 2: { // Perþiûra (visi)
                if (mokiniu_skaicius == 0) cout << "Sarasas tuscias.\n";
                for (int i = 0; i < mokiniu_skaicius; i++) {
                    cout << i + 1 << ". " << vardai[i] << " | Pazymiai: ";
                    for (int j = 0; j < kiekis_pazymiu[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 3: { // Konkretus mokinys
                int nr;
                cout << "Iveskite mokinio numeri is saraso: ";
                cin >> nr;
                if (nr > 0 && nr <= mokiniu_skaicius) {
                    cout << vardai[nr-1] << " pazymiai: ";
                    for (int j = 0; j < kiekis_pazymiu[nr-1]; j++) {
                        cout << pazymiai[nr-1][j] << " ";
                    }
                    cout << endl;
                } else cout << "Neteisingas numeris.\n";
                break;
            }
            case 4: { // Atnaujinimas
                int m_nr, p_nr;
                cout << "Kurio mokinio (nr.) pazymi keisite? ";
                cin >> m_nr;
                if (m_nr > 0 && m_nr <= mokiniu_skaicius) {
                    cout << "Kuri pazymi (nr.) keisite? ";
                    cin >> p_nr;
                    if (p_nr > 0 && p_nr <= kiekis_pazymiu[m_nr-1]) {
                        cout << "Iveskite nauja pazymi: ";
                        cin >> pazymiai[m_nr-1][p_nr-1];
                        cout << "Atnaujinta!\n";
                    } else cout << "Neteisingas pazymio numeris.\n";
                } else cout << "Neteisingas mokinio numeris.\n";
                break;
            }
            case 5: { // Ðalinimas
                int m_nr;
                cout << "Kuri mokini (nr.) pasalinti? ";
                cin >> m_nr;
                if (m_nr > 0 && m_nr <= mokiniu_skaicius) {
                    for (int i = m_nr - 1; i < mokiniu_skaicius - 1; i++) {
                        vardai[i] = vardai[i+1];
                        kiekis_pazymiu[i] = kiekis_pazymiu[i+1];
                        for (int j = 0; j < MAX_PAZYMIAI; j++) {
                            pazymiai[i][j] = pazymiai[i+1][j];
                        }
                    }
                    mokiniu_skaicius--;
                    cout << "Mokinys pasalintas.\n";
                } else cout << "Neteisingas numeris.\n";
                break;
            }
            default:
                cout << "Tokio pasirinkimo nera.\n";
        }
    }
    return 0;
}
