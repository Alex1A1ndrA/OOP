#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <utility>

template <class T>
class Trapezoid : public Figure<T> {
public:
    using vertex_t = std::pair<T, T>;
    vertex_t a, b, c, d;

    Trapezoid();
    std::pair<T, T> GetCenter() const override;
    void Print(std::ostream& os) const override;
    double Area() const override;
};

#endif
