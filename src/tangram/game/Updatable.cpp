#include <tangram/game/Updatable.hpp>


namespace tangram::game {
    
    Updatable::Updatable() {
        MLV_Keyboard_button k;
        
        for (uint64_t i = MLV_KEYBOARD_FIRST; i < MLV_KEYBOARD_LAST; i++) {
            k = MLV_Keyboard_button(i);
            this->keys[k] = InputState();
        }
        
        this->buttons[MLV_BUTTON_LEFT] = InputState();
        this->buttons[MLV_BUTTON_RIGHT] = InputState();
        this->buttons[MLV_BUTTON_MIDDLE] = InputState();
    }
    
    
    void Updatable::reset() {
        for (auto &[_, v]: this->buttons) {
            v.reset();
        }
        for (auto &[_, v]: this->keys) {
            v.reset();
        }
    }
    
    
    void Updatable::update(const game::Event &event, game::Engine &engine) {
        if (!this->enabled) {
            return;
        }
        
        bool mouse = event.type == MLV_MOUSE_BUTTON;
        bool key = event.type == MLV_KEY;
        
        this->reset();
        
        // Moused
        if (mouse && this->hovered && event.state == MLV_PRESSED) { // Pressed
            this->buttons[event.mouseButton].pressedPoint = geometry::Point16(event.mousePos);
            this->buttons[event.mouseButton].pressed = true;
            this->buttons[event.mouseButton].held = true;
        }
        else if (mouse && this->buttons[event.mouseButton].held && event.state == MLV_RELEASED) { // Released
            if (this->hovered) {
                this->buttons[event.mouseButton].released = true;
                if (this->buttons[event.mouseButton].held) {
                    this->buttons[event.mouseButton].clicked = true;
                }
            }
            this->buttons[event.mouseButton].held = false;
        }
        
        // Keyboard
        if (key && this->hovered && event.state == MLV_PRESSED) { // Pressed
            this->keys[event.symbol].pressedPoint = geometry::Point16(event.mousePos);
            this->keys[event.symbol].pressed = true;
            this->keys[event.symbol].held = true;
        }
        else if (key && this->keys[event.symbol].held && event.state == MLV_RELEASED) { // Released
            if (this->hovered) {
                this->keys[event.symbol].released = true;
                if (this->keys[event.symbol].held) {
                    this->keys[event.symbol].clicked = true;
                }
            }
            this->keys[event.symbol].held = false;
        }
    }
    
    
    bool Updatable::isHovered() const {
        return hovered;
    }
    
    ////////////////////////////// KEYBOARD'S KEY //////////////////////////////
    
    InputState Updatable::getKeyInputState(MLV_Keyboard_button key) const {
        return InputState(this->keys.at(key));
    }
    
    
    bool Updatable::isKeyPressed(MLV_Keyboard_button key) const {
        return this->keys.at(key).pressed;
    }
    
    
    bool Updatable::isKeyHeld(MLV_Keyboard_button key) const {
        return this->keys.at(key).held;
    }
    
    
    bool Updatable::isKeyReleased(MLV_Keyboard_button key) const {
        return this->keys.at(key).released;
    }
    
    
    bool Updatable::isKeyClicked(MLV_Keyboard_button key) const {
        return this->keys.at(key).clicked;
    }
    
    
    geometry::Point16 Updatable::getKeyPressedPoint(MLV_Keyboard_button key) const {
        return this->keys.at(key).pressedPoint;
    }
    
    ////////////////////////////// MOUSE'S BUTTON //////////////////////////////
    
    
    InputState Updatable::getButtonInputState(MLV_Mouse_button button) const {
        return InputState(this->buttons.at(button));
    }
    
    
    bool Updatable::isButtonPressed(MLV_Mouse_button button) const {
        return this->buttons.at(button).pressed;
    }
    
    
    bool Updatable::isButtonHeld(MLV_Mouse_button button) const {
        return this->buttons.at(button).held;
    }
    
    
    bool Updatable::isButtonReleased(MLV_Mouse_button button) const {
        return this->buttons.at(button).released;
    }
    
    
    bool Updatable::isButtonClicked(MLV_Mouse_button button) const {
        return this->buttons.at(button).clicked;
    }
    
    
    geometry::Point16 Updatable::getButtonPressedPoint(MLV_Mouse_button button) const {
        return this->buttons.at(button).pressedPoint;
    }
    
    //////////////////////////// RIGHT BUTTON'S SHORTCUTS //////////////////////
    
    
    bool Updatable::isRightPressed() const {
        return this->buttons.at(MLV_BUTTON_RIGHT).pressed;
    }
    
    
    bool Updatable::isRightHeld() const {
        return this->buttons.at(MLV_BUTTON_RIGHT).held;
    }
    
    
    bool Updatable::isRightReleased() const {
        return this->buttons.at(MLV_BUTTON_RIGHT).released;
    }
    
    
    bool Updatable::isRightClicked() const {
        return this->buttons.at(MLV_BUTTON_RIGHT).clicked;
    }
    
    
    geometry::Point16 Updatable::getRightPressedPoint() const {
        return this->buttons.at(MLV_BUTTON_RIGHT).pressedPoint;
    }
    
    //////////////////////////// LEFT BUTTON'S SHORTCUTS ///////////////////////
    
    
    bool Updatable::isLeftPressed() const {
        return this->buttons.at(MLV_BUTTON_LEFT).pressed;
    }
    
    
    bool Updatable::isLeftHeld() const {
        return this->buttons.at(MLV_BUTTON_LEFT).held;
    }
    
    
    bool Updatable::isLeftReleased() const {
        return this->buttons.at(MLV_BUTTON_LEFT).released;
    }
    
    
    bool Updatable::isLeftClicked() const {
        return this->buttons.at(MLV_BUTTON_LEFT).clicked;
    }
    
    
    geometry::Point16 Updatable::getLeftPressedPoint() const {
        return this->buttons.at(MLV_BUTTON_LEFT).pressedPoint;
    }
    
    
    bool Updatable::isEnable() const {
        return this->enabled;
    }
    
    
    void Updatable::enable() {
        this->enabled = true;
    }
    
    
    void Updatable::disable() {
        this->enabled = false;
    }
}
