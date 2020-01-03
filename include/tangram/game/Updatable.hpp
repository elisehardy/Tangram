#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <unordered_map>

#include <tangram/game/Engine.hpp>
#include <tangram/game/Event.hpp>
#include <tangram/geometry/Point.hpp>

/**
 * Interface for updatable elements.
 *
 * A button/key 'pressed' boolean is True if it has been pressed while hovering the element.
 *
 * A button/key 'held' boolean is True if it has been pressed while hovering the element. It stay True as long as the
 * button/key is held.
 *
 * A button/key 'released' boolean is True if it has been released while hovering the element, whether its 'pressed'
 * boolean is True or not.
 *
 * A button/key 'clicked' boolean is True if it has been released while hovering the element and its 'pressed' boolean
 * was True.
 *
 * Current of implementation of 'update()' will set every member according to the 'hovered' field. A good use is to set
 * 'hovered' in your overriding method and call the parent method. You will then be able to use every field for
 * specific actions.
 */
namespace tangram::game {
    
    class Updatable {
        private:
            void reset();
            
        protected:
            bool hovered = false;
            
            // Left button
            bool leftPressed = false;
            bool leftHeld = false;
            bool leftReleased = false;
            bool leftClicked = false;
            geometry::Point16 leftPressedPoint = { 0, 0 };
            
            // Right button
            bool rightPressed = false;
            bool rightHeld = false;
            bool rightReleased = false;
            bool rightClicked = false;
            geometry::Point16 rightPressedPoint = { 0, 0 };
            
            // Middle button
            bool middlePressed = false;
            bool middleHeld = false;
            bool middleReleased = false;
            bool middleClicked = false;
            geometry::Point16 middlePressedPoint = { 0, 0 };
            
            // Keyboard
            std::unordered_map<MLV_Keyboard_button, bool> keyPressed;
            std::unordered_map<MLV_Keyboard_button, bool> keyHeld;
            std::unordered_map<MLV_Keyboard_button, bool> keyReleased;
            std::unordered_map<MLV_Keyboard_button, bool> keyClicked;
            std::unordered_map<MLV_Keyboard_button, geometry::Point16> keyPressedPoint;
        
        public:
            
            Updatable();
            
            virtual void update(const game::Event &event, game::Engine &engine) = 0;
            
            [[nodiscard]] bool isHovered() const;
            
            [[nodiscard]] bool isLeftPressed() const;
            
            [[nodiscard]] bool isLeftHeld() const;
            
            [[nodiscard]] bool isLeftReleased() const;
            
            [[nodiscard]] bool isLeftClicked() const;
            
            [[nodiscard]] geometry::Point16 getLeftPressedPoint() const;
            
            [[nodiscard]] bool isRightPressed() const;
            
            [[nodiscard]] bool isRightHeld() const;
            
            [[nodiscard]] bool isRightReleased() const;
            
            [[nodiscard]] bool isRightClicked() const;
            
            [[nodiscard]] geometry::Point16 getRightPressedPoint() const;
            
            [[nodiscard]] bool isMiddlePressed() const;
            
            [[nodiscard]] bool isMiddleHeld() const;
            
            [[nodiscard]] bool isMiddleReleased() const;
            
            [[nodiscard]] bool isMiddleClicked() const;
            
            [[nodiscard]] geometry::Point16 getMiddlePressedPoint() const;
            
            [[nodiscard]] bool isKeyPressed(MLV_Keyboard_button key) const;
            
            [[nodiscard]] bool isKeyHeld(MLV_Keyboard_button key) const;
            
            [[nodiscard]] bool isKeyReleased(MLV_Keyboard_button key) const;
            
            [[nodiscard]] bool isKeyClicked(MLV_Keyboard_button key) const;
            
            [[nodiscard]] geometry::Point16 getKeyPressedPoint(MLV_Keyboard_button key) const;
    };
}

#endif // OBSERVABLE_HPP
