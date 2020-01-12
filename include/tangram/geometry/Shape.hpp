#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <string>

#include <tangram/game/Updatable.hpp>
#include <tangram/gui/Drawable.hpp>
#include <tangram/geometry/Polygon.hpp>


namespace tangram::geometry {
    class Shape : public gui::Drawable, public game::Updatable {
        
        private:
            std::vector<Polygon> polygons = {};
        
        public:
            
            ///////////////////// CONSTRUCTOR & DESTRUCTOR /////////////////////
            
            Shape() = default;
            
            static Shape load(const std::string &path);
            
            static Shape square();
            
            ///////////////////////// TRANSFORMATIONS //////////////////////////
            
            Shape &translate(const Vector16 &v);
            
            Shape &translate(int16_t x, int16_t y);
            
            Shape &scale(const VectorD &v);
            
            Shape &scale(double x, double y);
            
            Shape &scale(double factor);
            
            Shape &setColor(MLV_Color color);
            
            ///////////////////////////// OTHERS ///////////////////////////////
            
            bool operator==(const Shape &other) const;
            
            friend std::ostream &operator<<(std::ostream &os, const Shape &s);
            
            [[nodiscard]] std::vector<Point16> getPoints() const;
            
            [[nodiscard]] Polygon getRandomPolygon() const;
            
            void addPolygon(const Polygon &polygon);
            
            void ensureInbounds(Point16 lowerBound, Point16 upperBound);
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // SHAPE_HPP
