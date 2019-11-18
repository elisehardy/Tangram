#ifndef STATE_HPP
#define STATE_HPP

#include "Engine.hpp"


namespace Tangram::Game {
    
    class State {
        private:
            /**
             * Destructor
             */
            virtual ~State() = 0;
        
        public:
            virtual void init() = 0;
            virtual void cleanup() = 0;
            virtual void pause() = 0;
            virtual void resume() = 0;
            virtual void handleEvent(Engine *game) = 0;
            virtual void update(Engine *game) = 0;
            virtual void draw(Engine *game) = 0;
            
            void changeState(Engine *engine, State *state);
    };
};

#endif // STATE_HPP
