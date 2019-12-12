#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>

#include <MLV/MLV_color.h>

#include "../../gui/include/Observable.hpp"
#include "../../gui/include/Drawable.hpp"

#include "Triangle.hpp"


namespace tangram::geometry {
    
    class Polygon : public gui::Drawable, public gui::Observable {
        
        private:
            std::vector<Triangle> triangles = {};
            int16_t currentRotation;
            Point pressedPoint;
            bool lpressed;
            bool rpressed;
            bool hovered;
            MLV_Color color;
            
            explicit Polygon(MLV_Color color);
        
        public:
            
            //////////////////////////// FACTORIES /////////////////////////////
            
            [[nodiscard]] static Polygon custom(const std::vector<Triangle> &triangles, MLV_Color color);
            
            [[nodiscard]] static Polygon smallTriangle(const Point &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon mediumTriangle(const Point &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon largeTriangle(const Point &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon square(const Point &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon parallelogram(const Point &offset, MLV_Color color);
            
            ///////////////////////// TRANSFORMATIONS //////////////////////////
            
            Polygon &translate(const Vector &v);
            
            Polygon &translate(int16_t x, int16_t y);
            
            Polygon &rotate(int16_t n, const Point &center);
            
            Polygon &rotate(int16_t n);
            
            ////////////////////////////// OTHERS //////////////////////////////
            
            [[nodiscard]] std::vector<Point> getPoints() const;
            
            [[nodiscard]] bool contains(const Point &p) const;
            
            void add(const std::vector<Triangle> &triangles);
            
            void add(const Triangle &t);
            
            void update(const game::Event &event, game::Engine &engine) override final;
            
            void draw() const override final;
    };
}

#endif // POLYGON_HPP
