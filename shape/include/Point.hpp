#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <utility>
#include <cstdint>
#include <iostream>
#include <vector>

#include "Vector.hpp"


namespace Shape {
    
    class Point : public std::pair<uint16_t, uint16_t> {
        public:
            using std::pair<uint16_t, uint16_t>::pair;
            
            Point operator+(const Point &other) const;
        
            Vector operator-(const Point &other) const;
            
            friend std::ostream &operator<<(std::ostream &os, const Point &dt);
            
            [[nodiscard]] Point rotate(uint8_t angle, const Point &center) const;
            
            [[nodiscard]] Point translate(const Vector &translation) const;
            
            [[nodiscard]] static Point center(const std::vector<Point> &points);
    };
};

#endif //POINT_HPP
