#include "MyStack.hpp"

// Явная инстанциация для int и MyAllocator<int, 10>
template class MyStack<int, MyAllocator<int, 10>>;

template <typename T, typename Allocator>
MyStack<T, Allocator>::MyStack(const Allocator& alloc) : data(alloc) {}

template <typename T, typename Allocator>
bool MyStack<T, Allocator>::empty() const noexcept {
    return data.empty();
}

template <typename T, typename Allocator>
typename MyStack<T, Allocator>::size_type MyStack<T, Allocator>::size() const noexcept {
    return data.size();
}

template <typename T, typename Allocator>
void MyStack<T, Allocator>::push(const value_type& value) {
    data.push_back(value);
}

template <typename T, typename Allocator>
void MyStack<T, Allocator>::pop() {
    if (!empty()) {
        data.pop_back();
    }
}

template <typename T, typename Allocator>
typename MyStack<T, Allocator>::reference MyStack<T, Allocator>::top() {
    return data.back();
}

template <typename T, typename Allocator>
typename MyStack<T, Allocator>::const_reference MyStack<T, Allocator>::top() const {
    return data.back();
}
