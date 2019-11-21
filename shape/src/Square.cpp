#include "../include/Square.hpp"


using namespace Tangram::Shape;


Square::Square(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color) :
        Polygon(x, y, angle, size, color) {
}


Square::Square(Point center, uint8_t angle, Size size, MLV_Color color) :
        Polygon(center, angle, size, color) {
}


Square::~Square() {
}


void Square::init() {
    this->update();
}


void Square::update() {
    uint8_t angle = this->getAngle();
    Point center = this->getCenter();
    Size size = this->getSize();
    Point ul = {-size, -size}, ur = {size, -size}, bl = {-size, size}, br = {size, size};
    
    this->p1 = (center + ur).rotate(angle);
    this->p2 = (center + ul).rotate(angle);
    this->p3 = (center + bl).rotate(angle);
    this->p4 = (center + br).rotate(angle);
}


std::vector <Point> Square::getPoints() const {
    return {this->p1, this->p2, this->p3, this->p4};
}


bool Square::contains(uint16_t x, uint16_t y) const {
    // TODO
    return true;
}


bool Square::contains(const Tangram::Shape::Point &p) const {
    return this->contains(p.first, p.second);
}
