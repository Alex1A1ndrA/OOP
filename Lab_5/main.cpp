#include "MyStack.hpp"
#include <iostream>

int main() {
    MyStack<int, MyAllocator<int>> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }

    return 0;
}
