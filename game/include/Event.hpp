#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>

#include <MLV/MLV_event.h>

#include "../../geometry/include/Point.hpp"


namespace tangram::game {
    
    class Event {
        private:
            Event(MLV_Event t_type, MLV_Keyboard_button t_symbol, MLV_Keyboard_modifier t_modifier, const char *t_text,
                  geometry::Point16 t_mousePos, MLV_Mouse_button t_mouseButton, MLV_Button_state t_state);
        
        public:
            const MLV_Event type;
            const MLV_Keyboard_button symbol;
            const MLV_Keyboard_modifier modifier;
            const char *text;
            const geometry::Point16 mousePos;
            const MLV_Mouse_button mouseButton;
            const MLV_Button_state state;
            
            static Event get();
            
            friend std::ostream &operator<<(std::ostream &os, const Event &event);
    };
}

#endif // EVENT_HPP
