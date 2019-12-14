#include "../include/Shape.hpp"

#include <algorithm>


using namespace tangram::geometry;


tangram::geometry::Shape::Shape(std::string path) {}


Shape Shape::square(const Point16 &offset) {
    return Shape();
}


bool tangram::geometry::Shape::operator==(const tangram::geometry::Shape &other) const {
    return false;
}


std::vector<Point16> tangram::geometry::Shape::getPoints() const {
    return std::vector<Point16>();
}


void tangram::geometry::Shape::update(const tangram::game::Event &event, tangram::game::Engine &engine) {}


void tangram::geometry::Shape::draw() const {}
