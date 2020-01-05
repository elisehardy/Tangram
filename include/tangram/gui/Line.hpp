#ifndef TANGRAM_LINE_HPP
#define TANGRAM_LINE_HPP

#include <tangram/gui/Drawable.hpp>

namespace tangram::gui {
    class Line : public gui::Drawable {
        private:
            const MLV_Color color;
            const int16_t x1;
            const int16_t y1;
            const int16_t x2;
            const int16_t y2;
            
        public:
            
            Line(MLV_Color color, int16_t x1, int16_t y1, int16_t x2, int16_t y2);
            
            void draw() const override;
    };
}

#endif //TANGRAM_LINE_HPP
