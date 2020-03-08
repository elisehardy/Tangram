/** @file Shape.hpp
 *
 *  @brief ***Shape***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>
#include <string>

#include <tangram/game/Updatable.hpp>
#include <tangram/gui/Drawable.hpp>
#include <tangram/geometry/Polygon.hpp>


namespace tangram::geometry {
    
    /**
     * Represent a Shape composed of multiple Polygon.
     */
    class Shape : public gui::Drawable {
        
        private:
            std::vector<Polygon> polygons = {};
        
        public:
            
            ///////////////////// CONSTRUCTOR & DESTRUCTOR /////////////////////
            
            Shape() = default;
            
            static Shape load(const std::string &path);
            
            static Shape square();
            
            ///////////////////////// TRANSFORMATIONS //////////////////////////
            
            /**
             * Translate this Shape by the given vector.
             *
             * @param v Vector of translation.
             *
             * @return A reference to this.
             */
            Shape &translate(const Vector16 &v);
            
            /**
             * Translate this Shape by the given coordinates.
             *
             * @param x Translation on X.
             * @param y Translation on Y.
             *
             * @return A reference to this.
             */
            Shape &translate(int16_t x, int16_t y);
            
            /**
             * Scale this Shape by the given vector.
             *
             * @param v Scaling vector.
             *
             * @return A reference to this.
             */
            Shape &scale(const VectorD &v);
            
            /**
             * Translate this Shape by the given coordinates.
             *
             * @param x Scale on X.
             * @param y Scale on Y.
             *
             * @return A reference to this.
             */
            Shape &scale(double x, double y);
            
            /**
             * Translate this Shape by the given factor.
             *
             * @param factor Scaling factor.
             *
             * @return A reference to this.
             */
            Shape &scale(double factor);
        
            /**
             * Set the color of this Shape to the given color.
             *
             * @param color New color.
             *
             * @return A reference to this.
             */
            Shape &setColor(MLV_Color color);
            
            ///////////////////////////// OTHERS ///////////////////////////////
            
            bool operator==(const Shape &other) const;
            
            friend std::ostream &operator<<(std::ostream &os, const Shape &s);
            
            [[nodiscard]] std::vector<Point16> getPoints() const;
            
            /**
             * Ensure this Shape is inside the given bounds, moving it if necessary.
             *
             * @param lowerBound Lower bound.
             * @param upperBound Upper bound.
             */
            void ensureInbounds(Point16 lowerBound, Point16 upperBound);
            
            /**
             * Return a random polygon of this Shape.
             *
             * @return A random polygon of this Shape.
             */
            [[nodiscard]] Polygon getRandomPolygon() const;
            
            /**
             * Add a Polygon to this Shape.
             *
             * @param polygon Polygon to be added.
             */
            void addPolygon(const Polygon &polygon);
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // SHAPE_HPP
