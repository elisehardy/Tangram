#include <MLV/MLV_shape.h>

#include <tangram/gui/Line.hpp>


namespace tangram::gui {
    
    Line::Line(MLV_Color t_color, int16_t t_x1, int16_t t_y1, int16_t t_x2, int16_t t_y2) :
        color(t_color), x1(t_x1), y1(t_y1), x2(t_x2), y2(t_y2) {
    }
    
    
    void Line::draw() const {
        MLV_draw_line(this->x1, this->y1, this->x2, this->y2, this->color);
    }
}
