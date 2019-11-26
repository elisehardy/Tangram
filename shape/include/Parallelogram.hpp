#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include <vector>
#include <cmath>
#include "Polygon.hpp"
#include "Triangle.hpp"


namespace Tangram::Shape {
    
    class Parallelogram : public Polygon {
        private:
            Point p1;
            Point p2;
            Point p3;
            Point p4;
        
        public:
            //Parallelogram(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color);
            Parallelogram(Point t_p1, Point t_p2, Point t_p3,
                                         Point t_p4, uint8_t angle, MLV_Color color) ;
            ~Parallelogram();
            std::vector<Point> getPoints() const override;
            void init() override;
            void update() override;
            bool contains(const Point &p) const override;
            bool contains(uint16_t x, uint16_t y) const override;
            Point center();

        };
};



#endif //PARALLELOGRAM_HPP
