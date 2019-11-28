#include "../include/Button.hpp"


using namespace GUI;


Button::Button(uint16_t t_x, uint16_t t_y, uint16_t t_w, uint16_t t_h, uint8_t t_i, const char *t_text,
               const char *t_font, MLV_Color t_borderColor, MLV_Color t_textColor, MLV_Color t_backgroundColor,
               MLV_Color t_hBorderColor, MLV_Color t_hTextColor, MLV_Color t_hBackgroundColor,
               MLV_Color t_pBorderColor, MLV_Color t_pTextColor, MLV_Color t_pBackgroundColor,
               MLV_Text_justification t_justification, MLV_Horizontal_position t_horizontalPosition,
               MLV_Vertical_position t_verticalPosition, void (*t_execute)(Game::Engine &)) :
        x(t_x), y(t_y), w(t_w), h(t_h), i(t_i), text(t_text), borderColor(t_borderColor),
        textColor(t_textColor), backgroundColor(t_backgroundColor), hBorderColor(t_hBorderColor),
        hTextColor(t_hTextColor), hBackgroundColor(t_hBackgroundColor), pBorderColor(t_pBorderColor),
        pTextColor(t_pTextColor), pBackgroundColor(t_pBackgroundColor), justification(t_justification),
        horizontalPosition(t_horizontalPosition), verticalPosition(t_verticalPosition), hovered(false), pressed(false),
        execute(t_execute) {
    this->font = MLV_load_font(t_font, 20);
}


void Button::update(const Game::Event &event, Game::Engine &engine) {
    int x1 = this->x, x2 = x1 + this->w, y1 = this->y, y2 = y1 + this->h;
    int mx = event.mousePos.first, my = event.mousePos.second;
    bool leftClick = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_LEFT;
    
    this->hovered = mx >= x1 && my >= y1 && mx <= x2 && my <= y2;
    
    if (this->hovered && leftClick && event.state == MLV_PRESSED) {  // Pressed on button
        this->pressed = true;
    }
    else if (this->pressed && leftClick && event.state == MLV_RELEASED) { // Left click released
        if (this->hovered) { // Released on button
            this->pressed = false;
            this->execute(engine);
        }
        else { // Released outside button
            this->pressed = false;
        }
    }
}


void Button::draw() const {
    MLV_Color borderColor, textColor, backgroundColor;
    
    if (this->pressed) {
        textColor = this->pTextColor;
        borderColor = this->pBorderColor;
        backgroundColor = this->pBackgroundColor;
    }
    else if (this->hovered) {
        textColor = this->hTextColor;
        borderColor = this->hBorderColor;
        backgroundColor = this->hBackgroundColor;
    }
    else {
        textColor = this->textColor;
        borderColor = this->borderColor;
        backgroundColor = this->backgroundColor;
    }
    
    MLV_draw_text_box_with_font(
            this->x, this->y, this->w, this->h, this->text, this->font, this->i, borderColor, textColor,
            backgroundColor, this->justification, this->horizontalPosition, this->verticalPosition
    );
}
