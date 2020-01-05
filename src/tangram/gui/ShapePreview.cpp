#include <MLV/MLV_shape.h>

#include <tangram/gui/ShapePreview.hpp>


namespace tangram::gui {
    
    ShapePreview::ShapePreview(const geometry::Shape &t_shape, double scale, int16_t size, int16_t t_x, int16_t t_y,
                               MLV_Color color) :
        shape(geometry::Shape(t_shape).scale(scale).translate(t_x, t_y).setColor(color)),
        side(static_cast<int16_t>(size * scale)), x(t_x), y(t_y) {
    }
    
    
    void ShapePreview::draw() const {
        this->shape.draw();
        
        MLV_draw_line(this->x, this->y, this->x + this->side, this->y, MLV_COLOR_WHITE);
        MLV_draw_line(this->x, this->y, this->x, this->y + this->side, MLV_COLOR_WHITE);
        MLV_draw_line(this->x + this->side, this->y, this->x + this->side, this->y + this->side, MLV_COLOR_WHITE);
        MLV_draw_line(this->x, this->y + this->side, this->x + this->side, this->y + this->side, MLV_COLOR_WHITE);
    }
}
