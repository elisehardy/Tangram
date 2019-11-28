#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <algorithm>

#include "Point.hpp"
#include "../../gui/include/Drawable.hpp"


#define ANGLE_STEP 20
#define ANGLE_STEP_PER_CYCLE (360 / ANGLE_STEP)

namespace Shape {
    
    class Polygon : public GUI::Drawable {
        
        protected:
            uint8_t angle;             /**< Angle of the shape. */
            MLV_Color color;           /**< Color of the shape. */
            Point center;              /**< Coordinates of the center of the shape. */
            bool held;                 /**< Whether the Polygon is held by the mouse. */
            std::vector<Point> points; /**< Points of the polygon. */
            
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
             * @returns A vector of the points representing the polygon.
             */
            [[nodiscard]] std::vector<Point> getPoints() const;
            
            /**
             * Update the center of the polygon according to the points in 'points' field.
             */
            void updateCenter();
            
            /**
             * Move the center of the polygon to the new coordinates.
             *
             * @param x X coordinate of the new center.
             * @param y Y coordinate of the new center.
             */
            void translate(uint16_t x, uint16_t y);
            
            /**
             * Move the center of the polygon to the new coordinates.
             *
             * @param P coordinates of the new center.
             */
            void translate(const Point &p);
            
            /**
             * Rotate the shape by n step.
             *
             * @param n Number of step to rotate the polygon.
             */
            void rotate(int8_t n);
        
        public:
            
            /**
             * Return whether two Polygons are equal or not by checking if their
             * set of points is the same.
             *
             * @param other Other Polygon to compare with.
             *
             * @return true if the Polygons are equal, false otherwise.
             */
            bool operator==(const Polygon &other) const;
            
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
            
            void update(const Game::Event &event, Game::Engine &engine) override;
            
            void draw() const override;
    };
};

#endif //POLYGON_HPP
