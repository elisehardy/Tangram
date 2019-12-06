#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <list>
#include <memory>
#include <vector>

#include "Triangle.hpp"


namespace tangram::shape {
    
    class Polygon : public Shape {
        
        private:
            std::list<Shape *> shapes;
            
            ~Polygon() override = default;
        
        public:
            
            Polygon(const std::vector<Shape *> &shapes, MLV_Color color);
            
            [[nodiscard]] static Polygon square(const Point &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon mediumTriangle(const Point &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon largeTriangle(const Point &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon parallelogram(const Point &offset, MLV_Color color);
            
            [[nodiscard]] bool contains(uint16_t x, uint16_t y) const override;
            
            [[nodiscard]] std::vector<Point> getPoints() const override;
            
            [[nodiscard]] std::vector<Point> getPoints() override;
    };
};

#endif // POLYGON_HPP
