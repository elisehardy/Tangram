#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <vector>
#include "Polygon.hpp"
#include "Triangle.hpp"


namespace Shape {
    
    class Square : public Polygon {
        protected:
            [[nodiscard]] bool contains(uint16_t x, uint16_t y) const override;
        
        public:
            Square(Point t_p1, Point t_p2, Point t_p3, Point t_p4, uint8_t angle, MLV_Color color);
            ~Square() override = default;
    };
};

#endif // SQUARE_HPP
