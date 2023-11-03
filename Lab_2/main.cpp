#include <iostream>
#include "hex.hpp"

int main() {
    try {
        std::string val1, val2;
        std::cout << "Введите первое шестнадцатеричное число: ";
        std::cin >> val1;
        std::cout << "Введите второе шестнадцатеричное число: ";
        std::cin >> val2;

        Hex hex1(val1);
        Hex hex2(val2);

        char op;
        std::cout << "Какую операцию вы хотите выполнить (+, -, <, >, ==): ";
        std::cin >> op;

        switch (op) {
            case '+':
                std::cout << "Результат сложения: " << (hex1 + hex2) << std::endl;
                break;

            case '-':
                std::cout << "Результат вычитания: " << (hex1 - hex2) << std::endl;
                break;

            case '>':
                if (hex1 > hex2) {
                    std::cout << "Первое число больше второго" << std::endl;
                } else {
                    std::cout << "Первое число не больше второго" << std::endl;
                }
                break;

            case '<':
                if (hex1 < hex2) {
                    std::cout << "Первое число меньше второго" << std::endl;
                } else {
                    std::cout << "Первое число не меньше второго" << std::endl;
                }
                break;

            case '=':
                if (hex1 == hex2) {
                    std::cout << "Оба числа равны" << std::endl;
                } else {
                    std::cout << "Числа не равны" << std::endl;
                }
                break;

            default:
                std::cout << "Недопустимая операция" << std::endl;
                break;
        }

    } catch (const std::invalid_argument& ex) {
        std::cout << "Поймано исключение недопустимого аргумента: " << ex.what() << std::endl;
    }
    
    return 0;
}
