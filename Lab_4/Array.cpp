#include "Array.h"

template <class T>
Array<T>::Array() : size_(0), capacity_(0), data_(nullptr) {}

template <class T>
Array<T>::Array(size_t size) : size_(0), capacity_(size), data_(std::make_shared<std::shared_ptr<Figure<T>>[]>(new std::shared_ptr<Figure<T>>[size])) {}

template <class T>
Array<T>::Array(const Array<T>& other) : size_(other.size_), capacity_(other.size_), data_(std::make_shared<std::shared_ptr<Figure<T>>[]>(new std::shared_ptr<Figure<T>>[other.size_])) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <class T>
Array<T>::Array(Array<T>&& other) noexcept : size_(other.size_), capacity_(other.capacity_), data_(std::move(other.data_)) {
    other.size_ = 0;
    other.capacity_ = 0;
}

template <class T>
Array<T>::~Array() = default;

template <class T>
void Array<T>::Add(const std::shared_ptr<Figure<T>>& item) {
    if (size_ == capacity_) {
        // Реализация увеличения размера массива, если необходимо
    }
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
        capacity_ = other.size_;
        data_ = std::make_shared<std::shared_ptr<Figure<T>>[]>(new std::shared_ptr<Figure<T>>[other.size_]);
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template <class T>
Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
    if (this != &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = std::move(other.data_);
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

// Эксплицитная инстанциация шаблона для типа double
template class Array<double>;
