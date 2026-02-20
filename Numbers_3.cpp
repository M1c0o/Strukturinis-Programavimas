#include <iostream>

int main() {
    for (int i = 1; i <= 20; i++) {
        if (i % 4 == 0) {
            // Iðvedame skaièiø, tekstà ir patá dalybos rezultatà (i / 4)
            std::cout << i << " Divided by four: " << i / 4 << std::endl;
        }
    }
    return 0;
}
