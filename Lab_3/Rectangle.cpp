#include "Rectangle.h"

Rectangle::Rectangle() : vertices(4) {}

double Rectangle::GetArea() const {
    double length = Point::Distance(vertices[0], vertices[1]);
    double width = Point::Distance(vertices[1], vertices[2]);
    return length * width;
}

void Rectangle::PrintCenter() const {
    std::cout << "Прямоугольник: Центр - " << Figure::CalculateCenter(vertices) << std::endl;
}

void Rectangle::PrintCoordinates() const {
    std::cout << "Координаты вершин: ";
    for (const auto& vertex : vertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}

void Rectangle::ReadData() {
    std::cout << "Введите координаты вершин прямоугольника:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Вершина " << i + 1 << ": ";
        std::cin >> vertices[i];
    }
}

Rectangle* Rectangle::Clone() const {
    return new Rectangle(*this);
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
    if (otherRectangle == nullptr) {
        return false;
    }

    for (int i = 0; i < 4; ++i) {
        if (vertices[i] != otherRectangle->vertices[i]) {
            return false;
        }
    }

    return true;
}

