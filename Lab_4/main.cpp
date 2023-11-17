#include <iostream>
#include <memory>
#include "Array.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"

int main() {
    // Создаем динамический массив умных указателей на фигуры
    Array<double> figures;

    // Пример ввода и добавления квадрата в массив фигур
    Square<double> square;
    square.a = {0, 0};
    square.b = {0, 2};
    square.c = {2, 2};
    square.d = {2, 0};
    figures.Add(std::make_shared<Square<double>>(square));
    std::cout << "Квадрат добавлен в массив." << std::endl;

    // Пример ввода и добавления прямоугольника
    Rectangle<double> rectangle;
    rectangle.a = {0, 0};
    rectangle.b = {0, 4};
    rectangle.c = {6, 4};
    rectangle.d = {6, 0};
    figures.Add(std::make_shared<Rectangle<double>>(rectangle));
    std::cout << "Прямоугольник добавлен в массив." << std::endl;

    // Пример ввода и добавления трапеции
    Trapezoid<double> trapezoid;
    trapezoid.a = {0, 0};
    trapezoid.b = {2, 4};
    trapezoid.c = {8, 4};
    trapezoid.d = {10, 0};
    figures.Add(std::make_shared<Trapezoid<double>>(trapezoid));
    std::cout << "Трапеция добавлена в массив." << std::endl;

    // Вывод информации о фигурах в массиве
    for (size_t i = 0; i < figures.Size(); ++i) {
        auto center = figures[i]->GetCenter();
        std::cout << "Геометрический центр: (" << center.first << ", " << center.second << ")" << std::endl;
        figures[i]->Print(std::cout);
        std::cout << "Площадь: " << figures[i]->Area() << std::endl << std::endl;
    }

    // Вычисление общей площади фигур
    double total_area = 0.0;
    for (size_t i = 0; i < figures.Size(); ++i) {
        total_area += figures[i]->Area();
    }
    std::cout << "Общая площадь фигур в массиве: " << total_area << std::endl;

    // Удаление фигуры по индексу (например, первой фигуры)
    size_t index_to_remove = 0;
    if (index_to_remove < figures.Size()) {
        figures.Remove(index_to_remove);
        std::cout << "Фигура с индексом " << index_to_remove << " удалена из массива." << std::endl;
    } else {
        std::cout << "Некорректный индекс для удаления." << std::endl;
    }

    return 0;
}
