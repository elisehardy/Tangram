#include <algorithm>

#include "../include/Polygon.hpp"

#include "../include/Triangle.hpp"


using namespace tangram::shape;


Polygon::Polygon(const std::vector<Shape *> &shapes, MLV_Color color) :
        Shape(color) {
    this->shapes.insert(this->shapes.end(), shapes.begin(), shapes.end());
}


Polygon Polygon::square(const Point &offset, MLV_Color color) {
    auto *t1 = new Triangle(offset, color), *t2 = new Triangle(offset, color);
    t1->rotate(180);
    t1->translate({SIDE, SIDE});
    
    return Polygon({t1, t2}, color);
}


//Polygon Polygon::mediumTriangle(const Point &offset, MLV_Color color) {
//    return Polygon(0);
//}
//
//
//Polygon Polygon::largeTriangle(const Point &offset, MLV_Color color) {
//    return Polygon(0);
//}
//
//
//Polygon Polygon::parallelogram(const Point &offset, MLV_Color color) {
//    return Polygon(0);
//}


bool Polygon::contains(uint16_t x, uint16_t y) const {
    return std::any_of(this->shapes.begin(), this->shapes.end(), [x, y](auto &s) { return s->contains(x, y); });
}


std::vector<Point> Polygon::getPoints() const {
    std::vector<Point> points;
    
    std::for_each(
            this->shapes.begin(), this->shapes.end(), [&points](auto *s) {
                auto shapePoints = s->getPoints();
                points.insert(points.end(), shapePoints.begin(), shapePoints.end());
            }
    );
    
    return points;
}


std::vector<Point> Polygon::getPoints() {
    std::vector<Point> points;
    
    std::for_each(this->shapes.begin(), this->shapes.end(), [&points](Shape *s) {
                      std::vector<Point> sp = s->getPoints();
                      points.insert(points.end(), sp.begin(), sp.end());
                  }
    );
    
    return points;
}
