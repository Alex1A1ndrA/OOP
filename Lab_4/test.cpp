#include <gtest/gtest.h>
#include <memory>
#include "Array.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"

TEST(ShapeTests, AreaCalculation) {
    Array<double> figures;

    Square<double> square;
    square.a = {0, 0};
    square.b = {0, 2};
    square.c = {2, 2};
    square.d = {2, 0};
    figures.Add(std::make_shared<Square<double>>(square));

    Rectangle<double> rectangle;
    rectangle.a = {0, 0};
    rectangle.b = {0, 4};
    rectangle.c = {6, 4};
    rectangle.d = {6, 0};
    figures.Add(std::make_shared<Rectangle<double>>(rectangle));

    Trapezoid<double> trapezoid;
    trapezoid.a = {0, 0};
    trapezoid.b = {2, 4};
    trapezoid.c = {8, 4};
    trapezoid.d = {10, 0};
    figures.Add(std::make_shared<Trapezoid<double>>(trapezoid));

    ASSERT_DOUBLE_EQ(4.0, figures[0]->Area());
    ASSERT_DOUBLE_EQ(24.0, figures[1]->Area());
    ASSERT_DOUBLE_EQ(32.0, figures[2]->Area());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
