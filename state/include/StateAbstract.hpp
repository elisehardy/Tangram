#ifndef STATE_HPP
#define STATE_HPP

#include "../../game/include/Event.hpp"
#include "../../game/include/Updatable.hpp"

#include "../../gui/include/Drawable.hpp"

namespace tangram::game {
    class Engine;
}

namespace tangram::state {
    
    const uint16_t BUTTON_WIDTH = 140;
    const uint16_t BUTTON_HEIGTH = 50;
    const uint16_t NUMBER_BUTTON = 5;
    const uint16_t SPACE_2_BUTTON = 5;
    
    
    
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
