#include "../include/Point.hpp"

using namespace Tangram::Shape;

Point Point::operator+(const Point &other) const {
    return {this->first + other.first, this->second + other.second};
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

Point Point::rotate(uint8_t angle) const {
    uint16_t x = this->first, y = this->second;

    return {
        x * cos(angle) + y * sin(angle),
        -x * sin(angle) + y * cos(angle)
    };
}

Point Point::getVector(const Point &p2) const {
    return {p2.first - this->first, p2.second - this->second};
}


Point Point::dotProduct(const Point &v2) const {
    return {this->first*v2.first, this->second*v2.second};
}