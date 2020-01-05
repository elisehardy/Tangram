#ifndef TANGRAM_INPUT_HPP
#define TANGRAM_INPUT_HPP

#include <tangram/geometry/Point.hpp>


namespace tangram::game {
    
    struct InputState {
        geometry::Point16 pressedPoint = { 0, 0 };
        bool released = false;
        bool pressed = false;
        bool clicked = false;
        bool held = false;
        
        InputState() = default;
    
        friend std::ostream &operator<<(std::ostream &os, const InputState &inputState);
        
        void reset();
    };
}

#endif //TANGRAM_INPUT_HPP
