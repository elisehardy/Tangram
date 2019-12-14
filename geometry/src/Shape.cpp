#include "../include/Shape.hpp"

#include <algorithm>


using namespace tangram::geometry;


tangram::geometry::Shape::Shape(std::string path) {
}


Shape Shape::square(const Point16 &offset) {
    Shape shape;
    
    auto ltriangle1 = Polygon::largeTriangle(offset, MLV_COLOR_PURPLE).rotate(135);
    ltriangle1.translate(-Triangle::SIDE * 0.17, Triangle::SIDE * 0.75);
    
    auto ltriangle2 = Polygon::largeTriangle(offset, MLV_COLOR_RED).rotate(225);
    ltriangle2.translate(Triangle::SIDE * 0.75, -Triangle::SIDE * 0.17);
    
    auto mtriangle = Polygon::mediumTriangle(offset, MLV_COLOR_GREEN).rotate(180);
    mtriangle.translate(Triangle::SIDE * 1.89, Triangle::SIDE * 1.91);
    
    auto striangle1 = Polygon::smallTriangle(offset, MLV_COLOR_ORANGE2).rotate(45);
    striangle1.translate(Triangle::SIDE * 0.36, Triangle::SIDE * 2.27);
    
    auto striangle2 = Polygon::smallTriangle(offset, MLV_COLOR_YELLOW).rotate(315);
    striangle2.translate(Triangle::SIDE * 1.54, Triangle::SIDE * 1.1);
    
    auto square = Polygon::square(offset, MLV_COLOR_WHITE).rotate(45);
    square.translate(Triangle::SIDE * 0.9, Triangle::SIDE * 1.64);
    
    auto parallelogram = Polygon::parallelogram(offset, MLV_COLOR_CYAN).rotate(90);
    parallelogram.translate(Triangle::SIDE * 1.42, Triangle::SIDE * 0.71);
    
    shape.polygons.push_back(ltriangle1);
    shape.polygons.push_back(ltriangle2);
    shape.polygons.push_back(mtriangle);
    shape.polygons.push_back(striangle1);
    shape.polygons.push_back(striangle2);
    shape.polygons.push_back(square);
    shape.polygons.push_back(parallelogram);
    
    return shape;
}


bool tangram::geometry::Shape::operator==(const tangram::geometry::Shape &other) const {
    std::vector<Point16> aPoints = this->getPoints(), bPoints = other.getPoints();
    return aPoints.size() == bPoints.size() && std::is_permutation(aPoints.begin(), aPoints.end(), bPoints.begin());
}


std::vector<Point16> tangram::geometry::Shape::getPoints() const {
    std::vector<Point16> points = {};
    
    for (const Polygon &p: this->polygons) {
        auto polygonPoints = p.getPoints();
        std::for_each(
                polygonPoints.begin(), polygonPoints.end(),
                [&points](const Point16 &p) { points.push_back(Point16(p)); }
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
