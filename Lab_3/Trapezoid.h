#pragma once

#include "Figure.h"

class Trapezoid : public Figure {
private:
    std::vector<Point> vertices;

public:
    Trapezoid();
    double GetArea() const override;
    void PrintCenter() const override;
    void PrintCoordinates() const override;
    void ReadData() override;
    Trapezoid* Clone() const override;
    bool operator==(const Figure& other) const override;
};

