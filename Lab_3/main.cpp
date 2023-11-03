#include <iostream>
#include <vector>
#include "Figure.h"

int main() {
    std::vector<Figure*> figures;

    while (true) {
        std::cout << "Select a figure to create (1 - Square, 2 - Rectangle, 3 - Trapezoid, 0 - Exit): ";
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
                std::cout << "Invalid choice." << std::endl;
                continue;
        }

        figure->ReadData();
        figures.push_back(figure);
    }

    for (const auto& figure : figures) {
        figure->PrintCenter();
        figure->PrintCoordinates();
        std::cout << "Area: " << figure->GetArea() << std::endl;
    }

    // Calculate the total area
    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += figure->GetArea();
    }
    std::cout << "Total Area: " << totalArea << std::endl;

    // Clean up
    for (const auto& figure : figures) {
        delete figure;
    }

    return 0;
}
