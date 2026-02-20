#include <iostream>

int main() {
    int pazymys = 8;

    switch (pazymys) {
        case 10:
            std::cout << "puiku" << std::endl;
            break;
        case 9:
            std::cout << "labai gerai" << std::endl;
            break;
        case 8:
        case 7:
            std::cout << "gerai" << std::endl;
            break;
        case 6:
        case 5:
            std::cout << "patenkinamai" << std::endl;
            break;
        default:
            if (pazymys < 5 && pazymys >= 0) {
                std::cout << "egzaminas neislaikytas" << std::endl;
            } else {
                std::cout << "Neteisingas ávertinimas" << std::endl;
            }
            break;
    }

    return 0;
}
