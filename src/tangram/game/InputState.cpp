#include <tangram/game/InputState.hpp>


namespace tangram::game {
    
    void InputState::reset() {
        this->released = false;
        this->pressed = false;
        this->clicked = false;
    }
    
    
    std::ostream &operator<<(std::ostream &os, const InputState &inputState) {
        os << "Pressed:  " << (inputState.pressed ? "true" : "false") << std::endl;
        os << "Released: " << (inputState.released ? "true" : "false") << std::endl;
        os << "Clicked:  " << (inputState.clicked ? "true" : "false") << std::endl;
        os << "Held:     " << (inputState.held ? "true" : "false") << std::endl;
        os << "Point:    " << inputState.pressedPoint;
        return os;
    }
}
