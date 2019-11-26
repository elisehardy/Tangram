#include "../include/Triangle.hpp"


using namespace Tangram::Shape;


/*Triangle::Triangle(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color) :
        Polygon(x, y, angle, size, color) {
    this->init();
}


Triangle::Triangle(Point center, uint8_t angle, Size size, MLV_Color color) :
        Polygon(center, angle, size, color) {
    this->init();
}*/


Triangle::Triangle(Tangram::Shape::Point t_p1, Tangram::Shape::Point t_p2, Tangram::Shape::Point t_p3, uint8_t angle, MLV_Color color):
    Polygon(angle, color){
    list_point.push_back(t_p1);
    list_point.push_back(t_p2);
    list_point.push_back(t_p3);

    this->init();
}


Triangle::~Triangle() {
}


void Triangle::init() {
    this->p1 = list_point[0];
    this->p2 = list_point[1];
    this->p3 = list_point[2];
    this->update();
}


void Triangle::update() {
    uint8_t angle = this->getAngle();
    this->setCenter(center().rotate(angle));
    this->p1 = this->p1.rotate(angle);
    this->p2 = this->p2.rotate(angle);
    this->p3 = this->p3.rotate(angle);
}


std::vector <Point> Triangle::getPoints() const {
    return {this->p1, this->p2, this->p3};
}


int crossProductAG(Vector v1, Vector v2) {
    // a ^ b  in algebra geometric 2d
    return {(v1.first * v2.second) - (v1.second * v2.first)};
}


bool Triangle::contains(uint16_t x, uint16_t y) const {
    // TODO
    Vector Vab = p1.getVector(this->p2);
    Vector Vbc = p2.getVector(this->p3);
    Vector Vca = p3.getVector(this->p1);

    Vector Vax = p1.getVector(Point(x, y));
    Vector Vbx = p2.getVector(Point(x, y));
    Vector Vcx = p3.getVector(Point(x, y));

    int crossA = crossProductAG(Vab, Vax);
    int crossB = crossProductAG(Vbc, Vbx);
    int crossC = crossProductAG(Vca, Vcx);

    return ((crossA >= 0 && crossB >= 0 && crossC >= 0) || (crossA < 0 && crossB < 0 && crossC < 0));
}


bool Triangle::contains(const Tangram::Shape::Point &p) const {
    return this->contains(p.first, p.second);
}

// centroid  center of mass
Point Triangle::center(){
        return {(this->p1.first + this->p2.first + this->p3.first)/3, (this->p1.second + this->p2.second + this->p3.second)/3} ;
}