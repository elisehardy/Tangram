#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <string>

#include "../../gui/include/Observable.hpp"
#include "../../gui/include/Drawable.hpp"

#include "Polygon.hpp"


namespace tangram::geometry {
    class Shape : public gui::Drawable, public gui::Observable {
        
        private:
            std::vector<Polygon> polygons = {};
        
        public:
            
            Shape() = default;
            
            Shape(std::string path);
        
            static Shape square(const Point16 &offset);
            
            bool operator==(const Shape &other) const;
        
            [[nodiscard]] std::vector<Point16> getPoints() const;
            
            void update(const game::Event &event, game::Engine &engine) override final;
            
            void draw() const override final;
    };
}

#endif // SHAPE_HPP
