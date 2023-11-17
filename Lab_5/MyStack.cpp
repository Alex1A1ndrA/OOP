#include "MyStack.h"

template <typename T, typename Alloc>
MyStack<T, Alloc>::MyStack() : data(allocator.allocate(10)), capacity(10), size_(0) {}

template <typename T, typename Alloc>
MyStack<T, Alloc>::~MyStack() {
    allocator.deallocate(data, capacity);
}

template <typename T, typename Alloc>
void MyStack<T, Alloc>::push(const T& value) {
    // Проверка, достигнут ли текущий размер стека предела capacity
    if (size_ == capacity) {
        resize(); // Увеличение размера стека при необходимости
    }

    data[size_++] = value; // Добавление элемента в стек и инкремент размера
}

template <typename T, typename Alloc>
void MyStack<T, Alloc>::pop() {
    if (size_ > 0) {
        --size_; // Уменьшение размера стека при извлечении элемента
    }
}

template <typename T, typename Alloc>
T& MyStack<T, Alloc>::top() {
    if (size_ > 0) {
        return data[size_ - 1]; // Возвращение верхнего элемента стека
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

template <typename T, typename Alloc>
bool MyStack<T, Alloc>::empty() const {
    return size_ == 0; // Проверка, пуст ли стек
}

template <typename T, typename Alloc>
size_t MyStack<T, Alloc>::size() const {
    return size_; // Возвращение текущего размера стека
}

template <typename T, typename Alloc>
typename MyStack<T, Alloc>::iterator MyStack<T, Alloc>::begin() {
    return iterator(data); // Возвращение итератора на начало стека
}

template <typename T, typename Alloc>
typename MyStack<T, Alloc>::iterator MyStack<T, Alloc>::end() {
    return iterator(data + size_); // Возвращение итератора на конец стека
}

template <typename T, typename Alloc>
typename MyStack<T, Alloc>::const_iterator MyStack<T, Alloc>::cbegin() const {
    return const_iterator(data); // Возвращение константного итератора на начало стека
}

template <typename T, typename Alloc>
typename MyStack<T, Alloc>::const_iterator MyStack<T, Alloc>::cend() const {
    return const_iterator(data + size_); // Возвращение константного итератора на конец стека
}

template <typename T, typename Alloc>
void MyStack<T, Alloc>::resize() {
    size_t newCapacity = capacity * 2; // Увеличение вдвое текущей capacity
    T* newData = allocator.allocate(newCapacity); // Выделение новой памяти

    // Копирование старых элементов в новую память
    for (size_t i = 0; i < size_; ++i) {
        newData[i] = data[i];
    }

    allocator.deallocate(data, capacity); // Освобождение старой памяти

    data = newData; // Переназначение указателя на новую память
    capacity = newCapacity; // Обновление capacity
}
