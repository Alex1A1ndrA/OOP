#include "MyAllocator.h"

template <typename T, size_t N>
MyAllocator<T, N>::MyAllocator() : memoryPool(new T[N]), allocatedBlocks(0) {}

template <typename T, size_t N>
MyAllocator<T, N>::~MyAllocator() {
    delete[] memoryPool;
}

template <typename T, size_t N>
T* MyAllocator<T, N>::allocate(size_t n) {
    // Выделение блока памяти размером n элементов типа T
    if (allocatedBlocks + n > N) {
        throw std::bad_alloc(); // Бросаем исключение, если невозможно выделить достаточно памяти
    }

    T* allocatedMemory = memoryPool + allocatedBlocks; // Указатель на начало выделенной памяти
    allocatedBlocks += n; // Обновляем количество выделенных блоков
    return allocatedMemory; // Возвращаем указатель на выделенную память
}

template <typename T, size_t N>
void MyAllocator<T, N>::deallocate(T* p, size_t n) {
    // Не предполагается освобождение конкретного элемента
    // Аллокатор должен освобождать всю память самостоятельно
    allocatedBlocks = 0;
}

// Явная инстанциация для предотвращения ошибок компиляции при использовании шаблона в разных файлах
template class MyAllocator<int, 10>;
