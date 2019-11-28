#include "../include/Event.hpp"


using namespace Game;


Event::Event(const MLV_Event t_type, const MLV_Keyboard_button t_symbol, const MLV_Keyboard_modifier t_modifier,
             const char *t_text,
             const Shape::Point t_mousePos, const MLV_Mouse_button t_mouseButton, const MLV_Button_state t_state) :
        type(t_type), symbol(t_symbol), modifier(t_modifier), text(t_text), mousePos(t_mousePos),
        mouseButton(t_mouseButton), state(t_state) {
}


Event Event::get() {
    MLV_Event type;
    MLV_Keyboard_button symbol;
    MLV_Keyboard_modifier modifier;
    char *text;
    int x, y;
    MLV_Mouse_button mouseButton;
    MLV_Button_state state;
    
    type = MLV_get_event(&symbol, &modifier, nullptr, &text, nullptr, nullptr, nullptr, &mouseButton, &state);
    if (type == MLV_MOUSE_MOTION) {
        type = MLV_NONE;
    }
    
    MLV_get_mouse_position(&x, &y);
    
    return Event(type, symbol, modifier, text, Shape::Point({x, y}), mouseButton, state);
}



