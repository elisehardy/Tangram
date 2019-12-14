#include <cmath>
#include <utility>

#include <MLV/MLV_shape.h>

#include "../include/Triangle.hpp"


using namespace tangram::geometry;

const uint16_t Triangle::HYPOTENUSE = static_cast<uint16_t>(sqrt(SIDE * SIDE * 2));
const uint16_t Triangle::HEIGHT = static_cast<uint16_t>(Triangle::HYPOTENUSE / 2);


Triangle::Triangle(const Point16 &offset) :
    p1(offset), p2(offset), p3(offset){}


Triangle::Triangle(Point16 t_p1, Point16 t_p2, Point16 t_p3):
        p1(t_p1), p2(t_p2), p3(t_p3) {}


Triangle Triangle::translate(const Vector16 &v) const {
    return Triangle({0,0});
}


Triangle Triangle::translate(int16_t x, int16_t y) const {
    return Triangle({0,0});
}


Triangle Triangle::rotate(int16_t angle, const PointD &center) const {
    return Triangle({0,0});
}


bool Triangle::contains(const Point16 &p) const {
    return false;
}


std::vector<Point16> Triangle::getPoints() const {
    return std::vector<Point16>();
}


void Triangle::draw(MLV_Color color) const {}


