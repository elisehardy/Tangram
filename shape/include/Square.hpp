#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <vector>
#include "Polygon.hpp"


namespace Tangram::Shape {
    
    class Square : public Polygon {
        private:
            Point p1;
            Point p2;
            Point p3;
            Point p4;
        
        public:
            using Polygon::Polygon;
            ~Square();
            std::vector<Point> getPoints() const override;
            void init() override;
            void update() override;
            bool contains(const Point &p) const override;
            bool contains(uint16_t x, uint16_t y) const override;
    };
};

#endif // SQUARE_HPP
