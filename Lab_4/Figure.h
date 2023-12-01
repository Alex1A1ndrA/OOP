#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>

template <class T>
struct Figure {
    virtual std::pair<T, T> GetCenter() const = 0;
    virtual void Print(std::ostream& os) const = 0;
    virtual double Area() const = 0;
    virtual ~Figure() = default;
};

#endif