#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <algorithm>

#include "Point.hpp"
#include "../../gui/include/Drawable.hpp"


#define ANGLE_STEP 20

namespace Shape {
    
    const uint16_t S_TRIANGLE_S = 50;
    const uint16_t S_TRIANGLE_H = sqrt(S_TRIANGLE_S * S_TRIANGLE_S * 2);
    const uint16_t M_TRIANGLE_H = 2 * S_TRIANGLE_S;
    const uint16_t M_TRIANGLE_S = sqrt(M_TRIANGLE_H * M_TRIANGLE_H / 2);
    const uint16_t L_TRIANGLE_S = M_TRIANGLE_H;
    const uint16_t L_TRIANGLE_H = M_TRIANGLE_S * 2;
    const uint16_t PARALLELOGRAM_WIDTH = sqrt(S_TRIANGLE_S * S_TRIANGLE_S / 2);
    
    
    
    class Polygon : public GUI::Drawable, public GUI::Observable {
        
        protected:
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
             * @param color Color of the polygon.
             */
            Polygon(MLV_Color color);
            
            /**
             * Destructor
             */
            virtual ~Polygon() = default;
            
            /**
             * Update the center of mass of the polygon according to its points.
             */
            void updateCenter();
            
            
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
            [[nodiscard]]
            virtual bool contains(uint16_t x, uint16_t y) const = 0;
            
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
