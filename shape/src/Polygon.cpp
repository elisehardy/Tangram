#include "../include/Polygon.hpp"


using namespace Tangram::Shape;


Polygon::Polygon(uint8_t t_x, uint8_t t_y, uint8_t t_angle, Size t_size, MLV_Color t_color) :
        center(t_x, t_y), angle(t_angle), size(t_size), color(t_color) {
    this->init();
}


Polygon::Polygon(Point t_center, uint8_t t_angle, Size t_size, MLV_Color t_color) :
        center(t_center), angle(t_angle), size(t_size), color(t_color) {
    this->init();
}


Polygon::~Polygon() {
}


bool Polygon::operator==(const Polygon &other) const {
    std::vector <Point> v1 = this->getPoints(), v2 = other.getPoints();
    return std::is_permutation(v1.begin(), v1.end(), v2.begin());
}


Point Polygon::getCenter() const {
    return this->center;
}


uint8_t Polygon::getAngle() const {
    return this->angle;
}


Size Polygon::getSize() const {
    return this->size;
}


void Polygon::init() {
}


void Polygon::move(uint16_t x, uint16_t y) {
    this->center = Point(x, y);
    this->update();
}


void Polygon::move(Point p) {
    this->center = p;
    this->update();
}


void Polygon::rotate(int8_t n) {
    this->angle = (this->angle + n % ANGLE_STEP_PER_CYCLE
    * ANGLE_STEP) % 360;
    this->update();
}


void Polygon::draw() const {
    std::vector <Point> points = this->getPoints();
    uint8_t size = points.size(), i = 0;
    int32_t X[size], Y[size];
    
    for (auto &p: points) {
        X[i] = p.first;
        Y[i++] = p.second;
    }
    
    MLV_draw_filled_polygon(X, Y, size, this->color);
}
