#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "../../game/include/Engine.hpp"
#include "../../game/include/Event.hpp"


namespace GUI {
    
    class Observable {
        public:
            virtual void update(const Game::Event &event, Game::Engine &engine) = 0;
    };
}

#endif // OBSERVABLE_HPP
