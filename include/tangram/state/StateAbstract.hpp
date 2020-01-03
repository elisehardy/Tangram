#ifndef STATE_HPP
#define STATE_HPP

#include <tangram/game/Event.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/gui/Drawable.hpp>


namespace tangram::game {
    class Engine;
}

namespace tangram::state {
    
    class StateAbstract : public gui::Drawable, public game::Updatable {
        protected:
            StateAbstract() = default;
        
        public:
            virtual void init() = 0;
            virtual void cleanup() = 0;
            virtual void pause() = 0;
            virtual void resume() = 0;
    };
}

#endif // STATE_HPP
