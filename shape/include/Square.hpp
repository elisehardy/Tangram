#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <vector>
#include "Polygon.hpp"
#include "Triangle.hpp"


namespace Shape {
    
    class Square : public Polygon {
        public:
            Square(Point t_p1, Point t_p2, Point t_p3, Point t_p4, MLV_Color color);
            ~Square() override = default;
        
            [[nodiscard]] bool contains(uint16_t x, uint16_t y) const override;
    };
};

#endif // SQUARE_HPP
