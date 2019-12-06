#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"


namespace tangram::shape {
    
    class Triangle : public Shape {
        
        private:
            Point p1;
            Point p2;
            Point p3;
        
        public:
        
            Triangle(const Point &offset, MLV_Color color);
        
            Triangle(const Point &p1, const Point &p2, const Point &p3, MLV_Color color);
        
            ~Triangle() override = default;
        
            [[nodiscard]] bool contains(uint16_t x, uint16_t y) const override;
        
            [[nodiscard]] std::vector<Point> getPoints() const override;
        
            [[nodiscard]] std::vector<Point> getPoints() override;
    };
};

#endif // TRIANGLE_HPP
