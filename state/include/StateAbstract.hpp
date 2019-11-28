#ifndef STATE_HPP
#define STATE_HPP

#include "../../game/include/Event.hpp"
//#include "../../game/include/Engine.hpp"


namespace Game {
    class Engine;
}

namespace State {
    
    class StateAbstract {
        protected:
            /**
             * Making constructor protected since States will be singletons.
             */
            StateAbstract() = default;
        
        public:
            virtual void init() = 0;
            virtual void cleanup() = 0;
            virtual void pause() = 0;
            virtual void resume() = 0;
            virtual void update(const Game::Event &event, Game::Engine &engine) = 0;
            virtual void draw() = 0;
    };
};

#endif // STATE_HPP
