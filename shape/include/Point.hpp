#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>


namespace tangram::shape {
    
    class Point : public std::pair<int16_t, int16_t> {
        public:
            static constexpr uint16_t NEAR_THRESHOLD = 10;
            
            using std::pair<int16_t, int16_t>::pair;
        
            bool operator==(const Point &other) const;
            
            Point operator+(const Point &other) const;
            
            Point operator-(const Point &other) const;
            
            uint16_t operator^(const Point &other) const;
            
            friend std::ostream &operator<<(std::ostream &os, const Point &dt);
            
            [[nodiscard]] Point rotate(uint8_t angle, const Point &center) const;
            
            [[nodiscard]] Point translate(const Point &translation) const;
            
            [[nodiscard]] static Point center(const std::vector<Point> &points);
    };
    
    
    
    typedef Point Vector;
};

#endif //POINT_HPP
