#include <tangram/game/Updatable.hpp>


namespace tangram::game {
    
    Updatable::Updatable() {
        MLV_Keyboard_button b;
        
        for (uint64_t i = MLV_KEYBOARD_FIRST; i < MLV_KEYBOARD_LAST; i++) {
            b = MLV_Keyboard_button(i);
            this->keyPressed[b] = false;
            this->keyHeld[b] = false;
            this->keyReleased[b] = false;
            this->keyClicked[b] = false;
            this->keyPressedPoint[b] = { 0, 0 };
        }
    }
    
    
    void Updatable::reset() {
        MLV_Keyboard_button b;
        
        for (uint64_t i = MLV_KEYBOARD_FIRST; i < MLV_KEYBOARD_LAST; i++) {
            b = MLV_Keyboard_button(i);
            this->keyPressed[b] = false;
            this->keyReleased[b] = false;
            this->keyClicked[b] = false;
        }
        
        this->leftPressed = false;
        this->leftReleased = false;
        this->leftClicked = false;
        
        this->rightPressed = false;
        this->rightReleased = false;
        this->rightClicked = false;
        
        this->middlePressed = false;
        this->middleReleased = false;
        this->middleClicked = false;
    }
    
    
    void Updatable::update(const game::Event &event, game::Engine &engine) {
        bool leftButton = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_LEFT;
        bool rightButton = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_RIGHT;
        bool middleButton = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_MIDDLE;
        bool key = event.type == MLV_KEY;
        
        this->reset();
        
        if (this->hovered && leftButton && event.state == MLV_PRESSED) {
            this->leftPressedPoint = geometry::Point16(event.mousePos);
            this->leftPressed = true;
            this->leftHeld = true;
        }
        else if (this->leftHeld && leftButton && event.state == MLV_RELEASED) {
            if (this->hovered) {
                this->leftReleased = true;
                if (this->leftHeld) {
                    this->leftClicked = true;
                }
            }
            this->leftHeld = false;
        }
        
        if (this->hovered && rightButton && event.state == MLV_PRESSED) {
            this->rightPressedPoint = geometry::Point16(event.mousePos);
            this->rightPressed = true;
            this->rightHeld = true;
        }
        else if (this->rightHeld && rightButton && event.state == MLV_RELEASED) {
            if (this->hovered) {
                this->rightReleased = true;
                if (this->rightHeld) {
                    this->rightClicked = true;
                }
            }
            this->rightHeld = false;
        }
        
        if (this->hovered && middleButton && event.state == MLV_PRESSED) {
            this->middlePressedPoint = geometry::Point16(event.mousePos);
            this->middlePressed = true;
            this->middleHeld = true;
        }
        else if (this->middleHeld && middleButton && event.state == MLV_RELEASED) {
            if (this->hovered) {
                this->middleReleased = true;
                if (this->middleHeld) {
                    this->middleClicked = true;
                }
            }
            this->middleHeld = false;
        }
        
        if (this->hovered && key && event.state == MLV_PRESSED) {
            this->keyPressedPoint[event.symbol] = geometry::Point16(event.mousePos);
            this->keyPressed[event.symbol] = true;
            this->keyHeld[event.symbol] = true;
        }
        else if (this->keyHeld[event.symbol] && key && event.state == MLV_RELEASED) {
            if (this->hovered) {
                this->keyReleased[event.symbol] = true;
                if (this->keyHeld[event.symbol]) {
                    this->keyClicked[event.symbol] = true;
                }
            }
            this->keyHeld[event.symbol] = false;
        }
    }
    
    
    bool Updatable::isHovered() const {
        return hovered;
    }
    
    
    bool Updatable::isLeftPressed() const {
        return leftPressed;
    }
    
    
    bool Updatable::isLeftHeld() const {
        return leftHeld;
    }
    
    
    bool Updatable::isLeftReleased() const {
        return leftReleased;
    }
    
    
    bool Updatable::isLeftClicked() const {
        return leftClicked;
    }
    
    
    geometry::Point16 Updatable::getLeftPressedPoint() const {
        return leftPressedPoint;
    }
    
    
    bool Updatable::isRightPressed() const {
        return rightPressed;
    }
    
    
    bool Updatable::isRightHeld() const {
        return rightHeld;
    }
    
    
    bool Updatable::isRightReleased() const {
        return rightReleased;
    }
    
    
    bool Updatable::isRightClicked() const {
        return rightClicked;
    }
    
    
    geometry::Point16 Updatable::getRightPressedPoint() const {
        return rightPressedPoint;
    }
    
    
    bool Updatable::isMiddlePressed() const {
        return middlePressed;
    }
    
    
    bool Updatable::isMiddleHeld() const {
        return middleHeld;
    }
    
    
    bool Updatable::isMiddleReleased() const {
        return middleReleased;
    }
    
    
    bool Updatable::isMiddleClicked() const {
        return middleClicked;
    }
    
    
    geometry::Point16 Updatable::getMiddlePressedPoint() const {
        return middlePressedPoint;
    }
    
    
    bool Updatable::isKeyPressed(MLV_Keyboard_button key) const {
        return this->keyPressed.at(key);
    }
    
    
    bool Updatable::isKeyHeld(MLV_Keyboard_button key) const {
        return this->keyHeld.at(key);
    }
    
    
    bool Updatable::isKeyReleased(MLV_Keyboard_button key) const {
        return this->keyReleased.at(key);
    }
    
    
    bool Updatable::isKeyClicked(MLV_Keyboard_button key) const {
        return this->keyClicked.at(key);
    }
    
    
    geometry::Point16 Updatable::getKeyPressedPoint(MLV_Keyboard_button key) const {
        return this->keyPressedPoint.at(key);
    }
}
