#include <cmath>
#include <utility>

#include <MLV/MLV_shape.h>

#include "../include/Triangle.hpp"


using namespace tangram::geometry;

const int16_t Triangle::HYPOTENUSE = static_cast<int16_t>(sqrt(SIDE * SIDE * 2));
const int16_t Triangle::HEIGHT = static_cast<int16_t>(Triangle::HYPOTENUSE / 2);


Triangle::Triangle(const Point16 &offset) :
        p1(offset), p2(offset), p3(offset) {
    this->p1 = offset;
    this->p2 = offset + Vector16(SIDE, 0);
    this->p3 = offset + Vector16(0, SIDE);
}


Triangle::Triangle(Point16 t_p1, Point16 t_p2, Point16 t_p3) :
        p1(t_p1), p2(t_p2), p3(t_p3) {
}


Triangle Triangle::translate(const Vector16 &v) const {
    return Triangle(
            this->p1.translate(v),
            this->p2.translate(v),
            this->p3.translate(v)
    );
}


Triangle Triangle::translate(int16_t x, int16_t y) const {
    return this->translate({x, y});
}


Triangle Triangle::rotate(int16_t angle, const PointD &center) const {
    return Triangle(
            this->p1.rotate(angle, center),
            this->p2.rotate(angle, center),
            this->p3.rotate(angle, center)
    );
}


bool Triangle::contains(const Point16 &p) const {
    Vector16 Vab = this->p1 - this->p2;
    Vector16 Vbc = this->p2 - this->p3;
    Vector16 Vca = this->p3 - this->p1;
    
    Vector16 Vax = p1 - p;
    Vector16 Vbx = p2 - p;
    Vector16 Vcx = p3 - p;
    
    int crossA = Vab ^Vax;
    int crossB = Vbc ^Vbx;
    int crossC = Vca ^Vcx;
    
    return (crossA >= 0 && crossB >= 0 && crossC >= 0) || (crossA < 0 && crossB < 0 && crossC < 0);
}


std::vector<Point16> Triangle::getPoints() const {
    return {Point16(p1), Point16(p2), Point16(p3)};
}


void Triangle::draw(MLV_Color color) const {
    int X[3] = {this->p1.x, this->p2.x, this->p3.x};
    int Y[3] = {this->p1.y, this->p2.y, this->p3.y};
    MLV_draw_filled_polygon(X, Y, 3, color);
}


