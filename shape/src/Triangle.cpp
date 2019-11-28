#include "../include/Triangle.hpp"


using namespace Shape;


static int crossProduct(Vector v1, Vector v2) {
    return (v1.first * v2.second) - (v1.second * v2.first);
}


Triangle::Triangle(Shape::Point t_p1, Shape::Point t_p2, Shape::Point t_p3, uint8_t angle, MLV_Color color) :
        Polygon(angle, color) {
    this->points.push_back(t_p1);
    this->points.push_back(t_p2);
    this->points.push_back(t_p3);
    
    this->updateCenter();
}


bool Triangle::contains(uint16_t x, uint16_t y) const {
    std::vector<Point> points = this->getPoints();
    Point p1 = points[0], p2 = points[1], p3 = points[2];
    
    Vector Vab = p1.getVector(p2);
    Vector Vbc = p2.getVector(p3);
    Vector Vca = p3.getVector(p1);
    
    Vector Vax = p1.getVector(Point(x, y));
    Vector Vbx = p2.getVector(Point(x, y));
    Vector Vcx = p3.getVector(Point(x, y));
    
    int crossA = crossProduct(Vab, Vax);
    int crossB = crossProduct(Vbc, Vbx);
    int crossC = crossProduct(Vca, Vcx);
    
    return (crossA >= 0 && crossB >= 0 && crossC >= 0) || (crossA < 0 && crossB < 0 && crossC < 0);
}
