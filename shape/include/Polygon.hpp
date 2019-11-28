#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <algorithm>

#include "Point.hpp"
#include "../../gui/include/Drawable.hpp"


#define ANGLE_STEP 20
#define ANGLE_STEP_PER_CYCLE (360 / ANGLE_STEP)

namespace Shape {
    
    class Polygon : public GUI::Drawable, public GUI::Observable {
        
        protected:
            uint8_t angle;             /**< Angle of the shape. */
            MLV_Color color;           /**< Color of the shape. */
            Point center;              /**< Coordinates of the center of the shape. */
            std::vector<Point> points; /**< Points of the polygon. */
            
            Point startHeld;           /**< Position of the mouse when the Polygon was first held. */
            bool hovered;              /**< Whether the Polygon is hovered by the mouse. */
            bool lpressed;
            bool rpressed;
            
            /**
             * Polygon's default constructor.
             *
             * @param angle Angle of the polygon.
             * @param color Color of the polygon.
             */
            Polygon(uint8_t angle, MLV_Color color);
            
            
            /**
             * Destructor
             */
            virtual ~Polygon() = default;
            
            /**
             * Update the center of the polygon according to the points in 'points' field.
             */
            void updateCenter();
        
            void translate(uint16_t x, uint16_t y);
        
            void translate(const Vector &p);
        
            /**
             * Rotate the shape by n step.
             *
             * @param n Number of step to rotate the polygon.
             */
            void rotate(int8_t n);
        
        public:
        
            /**
             * Check if the Polygon contains the point p;
             *
             * @param x X coordinate of the Point checked against the Polygon.
             * @param y Y coordinate of the Point checked against the Polygon.
             *
             * @return true if the Point is inside the Polygon, false otherwise.
             */
            [[nodiscard]] virtual bool contains(uint16_t x, uint16_t y) const = 0;
        
            /**
             * Check if the Polygon contains the point p;
             *
             * @param p Point checked against the Polygon.
             *
             * @return true if the Point is inside the Polygon, false otherwise.
             */
            [[nodiscard]] bool contains(const Point &p);
        
            /**
             * @returns A vector of the points representing the polygon.
             */
            [[nodiscard]] std::vector<Point> getPoints() const;
        
            void update(const Game::Event &event, Game::Engine &engine) override;
        
            void draw() const override;
    };
};

#endif //POLYGON_HPP
