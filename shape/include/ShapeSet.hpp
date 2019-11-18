#ifndef SHAPESET_HPP
#define SHAPESET_HPP

#include <vector>
#include <algorithm>

#include "Polygon.hpp"


namespace Tangram::Shape {
    
    class ShapeSet : private std::vector<Polygon> {
        
        public:
            
            using std::vector<Polygon>::vector;
            
            /**
            * Return whether two Sets are equal or not by checking if their
            * Polygon are the same.
            *
            * @param other Other Set to compare with.
            * @return true if the Sets are equal, false otherwise.
            */
            bool operator==(const Set &other) const;
            
            /**
             * Draw this set on the screen.
             */
            void draw() const;
            
            /**
             * Returns the index corresponding to the last element of the Set
             * containing p.
             *
             * @param p Point checked against the Set.
             *
             * @return The index of the last Polygon in the Set containing p,
             * -1 if no Polygon contains the point.
             */
            int8_t indexFromPoint(Point &p) const;
            
            /**
             * Returns the index corresponding to the last element of the Set
             * containing the Point of coordinates *(x, y)*.
             *
             * @param x X coordinate of the Point checked against the Set.
             * @param y Y coordinate of the Point checked against the Set.
             *
             * @return The index of the last Polygon in the Set containing the point,
             * -1 if no Polygon contains the point.
             */
            int8_t indexFromPoint(uint16_t x, uint16_t y) const;
    };
};

#endif // SHAPESET_HPP
