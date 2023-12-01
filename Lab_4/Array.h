#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <stdexcept>
#include <vector>
#include "Figure.h"

template <class T>
class Array {
public:
    Array();
    explicit Array(size_t capacity);
    virtual ~Array();

    void Add(std::shared_ptr<Figure<T>> item);
    void Remove(size_t index);
    size_t Size() const;
    std::shared_ptr<Figure<T>> operator[](size_t index);
    const std::shared_ptr<Figure<T>> operator[](size_t index) const;
    Array<T>& operator=(const Array<T>& other);
    Array<T>& operator=(Array<T>&& other) noexcept;

private:
    size_t size_;
    std::vector<std::shared_ptr<Figure<T>>> data_;
};

#endif
