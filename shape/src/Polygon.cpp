#include "../include/Polygon.hpp"


using namespace Shape;


Polygon::Polygon(uint8_t t_angle, MLV_Color t_color) :
        angle(t_angle), color(t_color), held(false) {
}


bool Polygon::operator==(const Polygon &other) const {
    std::vector<Point> v1 = this->getPoints(), v2 = other.getPoints();
    return std::is_permutation(v1.begin(), v1.end(), v2.begin());
}


void Polygon::updateCenter() {
    this->center = Point::center(points);
}


std::vector<Point> Polygon::getPoints() const {
    return this->points;
}


void Polygon::move(uint16_t x, uint16_t y) {
    this->center = Point(x, y);
}


void Polygon::move(const Point &p) {
    this->move(p.first, p.second);
}


void Polygon::rotate(int8_t n) {
    this->angle = (this->angle + n % ANGLE_STEP_PER_CYCLE * ANGLE_STEP) % 360;
    for (auto &p : points) {
        p = p.rotate(this->angle, this->center);
    }
}


bool Polygon::contains(const Point &p) {
    return this->contains(p.first, p.second);
}


void Polygon::draw() const {
    std::vector<Point> points = this->getPoints();
    uint8_t size = points.size(), i = 0;
    int32_t X[size], Y[size];
    
    for (auto &p: points) {
        X[i] = p.first;
        Y[i++] = p.second;
    }
    
    MLV_draw_filled_polygon(X, Y, size, this->color);
}


void Polygon::update(const Game::Event &event, Game::Engine &engine) {
}



