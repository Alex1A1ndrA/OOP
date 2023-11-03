#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"
#include <utility>

template <class T>
class Square : public Figure<T> {
public:
    using vertex_t = std::pair<T, T>;
    vertex_t a, b, c, d;

    Square();
    std::pair<T, T> GetCenter() const override;
    void Print(std::ostream& os) const override;
    double Area() const override;
};

#endif
