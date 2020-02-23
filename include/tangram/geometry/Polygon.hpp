/** @file Polygon.hpp
 *
 *  @brief ***Polygon***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <fstream>

#include <MLV/MLV_color.h>

#include <tangram/game/Updatable.hpp>
#include <tangram/geometry/Triangle.hpp>
#include <tangram/gui/Drawable.hpp>


namespace tangram::geometry {
    
    /**
     * Represent a Polygon composed of multiple Triangle.
     */
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
        
            Polygon(const std::vector<Triangle> &triangles, MLV_Color color);
        
            Polygon(const Polygon &) = default;
        
            Polygon(Polygon &&) = default;
        
            Polygon &operator=(const Polygon &) = default;
            
            Polygon &operator=(Polygon &&) = default;
            
            ///////////////////////// GETTERS & SETTERS ////////////////////////
            
            [[nodiscard]] std::vector<Point16> getPoints() const;
            
            [[nodiscard]] int16_t getCurrentRotation() const;
            
            void setCurrentRotation(int16_t currentRotation);
            
            void setColor(MLV_Color color);
            
            ///////////////////////// TRANSFORMATIONS //////////////////////////
            
            /**
             * Translate this Polygon by the given vector.
             *
             * @param v Vector of translation.
             *
             * @return A reference to this.
             */
            Polygon &translate(const Vector16 &v);
        
            /**
             * Translate this Polygon by the given coordinates.
             *
             * @param x Translation on X.
             * @param y Translation on Y.
             *
             * @return A reference to this.
             */
            Polygon &translate(int16_t x, int16_t y);
        
            /**
             * Scale this Polygon by the given vector.
             *
             * @param v Scaling vector.
             *
             * @return A reference to this.
             */
            Polygon &scale(const VectorD &v);
        
            /**
             * Translate this Polygon by the given coordinates.
             *
             * @param x Scale on X.
             * @param y Scale on Y.
             *
             * @return A reference to this.
             */
            Polygon &scale(double x, double y);
        
            /**
             * Translate this Polygon by the given factor.
             *
             * @param factor Scaling factor.
             *
             * @return A reference to this.
             */
            Polygon &scale(double factor);
        
            /**
             * Rotate this Polygon by the given degrees around its center.
             *
             * @param n Degrees of rotation.
             *
             * @return A reference to this.
             */
            Polygon &rotate(int16_t n);
            
            ////////////////////////////// OTHERS //////////////////////////////
            
            friend std::ostream &operator<<(std::ostream &os, const Polygon &p);
            
            /**
             * Check whether a point is contained inside a Polygon.
             *
             * @param p Point to be checked.
             *
             * @return true if *p* is inside this Polygon, false otherwise.
             */
            [[nodiscard]] bool contains(const Point16 &p) const;
            
            /**
             * Add triangles to this Polygon.
             *
             * @param triangles Triangles to be added.
             */
            void add(const std::vector<Triangle> &triangles);
        
            /**
             * Add a triangle to this Polygon.
             *
             * @param t Triangle to be added.
             */
            void add(const Triangle &t);
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // POLYGON_HPP
