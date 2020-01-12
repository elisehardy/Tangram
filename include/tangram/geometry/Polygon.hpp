#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <fstream>

#include <MLV/MLV_color.h>

#include <tangram/game/Updatable.hpp>
#include <tangram/geometry/Triangle.hpp>
#include <tangram/gui/Drawable.hpp>


namespace tangram::geometry {
    
    class Polygon : public gui::Drawable, public game::Updatable {
        
        private:
            std::vector<Triangle> triangles = {};
            int16_t currentRotation = 0;
            Point16 center = { 0, 0 };
            int16_t angle = 0;
            MLV_Color color = 0;
        
        public:
            
            ///////////////////// CONSTRUCTOR & DESTRUCTOR /////////////////////
            
            Polygon() = default;
            
            explicit Polygon(MLV_Color color);
            
            Polygon(const Polygon &) = default;
            
            Polygon(Polygon &&) = default;
            
            Polygon &operator=(const Polygon &) = default;
            
            Polygon &operator=(Polygon &&) = default;
            
            //////////////////////////// FACTORIES /////////////////////////////
            
            [[nodiscard]] static Polygon custom(const std::vector<Triangle> &triangles, MLV_Color color);
            
            [[nodiscard]] static Polygon smallTriangle(const Point16 &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon mediumTriangle(const Point16 &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon largeTriangle(const Point16 &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon square(const Point16 &offset, MLV_Color color);
            
            [[nodiscard]] static Polygon parallelogram(const Point16 &offset, MLV_Color color);
            
            ///////////////////////// GETTERS & SETTERS ////////////////////////
            
            [[nodiscard]] std::vector<Point16> getPoints() const;
            
            [[nodiscard]] int16_t getCurrentRotation() const;
            
            void setCurrentRotation(int16_t currentRotation);
            
            void setColor(MLV_Color color);
            
            ///////////////////////// TRANSFORMATIONS //////////////////////////
            
            Polygon &translate(const Vector16 &v);
            
            Polygon &translate(int16_t x, int16_t y);
            
            Polygon &scale(const VectorD &v);
            
            Polygon &scale(double x, double y);
            
            Polygon &scale(double factor);
            
            Polygon &rotate(int16_t n);
            
            ////////////////////////////// OTHERS //////////////////////////////
            
            friend std::ostream &operator<<(std::ostream &os, const Polygon &p);
            
            [[nodiscard]] bool contains(const Point16 &p) const;
            
            void add(const std::vector<Triangle> &triangles);
            
            void add(const Triangle &t);
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // POLYGON_HPP
