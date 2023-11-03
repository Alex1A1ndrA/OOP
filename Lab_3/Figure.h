#pragma once

#include <iostream>

class Figure {
public:
    virtual double GetArea() const = 0;
    virtual void PrintCenter() const = 0;
    virtual void PrintCoordinates() const = 0;
    virtual void ReadData() = 0;
};

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Square : public Figure {
private:
    Point center;
    double side;

public:
    Square();
    double GetArea() const override;
    void PrintCenter() const override;
    void PrintCoordinates() const override;
    void ReadData() override;
};

class Rectangle : public Figure {
private:
    Point center;
    double width, height;

public:
    Rectangle();
    double GetArea() const override;
    void PrintCenter() const override;
    void PrintCoordinates() const override;
    void ReadData() override;
};

class Trapezoid : public Figure {
private:
    Point center;
    double topBase, bottomBase, height;

public:
    Trapezoid();
    double GetArea() const override;
    void PrintCenter() const override;
    void PrintCoordinates() const override;
    void ReadData() override;
};
