#include "../include/Square.hpp"


using namespace Shape;


Square::Square(Shape::Point t_p1, Shape::Point t_p2, Shape::Point t_p3, Shape::Point t_p4, MLV_Color color) :
        Polygon(color) {
    this->points.push_back(t_p1);
    this->points.push_back(t_p2);
    this->points.push_back(t_p3);
    this->points.push_back(t_p4);
    
    this->updateCenter();
}


bool Square::contains(uint16_t x, uint16_t y) const {
    std::vector<Point> points = this->getPoints();
    Point p1 = points[0], p2 = points[1], p3 = points[2], p4 = points[3];
    
    Shape::Triangle t1 = Shape::Triangle(p1, p2, p3, 0);
    Shape::Triangle t2 = Shape::Triangle(p1, p4, p3, 0);
    
    return t1.contains(x, y) || t2.contains(x, y);
}
