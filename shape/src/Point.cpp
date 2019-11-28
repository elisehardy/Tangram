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


Vector Point::operator-(const Point &other) const {
    return {this->first - other.first, this->second - other.second};
}


bool Point::operator==(const Point &other) const {
    return (std::abs(this->first - other.first) < NEAR_THRESHOLD
            && std::abs(this->second - other.second) < NEAR_THRESHOLD);
}


Point Point::rotate(uint8_t angle, const Point &center) const {
    double rad = radians(angle);
    uint16_t x = this->first, y = this->second;
    Vector p = Vector(x - center.first, y - center.second);
    
    return {
            p.first * cos(rad) - p.second * sin(rad) + center.first,
            p.first * sin(rad) + p.second * cos(rad) + center.second
    };
}


Point Point::translate(const Vector &translation) const {
    return {
            this->first + translation.first,
            this->second + translation.second
    };
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
