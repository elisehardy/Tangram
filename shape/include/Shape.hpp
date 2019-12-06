#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

#include "Point.hpp"
#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Observable.hpp"


namespace tangram::shape {
    
    class Shape : public gui::Drawable, public gui::Observable {
        
        private:
            MLV_Color color;
            bool hovered;
            bool lpressed;
            bool rpressed;
        
        protected:
            static constexpr uint16_t SIDE = 20;
            static const uint16_t HYPOTENUSE;
            
            
            Shape(MLV_Color color);
        
            [[nodiscard]] Point getCenter();
        
        public:
        
            virtual ~Shape() = default;
        
            bool operator==(const Shape &other) const;
        
            [[nodiscard]] virtual bool contains(uint16_t x, uint16_t y) const = 0;
        
            [[nodiscard]] bool contains(const Point &p) const;
        
            [[nodiscard]] virtual std::vector<Point> getPoints() const = 0;
        
            [[nodiscard]] virtual std::vector<Point> getPoints() = 0;
        
            void translate(const Vector &p);
        
            void rotate(int16_t n, const Point &center);
        
            void rotate(int16_t n);
        
            void update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
};

#endif // SHAPE_HPP
