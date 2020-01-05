#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <unordered_map>

#include <tangram/game/Engine.hpp>
#include <tangram/game/Event.hpp>
#include <tangram/game/InputState.hpp>


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
            bool enabled = true;
            std::unordered_map<MLV_Mouse_button, InputState> buttons;
            std::unordered_map<MLV_Keyboard_button, InputState> keys;
        
        public:
            
            Updatable();
            
            virtual ~Updatable() = default;
            
            virtual void update(const game::Event &event, game::Engine &engine);
            
            [[nodiscard]] bool isHovered() const;
            
            [[nodiscard]] bool isEnable() const;
            
            void enable();
            
            void disable();
            
            ////////////////////////// KEYBOARD'S KEY //////////////////////////
            
            [[nodiscard]] InputState getKeyInputState(MLV_Keyboard_button key) const;
            
            [[nodiscard]] bool isKeyPressed(MLV_Keyboard_button key) const;
            
            [[nodiscard]] bool isKeyHeld(MLV_Keyboard_button key) const;
            
            [[nodiscard]] bool isKeyReleased(MLV_Keyboard_button key) const;
            
            [[nodiscard]] bool isKeyClicked(MLV_Keyboard_button key) const;
            
            [[nodiscard]] geometry::Point16 getKeyPressedPoint(MLV_Keyboard_button key) const;
            
            ////////////////////////// MOUSE'S BUTTON //////////////////////////
            
            [[nodiscard]] InputState getButtonInputState(MLV_Mouse_button button) const;
            
            [[nodiscard]] bool isButtonPressed(MLV_Mouse_button button) const;
            
            [[nodiscard]] bool isButtonHeld(MLV_Mouse_button button) const;
            
            [[nodiscard]] bool isButtonReleased(MLV_Mouse_button button) const;
            
            [[nodiscard]] bool isButtonClicked(MLV_Mouse_button button) const;
            
            [[nodiscard]] geometry::Point16 getButtonPressedPoint(MLV_Mouse_button button) const;
            
            //////////////////////// RIGHT BUTTON'S SHORTCUTS //////////////////
            
            [[nodiscard]] bool isRightPressed() const;
            
            [[nodiscard]] bool isRightHeld() const;
            
            [[nodiscard]] bool isRightReleased() const;
            
            [[nodiscard]] bool isRightClicked() const;
            
            [[nodiscard]] geometry::Point16 getRightPressedPoint() const;
            
            //////////////////////// LEFT BUTTON'S SHORTCUTS ///////////////////
            
            [[nodiscard]] bool isLeftPressed() const;
            
            [[nodiscard]] bool isLeftHeld() const;
            
            [[nodiscard]] bool isLeftReleased() const;
            
            [[nodiscard]] bool isLeftClicked() const;
            
            [[nodiscard]] geometry::Point16 getLeftPressedPoint() const;
    };
}

#endif // OBSERVABLE_HPP
