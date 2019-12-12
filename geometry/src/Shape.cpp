#include <algorithm>

#include "../include/Shape.hpp"


using namespace tangram::geometry;


tangram::geometry::Shape::Shape(std::string path) {
}


Shape Shape::square(const Point &offset) {
    Shape shape;
    
    shape.polygons.push_back(
            Polygon::square(offset, MLV_COLOR_WHITE)
                    .translate(Triangle::SIDE, Triangle::SIDE * 2)
                    .rotate(45)
    );
    shape.polygons.push_back(
            Polygon::smallTriangle(offset, MLV_COLOR_WHITE)
    );
    
    return shape;
}


bool tangram::geometry::Shape::operator==(const tangram::geometry::Shape &other) const {
    std::vector<Point> aPoints = this->getPoints(), bPoints = other.getPoints();
    return aPoints.size() == bPoints.size() && std::is_permutation(aPoints.begin(), aPoints.end(), bPoints.begin());
}


std::vector<Point> tangram::geometry::Shape::getPoints() const {
    std::vector<Point> points = {};
    
    for (const Polygon &p: this->polygons) {
        auto polygonPoints = p.getPoints();
        std::for_each(
                polygonPoints.begin(), polygonPoints.end(),
                [&points](const Point &p) { points.push_back(Point(p)); }
        );
    }
    
    return points;
}


void tangram::geometry::Shape::update(const tangram::game::Event &event, tangram::game::Engine &engine) {
    std::for_each(this->polygons.begin(), this->polygons.end(), [&](Polygon &p) { p.update(event, engine); });
}


void tangram::geometry::Shape::draw() const {
    std::for_each(this->polygons.begin(), this->polygons.end(), [](const Polygon &p) { p.draw(); });
}
