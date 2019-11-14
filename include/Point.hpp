#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <utility>
#include <cstdint>

namespace Tangram::Shape {
    
    class Point : public std::pair<uint16_t, uint16_t> {
        public:
            using std::pair<uint16_t, uint16_t>::pair;
            Point operator+(const Point &other) const;
            Point rotate(uint8_t angle) const;
    };
};

#endif //POINT_HPP
