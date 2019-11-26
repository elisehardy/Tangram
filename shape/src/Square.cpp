#include "../include/Square.hpp"


using namespace Tangram::Shape;

/*
Square::Square(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color) :
        Polygon(x, y, angle, size, color) {
}


Square::Square(Point center, uint8_t angle, Size size, MLV_Color color) :
        Polygon(center, angle, size, color) {
}*/

Square::Square(Tangram::Shape::Point t_p1, Tangram::Shape::Point t_p2, Tangram::Shape::Point t_p3, Tangram::Shape::Point t_p4, uint8_t angle, MLV_Color color) :
        Polygon(angle, color) {
    list_point.push_back(t_p1);
    list_point.push_back(t_p2);
    list_point.push_back(t_p3);
    list_point.push_back(t_p4);
    this->init();

}


Square::~Square() {
}


void Square::init() {
    this->p1 = list_point[0];
    this->p2 = list_point[1];
    this->p3 = list_point[2];
    this->p4 = list_point[3];

    this->update();
}


void Square::update() {
    //uint8_t angle = this->getAngle();
    this->setCenter(center());
    this->p1 = this->p1;
    this->p2 = this->p2;
    this->p3 = this->p3;
    this->p4 = this->p4;
}


std::vector <Point> Square::getPoints() const {
    return {this->p1, this->p2, this->p3, this->p4};
}


bool Square::contains(uint16_t x, uint16_t y) const {
    // TODO
    Tangram::Shape::Triangle t1 = Tangram::Shape::Triangle(this->p1, this->p2, this->p3, 0, 0);
    Tangram::Shape::Triangle t2 = Tangram::Shape::Triangle(this->p1, this->p4, this->p3, 0, 0);

    return (t1.contains(x,y) || t2.contains(x,y));
}


bool Square::contains(const Tangram::Shape::Point &p) const {
    return this->contains(p.first, p.second);
}

// centroid  center of mass
Point Square::center(){
    return {(this->p1.first + this->p4.first)/2, (this->p1.second + this->p4.second)/2} ;
}