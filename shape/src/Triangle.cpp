#include <vector>

#include "../include/Triangle.hpp"


using namespace tangram::shape;


Triangle::Triangle(const Point &offset, MLV_Color color) :
        Shape(color) {
    this->p1 = offset;
    this->p2 = offset + Vector(Shape::SIDE, 0);
    this->p3 = offset + Vector(0, Shape::SIDE);
}


Triangle::Triangle(const Point &t_p1, const Point &t_p2, const Point &t_p3, MLV_Color color) :
        Shape(color) {
    this->p1 = t_p1;
    this->p2 = t_p2;
    this->p3 = t_p3;
}


auto Triangle::contains(uint16_t x, uint16_t y) const -> bool {
    Point p = {x, y};
    
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


std::vector<Point> Triangle::getPoints() {
    return {p1, p2, p3};
}
