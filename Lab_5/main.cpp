#include <iostream>
#include <map>
#include "MyAllocator.h"
#include "MyStack.h"

int main() {
    // создание экземпляра std::map с вашим аллокатором
    std::map<int, int, MyAllocator<std::pair<const int, int>, 10>> myMapAllocator;

    // заполнение 10 элементами, где ключ — это число от 0 до 9, а значение - факториал ключа
    for (int i = 0; i < 10; ++i) {
        int factorial = 1;
        for (int j = 1; j <= i; ++j) {
            factorial *= j;
        }
        myMapAllocator[i] = factorial;
    }

    // вывод на экран всех значений (ключ и значение разделены пробелом)
    std::cout << "std::map with custom allocator:" << std::endl;
    for (const auto& pair : myMapAllocator) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    // создание экземпляра своего контейнера для хранения int с собственным аллокатором
    MyStack<int, MyAllocator<int, 10>> myStackAllocator;

    // заполнение контейнера и печать его элементов
    for (int i = 0; i < 10; ++i) {
        myStackAllocator.push(i);
    }

    // вывод на экран всех значений в стеке
    std::cout << "\nMyStack with custom allocator:" << std::endl;
    while (!myStackAllocator.empty()) {
        std::cout << myStackAllocator.top() << " ";
        myStackAllocator.pop();
    }

    return 0;
}
