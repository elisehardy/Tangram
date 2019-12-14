#ifndef UPDATABLE_HPP
#define UPDATABLE_HPP

#include "Engine.hpp"
#include "Event.hpp"


namespace tangram::game {

    class Updatable {
    public:
        virtual void update(const game::Event &event, game::Engine &engine) = 0;
    };
}

#endif // UPDATABLE_HPP
