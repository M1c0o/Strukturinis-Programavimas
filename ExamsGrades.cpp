#include <iostream>
#include <cmath>
int main() {

    int Grade;

    std::cout << "Enter the grade: " << std::endl;
    std::cin >> Grade;

    if (Grade == 10) {
        std::cout << "Great :) " << std::endl;
    }
        else if (Grade >= 9 ) {
            std::cout << "Very good :) " << std::endl;
        }
            else if (Grade >= 7 ) {
                std::cout << "Good :) " << std::endl;
            }
                else if (Grade >= 5) {
                    std::cout << "satisfactorily :) " << std::endl;
                }
                    else if (Grade < 5) {
                        std::cout << "Exam failed :( " << std::endl;
                    }
                    return 0;
}
