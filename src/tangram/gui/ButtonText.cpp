#include <utility>

#include <tangram/gui/ButtonText.hpp>


namespace tangram::gui {
    
    ButtonText::ButtonText(int16_t t_x, int16_t t_y, int16_t t_w, int16_t t_h, int8_t t_i,
                           std::string t_text, const std::string &t_font,
                           MLV_Color t_borderColor, MLV_Color t_textColor, MLV_Color t_backgroundColor,
                           MLV_Color t_hBorderColor, MLV_Color t_hTextColor, MLV_Color t_hBackgroundColor,
                           MLV_Color t_pBorderColor, MLV_Color t_pTextColor, MLV_Color t_pBackgroundColor,
                           MLV_Text_justification t_justification, MLV_Horizontal_position t_horizontalPosition,
                           MLV_Vertical_position t_verticalPosition,
                           const std::function<bool(game::Engine &)> &t_execute) :
        ButtonAbstract(t_x, t_y, t_w, t_h, t_execute), i(t_i), text(std::move(t_text)),
        font(MLV_load_font(t_font.c_str(), 20)), borderColor(t_borderColor), textColor(t_textColor),
        backgroundColor(t_backgroundColor), hBorderColor(t_hBorderColor), hTextColor(t_hTextColor),
        hBackgroundColor(t_hBackgroundColor), pBorderColor(t_pBorderColor), pTextColor(t_pTextColor),
        pBackgroundColor(t_pBackgroundColor), justification(t_justification), horizontalPosition(t_horizontalPosition),
        verticalPosition(t_verticalPosition) {
        //        std::cout << "Create button " << this->text << std::endl;
    }
    
    
    ButtonText::~ButtonText() {
        //        std::cout << "Free button " << this->text << std::endl;
        //                MLV_free_font(this->font);
    }
    
    
    void ButtonText::draw() const {
        MLV_Color borderColor, textColor, backgroundColor;
        
        if (this->isLeftHeld() || !this->enabled) {
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
            this->x, this->y, this->w, this->h, this->text.c_str(), this->font, this->i, borderColor, textColor,
            backgroundColor, this->justification, this->horizontalPosition, this->verticalPosition
        );
    }
}
