#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <utility>
#include <cstdint>

#include <MLV/MLV_window.h>
#include <MLV/MLV_window.h>

#include "../../state/include/StateAbstract.hpp"

namespace Tangram::Game {
    
    const uint16_t WIDTH = 800;
    const uint16_t HEIGHT = 800;
    
    class Engine {
        private:
            std::vector<Tangram::State::StateAbstract*> states;
            bool running;
    
        public:
            void init();
            void cleanup();
            void pushState(Tangram::State::StateAbstract*state);
            void popState();
            void handleEvents();
            void update();
            void draw();
            bool over();
    };
};

#endif // ENGINE_HPP
