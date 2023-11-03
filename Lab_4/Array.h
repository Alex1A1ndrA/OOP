#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <stdexcept>
#include "Figure.h"

template <class T>
class Array {
public:
    Array();
    Array(size_t size);
    Array(const Array<T>& other);
    Array(Array<T>&& other) noexcept;
    ~Array();

    void Add(const std::shared_ptr<Figure<T>>& item);
    void Remove(size_t index);
    size_t Size() const;
    std::shared_ptr<Figure<T>> operator[](size_t index);
    const std::shared_ptr<Figure<T>> operator[](size_t index) const;
    Array<T>& operator=(const Array<T>& other);
    Array<T>& operator=(Array<T>&& other) noexcept;

private:
    size_t size_;
    size_t capacity_;
    std::unique_ptr<std::shared_ptr<Figure<T>>[]> data_;
};

#include "Array.cpp"

#endif
