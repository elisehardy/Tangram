#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <utility>
#include <cstdint>
#include <iostream>
#include "Vector.hpp"

namespace Tangram::Shape {

    class Point : public std::pair<uint16_t, uint16_t> {
        public:
            using std::pair<uint16_t, uint16_t>::pair;
            Point operator+(const Point &other) const;
            Point rotate(uint8_t angle, Point centre) const;
            Vector getVector(const Point &p2) const;
            friend std::ostream& operator<<(std::ostream& os, const Point& dt);
           static Point center(Point p1, Point p2, Point p3);

        };
};

#endif //POINT_HPP
