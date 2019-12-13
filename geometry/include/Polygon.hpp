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
            Point16 center = {0, 0};
            int16_t angle = 0;
            MLV_Color color;
            
            Point16 pressedPoint = {0, 0};
            int16_t currentRotation = 0;
            bool lpressed = false;
            bool rpressed = false;
            bool hovered = false;
            
            explicit Polygon(MLV_Color color);
        
        public:
            
            //////////////////////////// FACTORIES /////////////////////////////
            
            [[nodiscard]] static Polygon custom(const std::vector<Triangle> &triangles, MLV_Color color);
            
            [[nodiscard]] static Polygon smallTriangle(const Point16 &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon mediumTriangle(const Point16 &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon largeTriangle(const Point16 &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon square(const Point16 &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon parallelogram(const Point16 &offset, MLV_Color color);
            
            ///////////////////////// TRANSFORMATIONS //////////////////////////
            
            Polygon &translate(const Vector<int16_t> &v);
            
            Polygon &translate(int16_t x, int16_t y);
            
            Polygon &rotate(int16_t n);
            
            ////////////////////////////// OTHERS //////////////////////////////
            
            [[nodiscard]] std::vector<Point16> getPoints() const;
            
            [[nodiscard]] bool contains(const Point16 &p) const;
            
            void save(const Polygon &p, MLV_Color color, bool shadow) const;
        
            void add(const std::vector<Triangle> &triangles);
        
            void add(const Triangle &t);
            
            void update(const game::Event &event, game::Engine &engine) override final;
        
            void draw() const override final;
            
            void shadow(MLV_Color color) const;
    };
}

#endif // POLYGON_HPP
