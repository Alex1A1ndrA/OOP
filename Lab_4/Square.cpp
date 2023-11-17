#include "Square.h"

template <class T>
Square<T>::Square() {
    a = {0, 0};
    b = {0, 0};
    c = {0, 0};
    d = {0, 0};
}

template <class T>
std::pair<T, T> Square<T>::GetCenter() const {
    return {(a.first + c.first) / 2, (a.second + c.second) / 2};
}

template <class T>
void Square<T>::Print(std::ostream& os) const {
    os << "Square: " << a << " " << b << " " << c << " " << d << std::endl;
}

template <class T>
double Square<T>::Area() const {
    return std::abs((a.first - c.first) * (a.second - c.second));
}

// Эксплицитная инстанциация шаблона для типа double
template class Square<double>;
