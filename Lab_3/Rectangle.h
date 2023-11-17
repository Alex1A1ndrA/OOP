#pragma once

#include "Figure.h"

class Rectangle : public Figure {
private:
    std::vector<Point> vertices;

public:
    Rectangle();
    double GetArea() const override;
    void PrintCenter() const override;
    void PrintCoordinates() const override;
    void ReadData() override;
    Rectangle* Clone() const override;
    bool operator==(const Figure& other) const override;
};

