#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <unordered_map>

#include <tangram/game/Engine.hpp>
#include <tangram/game/Event.hpp>
#include <tangram/game/InputState.hpp>


namespace tangram::game {
    
    /**
     * Interface for updatable elements.
     */
    class Updatable {
        
        private:
            /**
             * Reset every keys / buttons by calling their reset() method.
             */
            void reset();
        
        protected:
            bool hovered = false; /**< Whether this element if hovered. */
            bool enabled = true;  /**< Whether this element is enabled. */
            /** InputState corresponding to the three mouse's buttons. */
            std::unordered_map<MLV_Mouse_button, InputState> buttons;
            /** InputState corresponding to every keyboard's keys. */
            std::unordered_map<MLV_Keyboard_button, InputState> keys;
            
            /**
             * Constructor.
             */
            Updatable();
            
            /**
             * Destructor.
             */
            virtual ~Updatable() = default;
            
        public:
            
            /**
             * This method should be implemented by inheriting classes.
             *
             * This implementation will set every member according to the 'hovered' and 'enabled' fields. A good use is
             * to set these fields in your overriding method and call the parent method. You will then be able to use
             * every field for specific actions after the call to the parents method.
             *
             * Nothing will be done if 'enabled' is false.
             *
             * @param event An instance of Event.
             * @param engine The instance of Engine corresponding to the game.
             *
             * @return A boolean telling whether the calling method should stop update other elements. For instance, it
             * can be useful if the implementation modify engine in a way that call to update on other elements could
             * cause segfault.
             */
            virtual bool update(const game::Event &event, game::Engine &engine);
            
            /**
             * @return true if this element is hovered, false otherwise.
             */
            [[nodiscard]] bool isHovered() const;
        
            /**
             * @return true if this element is enabled, false otherwise.
             */
            [[nodiscard]] bool isEnable() const;
            
            /**
             * Enable this element.
             */
            void enable();
        
            /**
             * Disable this element.
             */
            
            void disable();
        
            ////////////////////////////////////////////////////////////////////
            ////////////////////////// KEYBOARD'S KEY //////////////////////////
            ////////////////////////////////////////////////////////////////////
            
            /**
             * @param key Key from which the InputState will be retrieved.
             *
             * @return InputState corresponding to 'key'.
             */
            [[nodiscard]] InputState getKeyInputState(MLV_Keyboard_button key) const;
            
            /**
             * @param key Key that will be checked.
             *
             * @return true if 'key' has been pressed, false otherwise.
             */
            [[nodiscard]] bool isKeyPressed(MLV_Keyboard_button key) const;
        
            /**
             * @param key Key that will be checked.
             *
             * @return true if 'key' is held, false otherwise.
             */
            [[nodiscard]] bool isKeyHeld(MLV_Keyboard_button key) const;
        
            /**
             * @param key Key that will be checked.
             *
             * @return true if 'key' has been released, false otherwise.
             */
            [[nodiscard]] bool isKeyReleased(MLV_Keyboard_button key) const;
        
            /**
             * @param key Key that will be checked.
             *
             * @return true if 'key' has been clicked, false otherwise.
             */
            [[nodiscard]] bool isKeyClicked(MLV_Keyboard_button key) const;
        
            /**
             * @param key Which key's pressed point will be retrieved.
             *
             * @return The pressed Point corresponding to 'key'.
             */
            [[nodiscard]] geometry::Point16 getKeyPressedPoint(MLV_Keyboard_button key) const;
            
            ////////////////////////////////////////////////////////////////////
            ////////////////////////// MOUSE'S BUTTON //////////////////////////
            ////////////////////////////////////////////////////////////////////
        
            /**
             * @param button Button from which the InputState will be retrieved.
             *
             * @return InputState corresponding to 'button'.
             */
            [[nodiscard]] InputState getButtonInputState(MLV_Mouse_button button) const;
        
            /**
             * @param button Button that will be checked.
             *
             * @return true if 'button' has been pressed, false otherwise.
             */
            [[nodiscard]] bool isButtonPressed(MLV_Mouse_button button) const;
        
            /**
             * @param button Button that will be checked.
             *
             * @return true if 'button' is held, false otherwise.
             */
            [[nodiscard]] bool isButtonHeld(MLV_Mouse_button button) const;
        
            /**
             * @param button Button that will be checked.
             *
             * @return true if 'button' has been released, false otherwise.
             */
            [[nodiscard]] bool isButtonReleased(MLV_Mouse_button button) const;
        
            /**
             * @param button Button that will be checked.
             *
             * @return true if 'button' has been clicked, false otherwise.
             */
            [[nodiscard]] bool isButtonClicked(MLV_Mouse_button button) const;
        
            /**
             * @param button Which button's pressed point will be retrieved.
             *
             * @return The pressed Point corresponding to 'button'.
             */
            [[nodiscard]] geometry::Point16 getButtonPressedPoint(MLV_Mouse_button button) const;
        
            ////////////////////////////////////////////////////////////////////
            //////////////////////// RIGHT BUTTON'S SHORTCUTS //////////////////
            ////////////////////////////////////////////////////////////////////
            
            /**
             * @return true if the mouse's right button has been pressed, false otherwise.
             */
            [[nodiscard]] bool isRightPressed() const;
        
            /**
             * @return true if the mouse's right button is held, false otherwise.
             */
            [[nodiscard]] bool isRightHeld() const;
        
            /**
             * @return true if the mouse's right button has been released, false otherwise.
             */
            [[nodiscard]] bool isRightReleased() const;
        
            /**
             * @return true if the mouse's right button has been clicked, false otherwise.
             */
            [[nodiscard]] bool isRightClicked() const;
        
            /**
             * @return The pressed Point of the mouse's right button.
             */
            [[nodiscard]] geometry::Point16 getRightPressedPoint() const;
        
            ////////////////////////////////////////////////////////////////////
            //////////////////////// LEFT BUTTON'S SHORTCUTS ///////////////////
            ////////////////////////////////////////////////////////////////////
        
            /**
            * @return true if the mouse's left button has been pressed, false otherwise.
            */
            [[nodiscard]] bool isLeftPressed() const;
        
            /**
             * @return true if the mouse's left button is held, false otherwise.
             */
            [[nodiscard]] bool isLeftHeld() const;
        
            /**
             * @return true if the mouse's left button has been released, false otherwise.
             */
            [[nodiscard]] bool isLeftReleased() const;
        
            /**
             * @return true if the mouse's left button has been clicked, false otherwise.
             */
            [[nodiscard]] bool isLeftClicked() const;
        
            /**
             * @return The pressed Point of the mouse's left button.
             */
            [[nodiscard]] geometry::Point16 getLeftPressedPoint() const;
    };
}

#endif // OBSERVABLE_HPP
