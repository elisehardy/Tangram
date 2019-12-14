#include <string>

#include "../include/Event.hpp"


using namespace tangram::game;

namespace tangram::game {
    std::ostream &operator<<(std::ostream &os, const Event &event) {
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
    MLV_Event type=MLV_NONE;
    MLV_Keyboard_button symbol=MLV_KEYBOARD_NONE;
    MLV_Keyboard_modifier modifier=MLV_KEYBOARD_KMOD_NONE;
    char *text=new char;
    int x=0, y=0;
    MLV_Mouse_button mouseButton=MLV_BUTTON_LEFT;
    MLV_Button_state state=MLV_PRESSED;
    geometry::Point16 mousePos = geometry::Point16({static_cast<int16_t >(x), static_cast<int16_t >(y)});

    return Event(type, symbol, modifier, text, mousePos, mouseButton, state);
}

