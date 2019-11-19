#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <cstdint>
#include <vector>
#include <algorithm>
#include <MLV/MLV_color.h>
#include <MLV/MLV_shape.h>

#include "Point.hpp"


#define ANGLE_STEP 20
#define ANGLE_STEP_PER_CYCLE 360 / ANGLE_STEP

namespace Tangram::Shape {
    
    typedef enum {
        SMALL = 1,
        MEDIUM = SMALL * 2,
        LARGE = MEDIUM * 2
    } Size;
    
    
    
    class Polygon {
        
        private:
            Point center;    /**< Coordinates of the center of the shape. */
            uint8_t angle;   /**< Angle of the shape. */
            Size size;       /**< Size of the shape. */
            MLV_Color color; /**< Color of the shape. */
            
            /**
             * Polygon's default constructor.
             *
             * @param x X coordinate of the center of the polygon.
             * @param y Y coordinate of the center of the polygon.
             * @param angle Angle of the polygon.
             * @param size Size of the polygon.
             * @param color Color of the polygon.
             */
            Polygon(uint8_t x, uint8_t y, uint8_t angle, Size size, MLV_Color color);
            
            /**
             * Polygon's default constructor.
             *
             * @param P Center of the polygon.
             * @param angle Angle of the polygon.
             * @param size Size of the polygon.
             * @param color Color of the polygon.
             */
            Polygon(Point center, uint8_t angle, Size size, MLV_Color color);
            
            /**
             * Destructor
             */
            virtual ~Polygon() = 0;
            
            /**
             * @returns A vector of the points representing the polygon.
             */
            virtual std::vector <Point> getPoints() const = 0;
            
            /**
             * This method is called at the end of Polygon's constructor.
             *
             * It can be used to update others field added by Polygon's, subclasses.
             */
            virtual void init();
            
            /**
             * This method is called by methods updating any of the *x*, *y* or
             * *angle* fields of the polygon.
             *
             * It can be used to update others field added Polygon's subclasses.
             */
            virtual void update() = 0;
            
            /**
             * Check if the Polygon contains the point p;
             *
             * @param p Point checked against the Polygon.
             *
             * @return true if the Point is inside the Polygon, false otherwise.
             */
            virtual bool contains(const Point &p) const = 0;
            
            /**
             * Check if the Polygon contains the point p;
             *
             * @param x X coordinate of the Point checked against the Polygon.
             * @param y Y coordinate of the Point checked against the Polygon.
             *
             * @return true if the Point is inside the Polygon, false otherwise.
             */
            virtual bool contains(uint16_t x, uint16_t y) const = 0;
        
        protected:
            
            /**
             * @returns The points corresponding to the center of the polygon.
             */
            Point getCenter() const;
            /**
             * @returns The angle of the polygon.
             */
            uint8_t getAngle() const;
            
            /**
             * @returns The size of the polygon.
             */
            Size getSize() const;
        
        public:
            
            /**
             * Return whether two Polygons are equal or not by checking if their
             * set of points is the same.
             *
             * @param other Other Polygon to compare with.
             * @return true if the Polygon are equals, false otherwise.
             */
            bool operator==(const Polygon &other) const;
            
            /**
             * Move the center of the polygon to the new coordinates.
             *
             * @param x X coordinate of the new center.
             * @param y Y coordinate of the new center.
             */
            void move(uint16_t x, uint16_t y);
            
            /**
             * Move the center of the polygon to the new coordinates.
             *
             * @param P coordinates of the new center.
             */
            void move(const Point &p);
            
            /**
             * Move the center of the polygon to the new coordinates.
             *
             * @param p Point corresponding to the new coordinate.
             */
            void move(Point p);
            
            /**
             * Rotate the shape by n step.
             *
             * @param n Number of step to rotate the polygon.
             */
            void rotate(int8_t n);
            
            /**
             * Draw this polygon on the screen.
             */
            void draw() const;
    };
};

#endif //POLYGON_HPP
