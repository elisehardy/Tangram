#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include <vector>
#include <cmath>
#include "Polygon.hpp"


namespace Tangram::Shape {
    
    class Parallelogram : public Polygon {
        private:
            double i;
            double j;
            double k;
            Point p1;
            Point p2;
            Point p3;
            Point p4;
        
        public:
            using Polygon::Polygon;
            ~Parallelogram();
            std::vector<Point> getPoints() const override;
            void init() override;
            void update() override;
            bool contains(const Point &p) const override;
            bool contains(uint16_t x, uint16_t y) const override;
    };
};



#endif //PARALLELOGRAM_HPP
