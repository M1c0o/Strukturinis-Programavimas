#include <iostream>

int main() {
    for (int i = 1; i <= 20; i++) {
        if (i % 4 == 0) {
            std::cout << i << std::endl;
            std::cout << "All numbers Divided by four :) " << std::endl;
        }
    }
    return 0;
}
