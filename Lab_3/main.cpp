#include <iostream>
#include <vector>
#include "Figure.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"

int main() {
    std::vector<Figure*> figures;

    while (true) {
        std::cout << "Выберите фигуру для создания (1 - Квадрат, 2 - Прямоугольник, 3 - Трапеция, 0 - Выход): ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        Figure* figure = nullptr;
        switch (choice) {
            case 1:
                figure = new Square();
                break;
            case 2:
                figure = new Rectangle();
                break;
            case 3:
                figure = new Trapezoid();
                break;
            default:
                std::cout << "Неверный выбор." << std::endl;
                continue;
        }

        figure->ReadData();
        figures.push_back(figure);
    }

    for (const auto& figure : figures) {
        figure->PrintCenter();
        figure->PrintCoordinates();
        std::cout << "Площадь: " << static_cast<double>(*figure) << std::endl;
    }

    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "Общая площадь: " << totalArea << std::endl;

    // Очистка памяти
    for (const auto& figure : figures) {
        delete figure;
    }

    return 0;
}

