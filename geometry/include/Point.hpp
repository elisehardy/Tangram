#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>


namespace tangram::geometry {
    
    class Point {
        public:
            static constexpr uint16_t NEAR_THRESHOLD = 10;
            
            int16_t x;
            int16_t y;
            
            Point(int16_t x, int16_t y);
            
            bool operator==(const Point &other) const;
            
            Point operator+(const Point &other) const;
            
            Point operator-(const Point &other) const;
            
            int32_t operator^(const Point &other) const;
            
            friend std::ostream &operator<<(std::ostream &os, const Point &dt);
            
            [[nodiscard]] Point rotate(int16_t angle, const Point &center) const;
            
            [[nodiscard]] Point translate(const Point &translation) const;
            
            [[nodiscard]] Point translate(int16_t x, int16_t y) const;
            
            [[nodiscard]] static Point center(const std::vector<Point> &points);
    };
    
    
    
    typedef Point Vector;
}

#endif //POINT_HPP
