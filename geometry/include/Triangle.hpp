#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <MLV/MLV_color.h>

#include "Point.hpp"


namespace tangram::geometry {
    
    class Triangle {
        
        private:
            Point p1;
            Point p2;
            Point p3;
        
        public:
            static constexpr uint16_t SIDE = 100;
            static const uint16_t HYPOTENUSE;
            
            explicit Triangle(const Point &offset);
            
            Triangle(Point p1, Point p2, Point p3);
            
            [[nodiscard]] Triangle translate(const Vector &v) const;
            
            [[nodiscard]] Triangle rotate(int16_t n, const Point &center) const;
            
            [[nodiscard]] Triangle rotate(int16_t n) const;
            
            [[nodiscard]] bool contains(const Point &p) const;
            
            [[nodiscard]] std::vector<Point> getPoints() const;
            
            void draw(MLV_Color color) const;
    };
};

#endif // TRIANGLE_HPP
