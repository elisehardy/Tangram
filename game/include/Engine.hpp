#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <utility>
#include <cstdint>

#include <MLV/MLV_window.h>

class State;


namespace Tangram::Game {
    
    const uint16_t WIDTH = 800;
    const uint16_t HEIGHT = 800;
    
    class Engine {
        private:
            std::vector<State *> states;
            bool running;
    
        public:
            void init();
            void cleanup();
            void pushState(State *state);
            void popState();
            void handleEvents();
            void update();
            void draw();
            bool over();
    };
};

#endif // ENGINE_HPP
