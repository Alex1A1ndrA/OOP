#pragma once

#include "Figure.h"

class Square : public Figure {
private:
    std::vector<Point> vertices;

public:
    Square();
    double GetArea() const override;
    void PrintCenter() const override;
    void PrintCoordinates() const override;
    void ReadData() override;
    Square* Clone() const override;
    bool operator==(const Figure& other) const override;
};

