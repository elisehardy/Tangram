#ifndef SHAPESET_HPP
#define SHAPESET_HPP

#include <vector>
#include <algorithm>

#include "Polygon.hpp"
#include "Triangle.hpp"
#include "Square.hpp"


namespace Shape {
    
    class ShapeSet : public GUI::Drawable, public GUI::Observable, public std::vector<Polygon *> {
        public:
            
            using std::vector<Polygon *>::vector;
            
            ShapeSet(Point point);
            
            ShapeSet(std::string path);
            
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
            void update(const Game::Event &event, Game::Engine &engine) override;
    };
};

#endif // SHAPESET_HPP
