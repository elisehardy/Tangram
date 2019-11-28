#include "../include/Triangle.hpp"


using namespace Shape;


Triangle::Triangle(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color) :
        Polygon(x, y, angle, size, color) {
    this->init();
}


Triangle::Triangle(Point center, uint8_t angle, Size size, MLV_Color color) :
        Polygon(center, angle, size, color) {
    this->init();
}


Triangle::~Triangle() {
}


void Triangle::init() {
    this->update();
}


void Triangle::update() {
    uint8_t angle = this->getAngle();
    Point center = this->getCenter();
    Size size = this->getSize();
    Point ul = {-size, -size}, ur = {size, -size}, bl = {-size, size};
    this->p1 = (center + ur).rotate(angle);
    this->p2 = (center + ul).rotate(angle);
    this->p3 = (center + bl).rotate(angle);
}


std::vector <Point> Triangle::getPoints() const {
    return {this->p1, this->p2, this->p3};
}


int crossProductAG(Point v1, Point v2) {
    // a ^ b  in algebra geometric 2d
    return {v1.first * v2.second - v1.second * v2.first};
}


bool Triangle::contains(uint16_t x, uint16_t y) const {
    // TODO
    Point Vab = p1.getVector(this->p2);
    Point Vbc = p2.getVector(this->p3);
    Point Vca = p3.getVector(this->p1);
    Point Vax = p1.getVector(Point(x, y));
    Point Vbx = p2.getVector(Point(x, y));
    Point Vcx = p3.getVector(Point(x, y));
    int crossA = crossProductAG(Vab, Vax);
    int crossB = crossProductAG(Vbc, Vbx);
    int crossC = crossProductAG(Vca, Vcx);
    return ((crossA >= 0 && crossB >= 0 && crossC >= 0) || (crossA < 0 && crossB < 0 && crossC < 0));
}


bool Triangle::contains(const Shape::Point &p) const {
    return this->contains(p.first, p.second);
}

