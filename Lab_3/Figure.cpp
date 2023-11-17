#include "Figure.h"

Point Figure::CalculateCenter(const std::vector<Point>& vertices) {
    double centerX = 0, centerY = 0;
    for (const auto& vertex : vertices) {
        centerX += vertex.x;
        centerY += vertex.y;
    }
    return Point(centerX / vertices.size(), centerY / vertices.size());
}

//std::ostream& operator<<(std::ostream& os, const Point& point) {
//    os << "(" << point.x << ", " << point.y << ")";
//    return os;
//}

//std::istream& operator>>(std::istream& is, Point& point) {
//    is >> point.x >> point.y;
//    return is;
//}

bool operator!=(const Point& p1, const Point& p2) {
    return p1.x != p2.x || p1.y != p2.y;
}

bool operator==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool Figure::operator==(const Figure& other) const {
    return GetArea() == other.GetArea();
}

Figure::operator double() const {
    return GetArea();
}
