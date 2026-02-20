#include <iostream>
#include <fstream>
#include <cmath>
int main()
{
    int Number_1, Number_2, Number_3, Number_4;
    int sum = 0;
    int count = 4;
    int average;

    std::cout << "Enter the Number_1: " << std::endl;
    std::cin >> Number_1;
    std::cout << "Enter the Number_2: " << std::endl;
    std::cin >> Number_2;
    std::cout << "Enter the Number_3: " << std::endl;
    std::cin >> Number_3;
    std::cout << "Enter the Number_4: " << std::endl;
    std::cin >> Number_4;

    sum = Number_1 + Number_2 + Number_3 + Number_4;

    std::cout << "Your answer is: " << sum << std::endl;

    average = sum/count;

    std::cout << "Your answer is: " << average << std::endl;

    if (average >=5) {
        std::cout << "Average is positive :) " << std::endl;
    }
        else {
            std::cout << "Average is negative :( " << std::endl;
        }

    return 0;
}
