#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <vector>

#include "Polygon.hpp"


namespace Shape {
    
    class Triangle : public Polygon {
        public:
            Triangle(Point p1, Point p2, Point p3, MLV_Color color);
            ~Triangle() override = default;
            
            [[nodiscard]] bool contains(uint16_t x, uint16_t y) const override;
    };
};

#endif // TRIANGLE_HPP
