#ifndef EVENT_HPP
#define EVENT_HPP

#include <MLV/MLV_event.h>

#include "../../shape/include/Point.hpp"


namespace tangram::game {
    
    class Event {
        private:
            Event(MLV_Event t_type, MLV_Keyboard_button t_symbol, MLV_Keyboard_modifier t_modifier, const char *t_text,
                  shape::Point t_mousePos, MLV_Mouse_button t_mouseButton, MLV_Button_state t_state);
        
        public:
            const MLV_Event type;
            const MLV_Keyboard_button symbol;
            const MLV_Keyboard_modifier modifier;
            const char *text;
            const shape::Point mousePos;
            const MLV_Mouse_button mouseButton;
            const MLV_Button_state state;
            
            static Event get();
    };
};

#endif // EVENT_HPP
