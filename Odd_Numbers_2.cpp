#include <iostream>
int main() {

    int sum = 0;

    for (int i = 1; i <= 20; i += 2)
        {
            sum += i;
        }

        std::cout << "Answer is: " << sum << std::endl;
            return 0;
}
