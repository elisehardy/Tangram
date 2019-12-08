#include <cmath>
#include <utility>

#include <MLV/MLV_shape.h>

#include "../include/Triangle.hpp"


using namespace tangram::geometry;

const uint16_t Triangle::HYPOTENUSE = sqrt(SIDE * SIDE * 2);


Triangle::Triangle(const Point &offset) :
        p1(offset), p2(offset + Vector(SIDE, 0)), p3(offset + Vector(0, SIDE)) {
}


Triangle::Triangle(Point t_p1, Point t_p2, Point t_p3) :
        p1(std::move(t_p1)), p2(std::move(t_p2)), p3(std::move(t_p3)) {
}


Triangle Triangle::translate(const Vector &v) const {
    return Triangle(
            this->p1.translate(v),
            this->p2.translate(v),
            this->p3.translate(v)
    );
}


Triangle Triangle::rotate(int16_t angle, const Point &center) const {
    return Triangle(
            this->p1.rotate(angle, center),
            this->p2.rotate(angle, center),
            this->p3.rotate(angle, center)
    );
}


Triangle Triangle::rotate(int16_t angle) const {
    return this->rotate(angle, Point::center({this->p1, this->p2, this->p3}));
}


bool Triangle::contains(const Point &p) const {
    Vector Vab = this->p1 - this->p2;
    Vector Vbc = this->p2 - this->p3;
    Vector Vca = this->p3 - this->p1;
    
    Vector Vax = p1 - p;
    Vector Vbx = p2 - p;
    Vector Vcx = p3 - p;
    
    int crossA = Vab ^Vax;
    int crossB = Vbc ^Vbx;
    int crossC = Vca ^Vcx;
    
    return (crossA >= 0 && crossB >= 0 && crossC >= 0) || (crossA < 0 && crossB < 0 && crossC < 0);
}


std::vector<Point> Triangle::getPoints() const {
    return {Point(p1), Point(p2), Point(p3)};
}


void Triangle::draw(MLV_Color color) const {
    int X[3] = {this->p1.first, this->p2.first, this->p3.first};
    int Y[3] = {this->p1.second, this->p2.second, this->p3.second};
    MLV_draw_filled_polygon(X, Y, 3, color);
}


