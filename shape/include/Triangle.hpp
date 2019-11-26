#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <vector>
#include "Polygon.hpp"

namespace Tangram::Shape {
    
    class Triangle : public Polygon {
        private:
            Point p1;
            Point p2;
            Point p3;
        
        public:
            //Triangle(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color);
            //Triangle(Point center, uint8_t angle, Size size, MLV_Color color);
            Triangle(Point p1, Point p2, Point p3, uint8_t angle, MLV_Color color);

            ~Triangle();
            std::vector<Point> getPoints() const override;
            void init() override;
            void update() override;
            bool contains(const Point &p) const override;
            bool contains(uint16_t x, uint16_t y) const override;
             Point center();

        };
};

#endif // TRIANGLE_HPP
