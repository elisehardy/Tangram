#ifndef SHAPESET_HPP
#define SHAPESET_HPP

#include <vector>
#include <algorithm>

#include "Polygon.hpp"


namespace Shape {
    
    class ShapeSet : public GUI::Drawable, private std::vector<Polygon *> {
        
        public:
            
            using std::vector<Polygon *>::vector;
            
            /**
            * Return whether two Sets are equal or not by checking if their
            * Polygon are the same.
            *
            * @param other Other Set to compare with.
            * @return true if the Sets are equal, false otherwise.
            */
            bool operator==(const ShapeSet &other) const;
            
            /**
             * Draw this set on the screen.
             */
            void draw() const override;
            
            /**
             *
             */
    };
};

#endif // SHAPESET_HPP
