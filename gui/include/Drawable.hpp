#ifndef MAIN_DRAWABLE_HPP
#define MAIN_DRAWABLE_HPP

#include <cstdint>

#include <MLV/MLV_all.h>

#include "../../game/include/Event.hpp"
#include "../../game/include/Engine.hpp"

#include "Observable.hpp"

namespace GUI {
    
    class Drawable: public Observable {
        public:
            
            /**
             * Draw this drawable on the screen.
             */
            virtual void draw() const = 0;
            
            void update(const Game::Event &event, Game::Engine &engine) override = 0;
    };
};

#endif // MAIN_DRAWABLE_HPP
