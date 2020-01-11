#include <tangram/gui/ButtonDraw.hpp>


namespace tangram::gui {
    
    ButtonDraw::ButtonDraw(int16_t t_x, int16_t t_y, int16_t t_w, int16_t t_h,
                           std::function<void(int16_t, int16_t, int16_t, int16_t)> t_draw,
                           std::function<void(int16_t, int16_t, int16_t, int16_t)> t_hdraw,
                           std::function<void(int16_t, int16_t, int16_t, int16_t)> t_cdraw,
                           const std::function<bool(game::Engine &)> &t_execute) :
        ButtonAbstract(t_x, t_y, t_w, t_h, t_execute), customDraw(std::move(t_draw)), hCustomDraw(std::move(t_hdraw)),
        cCustomDraw(std::move(t_cdraw)) {
    }
    
    
    void ButtonDraw::draw() const {
        if (this->isLeftHeld()) {
            this->cCustomDraw(this->x, this->y, this->w, this->h);
        }
        else if (this->hovered) {
            this->hCustomDraw(this->x, this->y, this->w, this->h);
        }
        else {
            this->customDraw(this->x, this->y, this->w, this->h);
        }
    }
}
