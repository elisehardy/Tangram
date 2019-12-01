#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <utility>
#include <cstdint>

#include <MLV/MLV_window.h>
#include <MLV/MLV_time.h>

#include "../../game/include/Event.hpp"
#include "../../state/include/StateAbstract.hpp"


namespace Game {
    
    const uint16_t WIDTH = 1200;
    const uint16_t HEIGHT = 600;
    
    
    
    class Engine {
        private:
            std::vector<State::StateAbstract *> states;
            bool running;
        
        public:
            void init();
            void cleanup();
            void pushState(State::StateAbstract *state);
            void popState();
            void update(const Game::Event &even);
            void draw();
            bool isRunning();
            void stop();
    };
};

#endif // ENGINE_HPP
