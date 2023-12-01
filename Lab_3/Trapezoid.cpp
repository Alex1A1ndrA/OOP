#include "Trapezoid.h"

Trapezoid::Trapezoid() : vertices(4) {}

double Trapezoid::GetArea() const {
    double topBaseLength = Point::Distance(vertices[0], vertices[1]);
    double bottomBaseLength = Point::Distance(vertices[2], vertices[3]);
    double height = Point::Distance(vertices[1], vertices[2]);
    return (topBaseLength + bottomBaseLength) * height / 2;
}

void Trapezoid::PrintCenter() const {
    std::cout << "Трапеция: Центр - " << Figure::CalculateCenter(vertices) << std::endl;
}

void Trapezoid::PrintCoordinates() const {
    std::cout << "Координаты вершин: ";
    for (const auto& vertex : vertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}

void Trapezoid::ReadData() {
    std::cout << "Введите координаты вершин трапеции:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Вершина " << i + 1 << ": ";
        std::cin >> vertices[i];
    }
}

Trapezoid* Trapezoid::Clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::operator==(const Figure& other) const {
    const Trapezoid* otherTrapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (otherTrapezoid == nullptr) {
        return false;
    }

    for (int i = 0; i < 4; ++i) {
        if (vertices[i] != otherTrapezoid->vertices[i]) {
            return false;
        }
    }

    return true;
}

