#include "../include/Parallelogram.hpp"


using namespace Tangram::Shape;


/*Parallelogram::Parallelogram(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color) :
        Polygon(x, y, angle, size, color) {
}*/


Parallelogram::Parallelogram(Tangram::Shape::Point t_p1, Tangram::Shape::Point t_p2, Tangram::Shape::Point t_p3,
                             Tangram::Shape::Point t_p4, uint8_t angle, MLV_Color color) :
        Polygon(angle, color) {
    list_point.push_back(t_p1);
    list_point.push_back(t_p2);
    list_point.push_back(t_p3);
    list_point.push_back(t_p4);
    this->init();

}


Parallelogram::~Parallelogram() {
}


void Parallelogram::init() {
    this->p1 = list_point[0];
    this->p2 = list_point[1];
    this->p3 = list_point[2];
    this->p4 = list_point[3];

    this->update();
}


void Parallelogram::update() {
    uint8_t angle = this->getAngle();
    this->setCenter(center().rotate(angle));
    this->p1 = this->p1.rotate(angle);
    this->p2 = this->p2.rotate(angle);
    this->p3 = this->p3.rotate(angle);
    this->p4 = this->p4.rotate(angle);
}


std::vector <Point> Parallelogram::getPoints() const {
    return {this->p1, this->p2, this->p3, this->p4};
}


bool Parallelogram::contains(uint16_t x, uint16_t y) const {
    // TODO
    Tangram::Shape::Triangle t1 = Tangram::Shape::Triangle(this->p1, this->p2, this->p3, 0, 0);
    Tangram::Shape::Triangle t2 = Tangram::Shape::Triangle(this->p1, this->p4, this->p3, 0, 0);

    return (t1.contains(x,y) || t2.contains(x,y));

}


bool Parallelogram::contains(const Tangram::Shape::Point &p) const {
    return this->contains(p.first, p.second);
}

// centroid  center of mass
Point Parallelogram::center(){
    return {(this->p1.first + this->p4.first)/2, (this->p1.second + this->p4.second)/2} ;
}