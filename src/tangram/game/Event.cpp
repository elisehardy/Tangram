#include <string>

#include <tangram/game/Event.hpp>


using namespace tangram::game;

namespace tangram::game {
    std::ostream &operator<<(std::ostream &os, const Event &event) {
        os << "Mouse position: " << event.mousePos << " | ";
        switch (event.type) {
            case MLV_NONE:
            case MLV_MOUSE_MOTION:
                os << "No event";
                break;
            case MLV_KEY:
                os << "Keyboard's key " << (event.state == MLV_PRESSED ? "pressed" : "released")
                   << ": " << MLV_convert_keyboard_button_to_string(event.symbol);
                break;
            case MLV_MOUSE_BUTTON:
                os << "Mouse's button " << (event.state == MLV_PRESSED ? "pressed" : "released")
                   << ": " << MLV_convert_mouse_button_to_string(event.mouseButton);
                break;
            case MLV_INPUT_BOX:
                os << "Input box: " << event.text;
                break;
        }
        
        return os;
    }
}


Event::Event(const MLV_Event t_type, const MLV_Keyboard_button t_symbol, const MLV_Keyboard_modifier t_modifier,
             const char *t_text, const geometry::Point16 t_mousePos, const MLV_Mouse_button t_mouseButton,
             const MLV_Button_state t_state) :
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
    
    geometry::Point16 mousePos = geometry::Point16({ static_cast<int16_t >(x), static_cast<int16_t >(y) });
    return Event(type, symbol, modifier, text, mousePos, mouseButton, state);
}

