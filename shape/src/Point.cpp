#include "../include/Point.hpp"


using namespace Tangram::Shape;

namespace Tangram::Shape {
    std::ostream &operator<<(std::ostream &os, const Point &p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
}


Point Point::operator+(const Point &other) const {
    return {this->first + other.first, this->second + other.second};
}


Point Point::rotate(uint8_t angle) const {
    uint16_t x = this->first, y = this->second;
    
    return {
            x * cos(angle) + y * sin(angle),
            -x * sin(angle) + y * cos(angle)
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
