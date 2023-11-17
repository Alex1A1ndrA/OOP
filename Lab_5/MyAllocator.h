#pragma once

#include <cstddef>

template <typename T, size_t N>
class MyAllocator {
public:
    using value_type = T;

    MyAllocator();  // Конструктор аллокатора
    ~MyAllocator(); // Деструктор аллокатора

    T* allocate(size_t n);    // Выделение памяти для n элементов типа T
    void deallocate(T* p, size_t n); // Освобождение памяти (не используется в данной реализации)

private:
    T* memoryPool;  // Указатель на начало выделенной памяти
    size_t allocatedBlocks; // Количество выделенных блоков
};

#include "MyAllocator.cpp"  // Включаем реализацию из отдельного файла
