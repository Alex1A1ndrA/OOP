#pragma once

#include <deque>
#include "MyAllocator.hpp"

template <typename T, typename Allocator = std::allocator<T>>
class MyStack {
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = T&;
    using const_reference = const T&;

    MyStack(const Allocator& alloc = Allocator());
    ~MyStack() = default;

    bool empty() const noexcept;
    size_type size() const noexcept;

    void push(const value_type& value);
    void pop();
    reference top();
    const_reference top() const;

private:
    std::deque<T, MyAllocator<T>> data;
};
