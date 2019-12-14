#include "../include/Button.hpp"


using namespace tangram::gui;


Button::Button(uint16_t t_x, uint16_t t_y, uint16_t t_w, uint16_t t_h, uint8_t t_i, const char *t_text,
               const char *t_font, MLV_Color t_borderColor, MLV_Color t_textColor, MLV_Color t_backgroundColor,
               MLV_Color t_hBorderColor, MLV_Color t_hTextColor, MLV_Color t_hBackgroundColor,
               MLV_Color t_pBorderColor, MLV_Color t_pTextColor, MLV_Color t_pBackgroundColor,
               MLV_Text_justification t_justification, MLV_Horizontal_position t_horizontalPosition,
               MLV_Vertical_position t_verticalPosition, void (*t_execute)(game::Engine &)) :
        x(t_x), y(t_y), w(t_w), h(t_h), i(t_i), text(t_text), borderColor(t_borderColor),
        textColor(t_textColor), backgroundColor(t_backgroundColor), hBorderColor(t_hBorderColor),
        hTextColor(t_hTextColor), hBackgroundColor(t_hBackgroundColor), pBorderColor(t_pBorderColor),
        pTextColor(t_pTextColor), pBackgroundColor(t_pBackgroundColor), justification(t_justification),
        horizontalPosition(t_horizontalPosition), verticalPosition(t_verticalPosition), hovered(false), pressed(false),
        execute(t_execute) {}

void Button::update(const game::Event &event, game::Engine &engine) {}


void Button::draw() const {}
