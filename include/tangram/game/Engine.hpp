#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <cstdint>
#include <string>

#include <MLV/MLV_window.h>
#include <MLV/MLV_time.h>

#include <tangram/game/Event.hpp>


namespace tangram::state {
    class StateAbstract;
}

namespace tangram::game {
    
    static const std::string SHAPE_DIR = "../resources/shapes/";
    static const std::string FONT_DIR = "../resources/fonts/";
    
    static constexpr uint16_t WIDTH = 1200;
    static constexpr uint16_t HEIGHT = 800;
    
    
    
    class Engine {
        private:
            std::vector<state::StateAbstract *> states = {};
            bool running = false;
        
        public:
            
            void init();
            
            void cleanup();
            
            void pushState(state::StateAbstract *state);
            
            void popState();
            
            state::StateAbstract *current();
            
            void update(const game::Event &even);
            
            void draw();
            
            bool isRunning();
            
            void stop();
    };
}

#endif // ENGINE_HPP
