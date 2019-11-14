#include "Point.hpp"

using namespace Tangram::Shape;

Point Point::operator+(const Point &other) const {
    return {this->fist + other->first, this->second + other->second};
}


Point Point::rotate(uint8_t angle) const {
    return {x * cos(angle) + y * sin(angle), -x * sin(angle) + y * cos(angle)}
}
