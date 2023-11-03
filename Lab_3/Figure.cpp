#include "Figure.h"

// Реализация методов класса Square
Square::Square() : center(0, 0), side(1) {}

double Square::GetArea() const {
    return side * side;
}

void Square::PrintCenter() const {
    std::cout << "Square Center: " << center.x << ", " << center.y << std::endl;
}

void Square::PrintCoordinates() const {
    std::cout << "Square Coordinates: ";
    std::cout << "(" << center.x - side / 2 << ", " << center.y - side / 2 << ") ";
    std::cout << "(" << center.x - side / 2 << ", " << center.y + side / 2 << ") ";
    std::cout << "(" << center.x + side / 2 << ", " << center.y + side / 2 << ") ";
    std::cout << "(" << center.x + side / 2 << ", " << center.y - side / 2 << ")" << std::endl;
}

void Square::ReadData() {
    std::cout << "Enter the coordinates of the center of the square: ";
    std::cin >> center.x >> center.y;
    std::cout << "Enter the side length of the square: ";
    std::cin >> side;
}

// Реализация методов класса Rectangle
Rectangle::Rectangle() : center(0, 0), width(1), height(1) {}

double Rectangle::GetArea() const {
    return width * height;
}

void Rectangle::PrintCenter() const {
    std::cout << "Rectangle Center: " << center.x << ", " << center.y << std::endl;
}

void Rectangle::PrintCoordinates() const {
    std::cout << "Rectangle Coordinates: ";
    std::cout << "(" << center.x - width / 2 << ", " << center.y - height / 2 << ") ";
    std::cout << "(" << center.x - width / 2 << ", " << center.y + height / 2 << ") ";
    std::cout << "(" << center.x + width / 2 << ", " << center.y + height / 2 << ") ";
    std::cout << "(" << center.x + width / 2 << ", " << center.y - height / 2 << ")" << std::endl;
}

void Rectangle::ReadData() {
    std::cout << "Enter the coordinates of the center of the rectangle: ";
    std::cin >> center.x >> center.y;
    std::cout << "Enter the width and height of the rectangle: ";
    std::cin >> width >> height;
}

// Реализация методов класса Trapezoid
Trapezoid::Trapezoid() : center(0, 0), topBase(1), bottomBase(2), height(1) {}

double Trapezoid::GetArea() const {
    return (topBase + bottomBase) * height / 2;
}

void Trapezoid::PrintCenter() const {
    std::cout << "Trapezoid Center: " << center.x << ", " << center.y << std::endl;
}

void Trapezoid::PrintCoordinates() const {
    double halfTop = topBase / 2;
    double halfBottom = bottomBase / 2;
    std::cout << "Trapezoid Coordinates: ";
    std::cout << "(" << center.x - halfBottom << ", " << center.y - height / 2 << ") ";
    std::cout << "(" << center.x - halfTop << ", " << center.y + height / 2 << ") ";
    std::cout << "(" << center.x + halfTop << ", " << center.y + height / 2 << ") ";
    std::cout << "(" << center.x + halfBottom << ", " << center.y - height / 2 << ")" << std::endl;
}

void Trapezoid::ReadData() {
    std::cout << "Enter the coordinates of the center of the trapezoid: ";
    std::cin >> center.x >> center.y;
    std::cout << "Enter the top base, bottom base, and height of the trapezoid: ";
    std::cin >> topBase >> bottomBase >> height;
}
