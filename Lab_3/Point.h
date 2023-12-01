#pragma once

#include <iostream>

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Перегрузка оператора вывода для вывода координат точки
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    // Перегрузка оператора ввода для ввода координат точки
    friend std::istream& operator>>(std::istream& is, Point& point);
    
    // Расстояние между двумя точками
    static double Distance(const Point& p1, const Point& p2);

    // Оператор равенства для сравнения точек
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // Оператор неравенства для сравнения точек
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};
