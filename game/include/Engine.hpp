#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <utility>
#include <cstdint>

#include <MLV/MLV_window.h>
#include <MLV/MLV_time.h>

#include "../../game/include/Event.hpp"


namespace tangram::state {
    class StateAbstract;
}

namespace tangram::game {
    
    const uint16_t WIDTH = 1600;
    const uint16_t HEIGHT = 900;
    
    
    
    class Engine {
        private:
            std::vector<state::StateAbstract *> states;
            bool running;
        
        public:
            void init();
            void cleanup();
            void pushState(state::StateAbstract *state);
            void popState();
            void update(const game::Event &even);
            void draw();
            bool isRunning();
            void stop();
    };
}

#endif // ENGINE_HPP
