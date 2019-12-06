#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "../../game/include/Engine.hpp"
#include "../../game/include/Event.hpp"


namespace tangram::gui {
    
    class Observable {
        public:
            virtual void update(const game::Event &event, game::Engine &engine) = 0;
    };
}

#endif // OBSERVABLE_HPP
