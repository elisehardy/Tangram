/** @file Triangle.hpp
 *
 *  @brief ***Triangle***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <MLV/MLV_color.h>

#include <tangram/geometry/Point.hpp>


namespace tangram::geometry {
    
    /**
     * Represent a Triangle composed of 3 points.
     */
    class Triangle {
        
        private:
            Point16 p1;
            Point16 p2;
            Point16 p3;
        
        public:
            static constexpr int16_t ANGLE_STEP = 3;
            static constexpr int16_t SIDE = 100;
            static const int16_t HYPOTENUSE;
            static const int16_t HEIGHT;
            
            explicit Triangle(const Point16 &offset);
            
            Triangle(Point16 p1, Point16 p2, Point16 p3);
            
            friend std::ostream &operator<<(std::ostream &os, const Triangle &t);
        
            /**
             * Translate this Triangle by the given vector.
             *
             * @param v Vector of translation.
             *
             * @return A reference to this.
             */
            [[nodiscard]] Triangle translate(const Vector16 &v) const;
        
            /**
             * Translate this Triangle by the given coordinates.
             *
             * @param x Translation on X.
             * @param y Translation on Y.
             *
             * @return A reference to this.
             */
            [[nodiscard]] Triangle translate(int16_t x, int16_t y) const;
        
            /**
             * Scale this Triangle by the given vector.
             *
             * @param v Scaling vector.
             *
             * @return A reference to this.
             */
            [[nodiscard]] Triangle scale(const VectorD &v) const;
        
            /**
             * Translate this Triangle by the given coordinates.
             *
             * @param x Scale on X.
             * @param y Scale on Y.
             *
             * @return A reference to this.
             */
            [[nodiscard]] Triangle scale(double x, double y) const;
        
            /**
             * Translate this Triangle by the given factor.
             *
             * @param factor Scaling factor.
             *
             * @return A reference to this.
             */
            [[nodiscard]] Triangle scale(double factor) const;
        
            /**
             * Rotate this Polygon by the given degrees around center.
             *
             * @param angle Angle of rotation in degrees.
             * @param center Center of rotation
             *
             * @return A reference to this.
             */
            [[nodiscard]] Triangle rotate(int16_t angle, const PointD &center) const;
        
            /**
             * Check whether a point is contained inside this Triangle.
             *
             * @param p Point to be checked.
             *
             * @return true if *p* is inside this Polygon, false otherwise.
             */
            [[nodiscard]] bool contains(const Point16 &p) const;
            
            [[nodiscard]] std::vector<Point16> getPoints() const;
            
            void draw(MLV_Color color) const;
    };
}

#endif // TRIANGLE_HPP
