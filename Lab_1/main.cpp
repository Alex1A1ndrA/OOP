#include <iostream>
#include <string>
#include "function.cpp"
#include <cctype>

int main() {
    std::string day_week;
    int number;

    std::cout << "Введите день недели: ";
    std::cin >> day_week;

    std::cout << "Введите число: ";
    std::cin >> number;

    bool result = fear(day_week, number);

    if (result) {
        std::cout << "Вы боитесь этого числа." << std::endl;
    } else {
        std::cout << "Вы не боитесь этого числа." << std::endl;
    }

    return 0;
}
