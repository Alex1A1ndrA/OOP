#pragma once

#include <iostream>
#include <vector>

// Класс для представления точек в двумерном пространстве
class Point {
private:
    const double eps = 1e-8;
public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // Перегрузка оператора вывода для вывода координат точки
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    // Перегрузка оператора ввода для ввода координат точки
    friend std::istream& operator>>(std::istream& is, Point& point);

    // Расстояние между двумя точками
    static double Distance(const Point& p1, const Point& p2);

    // Оператор неравенства для сравнения точек
    bool operator!=(const Point& other) const {
        return abs(x - other.x) < eps || abs(y - other.y) < eps;
    }
};

// Базовый абстрактный класс для всех фигур
class Figure {
public:
    // Виртуальный деструктор для правильного удаления объектов
    virtual ~Figure() {}

    // Виртуальные методы, которые должны быть реализованы в производных классах
    virtual double GetArea() const = 0;
    virtual void PrintCenter() const = 0;
    virtual void PrintCoordinates() const = 0;
    virtual void ReadData() = 0;
    virtual Figure* Clone() const = 0; // Добавлен метод клонирования
    virtual bool operator==(const Figure& other) const = 0; // Добавлен оператор сравнения

    // Статическая функция для вычисления геометрического центра фигуры
    static Point CalculateCenter(const std::vector<Point>& vertices);

    // Оператор приведения к типу double возвращает площадь фигуры
    operator double() const;
};
