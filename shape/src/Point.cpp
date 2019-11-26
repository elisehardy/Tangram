#include "../include/Point.hpp"


using namespace Tangram::Shape;

namespace Tangram::Shape {
    std::ostream &operator<<(std::ostream &os, const Point &p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
}

double DegToRad(double deg){
    return (deg * M_PI)/180.0;
}

Point Point::operator+(const Point &other) const {
    return {this->first + other.first, this->second + other.second};
}


Point Point::rotate(uint8_t angle, Point centre) const {
    double angle_rad = DegToRad(angle);
    std::cout << angle_rad << std::endl;
    uint16_t x = this->first, y = this->second;
    Vector p = Vector(x-centre.first, y-centre.second);
    
    return {
            p.first * cos(angle_rad) - p.second * sin(angle_rad) + centre.first,
            p.first * sin(angle_rad) + p.second * cos(angle_rad) + centre.second
    };
}


Vector Point::getVector(const Point &p2) const {
    return {p2.first - this->first, p2.second - this->second};
}


// centroid  center of mass triangle
 Point Point::center(Point p1, Point p2, Point p3){
    std::cout << "p1" <<p1 << "p2" << p2 << "p3"  << p3 << std::endl;
    std::cout << (p1.first + p2.first + p3.first)/3 << std::endl;
    std::cout << (p1.second + p2.second + p3.second)/3 << std::endl;
    return {(p1.first + p2.first + p3.first)/3, (p1.second + p2.second + p3.second)/3} ;
}
