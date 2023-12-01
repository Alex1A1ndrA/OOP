#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include <utility>

template <class T>
class Rectangle : public Figure<T> {
public:
    using vertex_t = std::pair<T, T>;
    vertex_t a, b, c, d;

    Rectangle();
    std::pair<T, T> GetCenter() const override;
    void Print(std::ostream& os) const override;
    double Area() const override;
};

#endif
