#include <iostream>
#include <string>
#include <iomanip> //Reikalinga apvalinimui (serprecision)

using namespace std;



    // Struktūra valiūtų kursams saugoti

    struct Kursai {

        double bendras;
        double pirkti;
        double parduoti;

    };

    int main() {


            // 1. Duomenų paruošimas pagal užduotį

            Kursai GBP = {0.8729, 0.8600, 0.9220};
            Kursai USD = {1.1793, 1.1460, 1.2340};
            Kursai INR = {104.6918, 101.3862, 107.8546};

            int pasirinkimas;
            string valiutosKodas;
            double kiekis, rezultatas;
            Kursai pasirinktaValiuta;

            cout << "--- Valiutos Keitykla ---" << endl;
                cout << "1. Valiutos kurso palyginimas" << endl;
                cout << "2. Pirkti valiuta (is EUR i kita)" << endl;
                cout << "3. Parduoti valiuta (is kitos  i EUR)" << endl;
                cout << "Pasirinkite valiuta: ";
                cin >> pasirinkimas;

                cout << "Iveskite valiutos koda (GBP, USD, INR): ";
                    cin >> valiutosKodas;

                    // Valiutos pasirinkimas pagal ivesti
                        if (valiutosKodas == "GBP")
                    pasirinktaValiuta = GBP;
                        else if (valiutosKodas == "USD")
                        pasirinktaValiuta = USD;
                            else if (valiutosKodas == "INR")
                            pasirinktaValiuta = INR;
                        else {
                            cout << "Klaida: Neteisingas valiutos kodas!" << endl;
                                return 1; // signalizuoja, kad vykdymo metu įvyko klaida.
                        }

                        // Nustatoma isvesti rodyti 2 skaicius po kablelio (simtuju tikslumu)
                        cout << fixed << setprecision(2);

                        // 2. Logika pagal pasirinkim1
                        switch (pasirinkimas) { // paima kintamaji ir iesko atitinkamo case bloko.
                    case 1:
                            cout << "1 EUR bendras kursas yra: " << pasirinktaValiuta.bendras << " " << valiutosKodas << endl;
                                break; // stop zenklas, pasako programai: 0132Viskas darb1 siame bloke baigeme.
                    case 2:
                            cout << " Kiek EUR norite konvertuoti i " << valiutosKodas << "? ";
                                cin >> kiekis;
                                    rezultatas = kiekis * pasirinktaValiuta.pirkti;
                                        cout << "Gausite: " << rezultatas << " " << valiutosKodas << endl;
                                            break;
                    case 3:
                            cout << "kiek " << valiutosKodas << " norite parduoti? ";
                            cin >> kiekis;
                            rezultatas = kiekis / pasirinktaValiuta.parduoti;
                            cout << "Gausite: " << rezultatas << "EUR" << endl;
                                break;
                    default: // suveikia tik tada kai neivienas case nesuveikia
                        cout << "Klaid: Neteisingas pasirinkimas!" << endl;
                        }
                return 0;
    }