#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <utility>
#include <cstdint>
#include <iostream>

namespace Tangram::Shape {

    class Point : public std::pair<uint16_t, uint16_t> {
        public:
            using std::pair<uint16_t, uint16_t>::pair;
            Point operator+(const Point &other) const;
            Point rotate(uint8_t angle) const;
            Point getVector(const Point &p2) const;
            Point dotProduct(const Point &v2) const;
            friend std::ostream& operator<<(std::ostream& os, const Point& dt);

        };
};

#endif //POINT_HPP
