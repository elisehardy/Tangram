#include "../include/Triangle.hpp"


using namespace Tangram::Shape;


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


std::vector<Point> Triangle::getPoints() const {
    return {this->p1, this->p2, this->p3};
}

bool Triangle::contains(uint16_t x, uint16_t y) const {
    // TODO
    return true;
}

bool Triangle::contains(const Tangram::Shape::Point &p) const {
    return this->contains(p.first, p.second);
}
