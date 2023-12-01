#include "Array.h"

template <class T>
Array<T>::Array() : size_(0) {}

template <class T>
Array<T>::Array(size_t capacity) : size_(0), data_(capacity) {}

template <class T>
Array<T>::~Array() {
    
}

template <class T>
void Array<T>::Add(std::shared_ptr<Figure<T>> item) {
    data_[size_] = item;
    size_++;
}

template <class T>
void Array<T>::Remove(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }

    for (size_t i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }

    size_--;
}

template <class T>
size_t Array<T>::Size() const {
    return size_;
}

template <class T>
std::shared_ptr<Figure<T>> Array<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <class T>
const std::shared_ptr<Figure<T>> Array<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        size_ = other.size_;
        data_ = other.data_;
    }
    return *this;
}

template <class T>
Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
    if (this != &other) {
        size_ = other.size_;
        data_ = std::move(other.data_);
        other.size_ = 0;
    }
    return *this;
}

// Эксплицитная инстанциация шаблона для типа double
template class Array<double>;
