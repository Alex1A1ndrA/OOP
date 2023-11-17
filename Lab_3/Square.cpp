#include "Square.h"

Square::Square() : vertices(4) {}

double Square::GetArea() const {
    double sideLength = Point::Distance(vertices[0], vertices[1]);
    return sideLength * sideLength;
}

void Square::PrintCenter() const {
    std::cout << "Квадрат: Центр - " << Figure::CalculateCenter(vertices) << std::endl;
}

void Square::PrintCoordinates() const {
    std::cout << "Координаты вершин: ";
    for (const auto& vertex : vertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}

void Square::ReadData() {
    std::cout << "Введите координаты вершин квадрата:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Вершина " << i + 1 << ": ";
        std::cin >> vertices[i];
    }
}

Square* Square::Clone() const {
    return new Square(*this);
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (otherSquare == nullptr) {
        return false;
    }

    for (int i = 0; i < 4; ++i) {
        if (vertices[i] != otherSquare->vertices[i]) {
            return false;
        }
    }

    return true;
}

