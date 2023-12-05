#pragma once

#include <cstdlib>
#include <new>

template <typename T, std::size_t ChunkSize = 10>
class MyAllocator {
public:
    using value_type = T;

    MyAllocator() noexcept;
    ~MyAllocator() noexcept;

    T* allocate(std::size_t n);
    void deallocate(T* p, std::size_t n) noexcept;

    // Добавим следующее, чтобы удовлетворить требованиям аллокатора
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    // Конструктор копирования
    template <typename U>
    MyAllocator(const MyAllocator<U, ChunkSize>&) noexcept {}

    template <class U>
    struct rebind {
        using other = MyAllocator<U, ChunkSize>;
    };
};

template <typename T, std::size_t ChunkSize>
MyAllocator<T, ChunkSize>::MyAllocator() noexcept {}

template <typename T, std::size_t ChunkSize>
MyAllocator<T, ChunkSize>::~MyAllocator() noexcept {}

template <typename T, std::size_t ChunkSize>
T* MyAllocator<T, ChunkSize>::allocate(std::size_t n) {
    return static_cast<T*>(std::malloc(n * sizeof(T)));
}

template <typename T, std::size_t ChunkSize>
void MyAllocator<T, ChunkSize>::deallocate(T* p, std::size_t /*n*/) noexcept {
    std::free(p);
}

template <typename T, std::size_t ChunkSize>
bool operator==(const MyAllocator<T, ChunkSize>&, const MyAllocator<T, ChunkSize>&) noexcept {
    return true;
}

template <typename T, std::size_t ChunkSize>
bool operator!=(const MyAllocator<T, ChunkSize>&, const MyAllocator<T, ChunkSize>&) noexcept {
    return false;
}
