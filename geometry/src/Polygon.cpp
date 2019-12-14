#include <algorithm>
#include <regex>

#include "../include/Polygon.hpp"


using namespace tangram::geometry;


Polygon::Polygon(MLV_Color t_color) {}


Polygon Polygon::custom(const std::vector<Triangle> &triangles, MLV_Color color) {
    return Polygon(0);
}


Polygon Polygon::smallTriangle(const Point16 &offset, MLV_Color color) {
    return Polygon(0);
}


Polygon Polygon::mediumTriangle(const Point16 &offset, MLV_Color color) {
    return Polygon(0);
}


Polygon Polygon::largeTriangle(const Point16 &offset, MLV_Color color) {
    return Polygon(0);
}


Polygon Polygon::parallelogram(const Point16 &offset, MLV_Color color) {
    return Polygon(0);
}


Polygon Polygon::square(const Point16 &offset, MLV_Color color) {
    return Polygon(0);
}


Polygon &Polygon::translate(const Vector16 &v) {
    return *this;
}


Polygon &Polygon::translate(int16_t x, int16_t y) {
    return *this;
}


Polygon &Polygon::rotate(int16_t n) {
    return *this;
}


std::vector<Point16> Polygon::getPoints() const {
    return std::vector<Point16>();
}


bool Polygon::contains(const Point16 &p) const {
    return false;
}


void Polygon::save(const Polygon &p, MLV_Color color, bool shadow) const {}


void Polygon::add(const Triangle &t) {}


void Polygon::add(const std::vector<Triangle> &triangles) {}


void Polygon::update(const game::Event &event, game::Engine &engine) {}


void Polygon::draw() const {}


void Polygon::shadow(MLV_Color color) const {}
