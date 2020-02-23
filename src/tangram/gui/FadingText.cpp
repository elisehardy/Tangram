#include <utility>

#include <MLV/MLV_text.h>
#include <MLV/MLV_shape.h>

#include <tangram/gui/FadingText.hpp>


namespace tangram::gui {
    
    FadingText::FadingText(int16_t t_x, int16_t t_y, std::string t_text, MLV_Color t_color, const std::string &t_font,
                           int32_t fontSize) :
        text(std::move(t_text)), x(t_x), y(t_y), color(t_color), font(MLV_load_font(t_font.c_str(), fontSize)) {
    }
    
    
    void FadingText::rewind() {
        MLV_get_size_of_text_with_font(this->text.c_str(), &(this->width), nullptr, font);
    }
    
    
    bool FadingText::update(const game::Event &event, game::Engine &engine) {
        this->width = this->width > 0 ? this->width - 2 : 0;
        return false;
    }
    
    
    void FadingText::draw() const {
        int32_t height;
        MLV_get_size_of_text_with_font(this->text.c_str(), nullptr, &height, font);
        
        if (this->width) {
            MLV_draw_text_with_font(this->x, this->y, this->text.c_str(), this->font, this->color);
            MLV_draw_line(this->x, this->y + height + 2, this->x + this->width, this->y + height + 2, this->color);
        }
    }
}
