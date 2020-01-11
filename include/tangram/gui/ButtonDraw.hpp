#ifndef BUTTONDRAW_HPP
#define BUTTONDRAW_HPP

#include <any>
#include <functional>

#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/gui/Drawable.hpp>
#include <tangram/gui/ButtonAbstract.hpp>


namespace tangram::gui {
    
    /**
     * Represents a clickable button on the gui.
     */
    class ButtonDraw final : public ButtonAbstract {
        private:
            /** Function used to draw the button */
            const std::function<void(int16_t, int16_t, int16_t, int16_t)> customDraw;
            const std::function<void(int16_t, int16_t, int16_t, int16_t)> hCustomDraw;
            const std::function<void(int16_t, int16_t, int16_t, int16_t)> cCustomDraw;
        
        public:
            
            ButtonDraw(int16_t x, int16_t y, int16_t w, int16_t h,
                       std::function<void(int16_t, int16_t, int16_t, int16_t)> draw,
                       std::function<void(int16_t, int16_t, int16_t, int16_t)> hdraw,
                       std::function<void(int16_t, int16_t, int16_t, int16_t)> cdraw,
                       const std::function<bool(game::Engine &)> &execute);
            
            void draw() const override;
    };
}

#endif // BUTTONDRAW_HPP
