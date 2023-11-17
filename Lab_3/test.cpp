#include <gtest/gtest.h>
#include "Figure.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"

TEST(FigureTests, SquareArea) {
    Square square;
    square.ReadData();
    ASSERT_EQ(square.GetArea(), static_cast<double>(square));
}

TEST(FigureTests, RectangleArea) {
    Rectangle rectangle;
    rectangle.ReadData();
    ASSERT_EQ(rectangle.GetArea(), static_cast<double>(rectangle));
}

TEST(FigureTests, TrapezoidArea) {
    Trapezoid trapezoid;
    trapezoid.ReadData();
    ASSERT_EQ(trapezoid.GetArea(), static_cast<double>(trapezoid));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
