#include <iostream>
#include <cmath>
#include <iomanip>
int main() {


    double Principal_amount = 1000;
    double Annual_interest_rate = 0.05;
    int Number_of_years = 10;

    double Final_Amount = Principal_amount * std::pow((1 + Annual_interest_rate), Number_of_years);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "After " << Number_of_years << " years, the final amount is: "
        << Final_Amount << " EUR " << std::endl;


    return 0;

}
