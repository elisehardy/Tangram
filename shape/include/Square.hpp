#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <vector>
#include "Polygon.hpp"
#include "Triangle.hpp"


namespace Tangram::Shape {

    class Square : public Polygon {
    private:
        Point p1;
        Point p2;
        Point p3;
        Point p4;

    public:
        Square(Point t_p1, Point t_p2, Point t_p3,
                       Point t_p4, uint8_t angle, MLV_Color color) ;
        //Square(Point center, uint8_t angle, Size size, MLV_Color color);
                ~Square();

        std::vector <Point> getPoints() const override;

        void init() override;

        void update() override;

        bool contains(const Point &p) const override;

        bool contains(uint16_t x, uint16_t y) const override;
        Point center();

        };
};

#endif // SQUARE_HPP
