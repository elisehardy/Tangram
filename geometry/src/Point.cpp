#include <cmath>

#include "../include/Point.hpp"


using namespace tangram::geometry;


static double radians(double deg) {
    constexpr double r = M_PI / 180.0;
    return deg * r;
}


namespace tangram::geometry {
    std::ostream &operator<<(std::ostream &os, const Point &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
}


Point::Point(int16_t t_x, int16_t t_y) :
        x(t_x), y(t_y) {
}


Point Point::operator+(const Point &other) const {
    return Point(this->x + other.x, this->y + other.y);
}


Point Point::operator-(const Point &other) const {
    return Point(this->x - other.x, this->y - other.y);
}


int32_t Point::operator^(const Point &other) const {
    return (this->x * other.y) - (this->y * other.x);
}


bool Point::operator==(const Point &other) const {
    return (std::abs(this->x - other.x) < NEAR_THRESHOLD
            && std::abs(this->y - other.y) < NEAR_THRESHOLD);
}


Point Point::rotate(int16_t angle, const Point &center) const {
    double rad = radians(angle);
    double x = this->x - center.x;
    double y = this->y - center.y;
    
    return Point(
            static_cast<int16_t>(x * cos(rad) - y * sin(rad) + center.x),
            static_cast<int16_t>(x * sin(rad) + y * cos(rad) + center.y)
    );
}


Point Point::translate(const Vector &translation) const {
    return Point(
            this->x + translation.x,
            this->y + translation.y
    );
}


Point Point::translate(int16_t x, int16_t y) const {
    return Point(
            this->x + x,
            this->y + y
    );
}


Point Point::center(const std::vector<Point> &points) {
    int64_t size = points.size();
    int16_t x = 0, y = 0;
    
    for (Point p: points) {
        x += p.x;
        y += p.y;
    }
    
    return Point(x / size, y / size);
}
