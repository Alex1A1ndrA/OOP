#include "gtest/gtest.h"
#include "Figure.h"

// Тесты для Square
TEST(SquareTest, AreaCalculation) {
    Square square;
    square.ReadData(); // Введите данные для квадрата
    double expectedArea = square.GetArea();
    ASSERT_GE(expectedArea, 0.0); // Проверка, что площадь неотрицательная
}

// Тесты для Rectangle
TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle;
    rectangle.ReadData(); // Введите данные для прямоугольника
    double expectedArea = rectangle.GetArea();
    ASSERT_GE(expectedArea, 0.0); // Проверка, что площадь неотрицательная
}

// Тесты для Trapezoid
TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trapezoid;
    trapezoid.ReadData(); // Введите данные для трапеции
    double expectedArea = trapezoid.GetArea();
    ASSERT_GE(expectedArea, 0.0); // Проверка, что площадь неотрицательная
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
