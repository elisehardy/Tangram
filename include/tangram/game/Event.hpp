/** @file Event.hpp
 *
 *  @brief ***Event***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>

#include <MLV/MLV_event.h>

#include <tangram/geometry/Point.hpp>


namespace tangram::game {
    
    /**
     * Store the inputs of the user.
     */
    class Event {
        private:
            /**
             * Make the constructor private since the static factory get() should be used to get the current Event.
             */
            Event(MLV_Event type, MLV_Keyboard_button symbol, MLV_Keyboard_modifier mode, const char *text,
                  geometry::Point16 mousePos, MLV_Mouse_button mouseButton, MLV_Button_state state);
        
        public:
            const MLV_Event type;               /**< Type of the event. */
            const MLV_Keyboard_button symbol;   /**< Key pressed or released. */
            const MLV_Keyboard_modifier mode;   /**< Mode the keyboard was in when the key was pressed or released. */
            const char *text;                   /**< Text from an input box. */
            const geometry::Point16 mousePos;   /**< Current mouse's position. */
            const MLV_Mouse_button mouseButton; /**< Button of the mouse pressed or released. */
            const MLV_Button_state state;       /**< Whether the key/button was pressed or released */
            
            /**
             * Return an instance of Event containing the last user's input.
             *
             * Appart from mousePos, which is always set, different fields are set according to *type* :
             *      * MLV_NONE : none
             *      * MLV_KEY : symbol, mode, state
             *      * MLV_INPUT_BOX : text
             *      * MLV_MOUSE_BUTTON : mouseButton, state
             *
             * @return The instance of Event generated.
             */
            static Event get();
            
            friend std::ostream &operator<<(std::ostream &os, const Event &event);
    };
}

#endif // EVENT_HPP
