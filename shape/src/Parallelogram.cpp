#include "../include/Parallelogram.hpp"


using namespace Tangram::Shape;

Parallelogram::Parallelogram(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color): Polygon(x, y, angle, size, color),i(0), j(0), k(0),
                                                                                               p1(Point({0, 0})),
                                                                                               p2(Point({0, 0})),
                                                                                               p3(Point({0, 0})),
                                                                                               p4(Point({0, 0})) {}
Parallelogram::Parallelogram(Point center, uint8_t angle, Size size, MLV_Color color): Polygon(center, angle, size, color),i(0), j(0), k(0),
                                                                                       p1(Point({0, 0})),
                                                                                       p2(Point({0, 0})),
                                                                                       p3(Point({0, 0})),
                                                                                       p4(Point({0, 0})) {}
void Parallelogram::init() {
    uint16_t size = this->getSize();
    double hsize = size / 2, h, i, j, k;

    h = std::sqrt(size * size * 2); // Pythagorean Theorem
    i = h * (hsize / size); // Thales Theorem (Intercept theorem)
    j = (h - i) / 2; // h = i + j * 2
    k = std::sqrt(hsize * hsize + j * j); // Pythagorean Theorem

    this->i = i;
    this->j = j;
    this->k = k;

    this->update();
}


void Parallelogram::update() {
    uint8_t a = this->getAngle();
    Point c = this->getCenter();
    Point ul = {-this->k, -this->j}, ur = {this->k, -this->i - this->j};
    Point bl = {-this->k, this->i + this->j}, br = {this->k, this->j};

    this->p1 = (c + ur).rotate(a);
    this->p2 = (c + ul).rotate(a);
    this->p3 = (c + bl).rotate(a);
    this->p4 = (c + br).rotate(a);
}


std::vector<Point> Parallelogram::getPoints() const {
    return {this->p1, this->p2, this->p3};
}

bool Parallelogram::contains(uint16_t x, uint16_t y) const {
    // TODO
    return true;
}

bool Parallelogram::contains(const Tangram::Shape::Point &p) const {
    return this->contains(p.first, p.second);
}
