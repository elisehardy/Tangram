#include <tangram/gui/ButtonAbstract.hpp>

namespace tangram::gui {
    
    ButtonAbstract::ButtonAbstract(int16_t t_x, int16_t t_y, int16_t t_w, int16_t t_h,
                                   std::function<bool(game::Engine &)> t_execute) :
        x(t_x), y(t_y), w(t_w), h(t_h), execute(std::move(t_execute)) {
    }
    
    
    bool ButtonAbstract::update(const game::Event &event, game::Engine &engine) {
        int x1 = this->x, x2 = x1 + this->w, y1 = this->y, y2 = y1 + this->h;
        int mx = event.mousePos.x, my = event.mousePos.y;
        
        this->hovered = mx >= x1 && my >= y1 && mx <= x2 && my <= y2;
        
        game::Updatable::update(event, engine);
        
        if (this->enabled && this->isLeftClicked()) {
            return this->execute(engine);
        }
        
        return false;
    }
}
