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
            using Polygon::Polygon;
            ~Triangle();
            std::vector<Point> getPoints() const override;
            void init() override;
            void update() override;
            bool contains(const Point &p) const override;
            bool contains(uint16_t x, uint16_t y) const override;
    };
};

#endif // TRIANGLE_HPP
