#include "../include/Point.hpp"


using namespace Shape;


static double radians(double deg) {
    return (deg * M_PI) / 180.0;
}


namespace Shape {
    std::ostream &operator<<(std::ostream &os, const Point &p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
}


Point Point::operator+(const Point &other) const {
    return {this->first + other.first, this->second + other.second};
}


Point Point::rotate(uint8_t angle, Point center) const {
    double angle_rad = radians(angle);
    
    uint16_t x = this->first, y = this->second;
    Vector p = Vector(x - center.first, y - center.second);
    
    return {
            p.first * cos(angle_rad) - p.second * sin(angle_rad) + center.first,
            p.first * sin(angle_rad) + p.second * cos(angle_rad) + center.second
    };
}


Vector Point::getVector(const Point &p2) const {
    return {p2.first - this->first, p2.second - this->second};
}


Point Point::center(const std::vector<Point> &points) {
    int size = points.size();
    double x = 0, y = 0;
    
    for (Point p: points) {
        x += p.first;
        y += p.second;
    }
    
    return Point(x / size, y / size);
}
