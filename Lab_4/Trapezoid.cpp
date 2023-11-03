#include "Trapezoid.h"

template <class T>
Trapezoid<T>::Trapezoid() {
    a = {0, 0};
    b = {0, 0};
    c = {0, 0};
    d = {0, 0};
}

template <class T>
std::pair<T, T> Trapezoid<T>::GetCenter() const {
    return {(a.first + b.first + c.first + d.first) / 4, (a.second + b.second + c.second + d.second) / 4};
}

template <class T>
void Trapezoid<T>::Print(std::ostream& os) const {
    os << "Trapezoid: " << a << " " << b << " " << c << " " << d << std::endl;
}

template <class T>
double Trapezoid<T>::Area() const {
    // Вычисление площади трапеции
    T base1 = std::abs(b.first - a.first);
    T base2 = std::abs(d.first - c.first);
    T height = std::abs(a.second - d.second);
    return 0.5 * (base1 + base2) * height;
}

// Эксплицитная инстанциация шаблона для типа double
template class Trapezoid<double>;
