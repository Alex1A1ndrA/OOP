#include "Rectangle.h"

template <class T>
Rectangle<T>::Rectangle() {
    a = {0, 0};
    b = {0, 0};
    c = {0, 0};
    d = {0, 0};
}

template <class T>
std::pair<T, T> Rectangle<T>::GetCenter() const {
    return {(a.first + c.first) / 2, (a.second + c.second) / 2};
}

template <class T>
void Rectangle<T>::Print(std::ostream& os) const {
    //os << "Rectangle: " << a << " " << b << " " << c << " " << d << std::endl;
}

template <class T>
double Rectangle<T>::Area() const {
    return std::abs((a.first - c.first) * (a.second - c.second));
}

// Эксплицитная инстанциация шаблона для типа double
template class Rectangle<double>;
