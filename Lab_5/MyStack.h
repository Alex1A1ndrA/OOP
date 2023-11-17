#pragma once

#include <cstddef>
#include "MyAllocator.h"

template <typename T, typename Alloc = MyAllocator<T, 10>>
class MyStack {
public:
    using value_type = T;
    using allocator_type = Alloc;

    class iterator {
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using iterator_category = std::forward_iterator_tag;

        iterator(pointer ptr) : current(ptr) {}

        reference operator*() const {
            return *current;
        }

        iterator& operator++() {
            ++current;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++current;
            return temp;
        }

        bool operator==(const iterator& rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator& rhs) const {
            return current != rhs.current;
        }

    private:
        pointer current;
    };

    class const_iterator {
    public:
        using value_type = const T;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = std::forward_iterator_tag;

        const_iterator(pointer ptr) : current(ptr) {}

        reference operator*() const {
            return *current;
        }

        const_iterator& operator++() {
            ++current;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator temp = *this;
            ++current;
            return temp;
        }

        bool operator==(const const_iterator& rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator& rhs) const {
            return current != rhs.current;
        }

    private:
        pointer current;
    };

    MyStack();          // Конструктор стека
    ~MyStack();         // Деструктор стека

    void push(const T& value); // Добавление элемента в стек
    void pop();                // Извлечение элемента из стека
    T& top();                  // Получение верхнего элемента стека
    bool empty() const;        // Проверка, пуст ли стек
    size_t size() const;       // Получение текущего размера стека

    iterator begin();          // Получение итератора на начало стека
    iterator end();            // Получение итератора на конец стека
    const_iterator cbegin() const; // Получение константного итератора на начало стека
    const_iterator cend() const;   // Получение константного итератора на конец стека

private:
    T* data;             // Указатель на данные в стеке
    size_t capacity;     // Общая вместимость стека
    size_t size_;        // Текущий размер стека
    Alloc allocator;     // Аллокатор для управления памятью

    // Приватный метод для увеличения размера стека
    void resize();
};

#include "MyStack.cpp"  // Включаем реализацию из отдельного файла
