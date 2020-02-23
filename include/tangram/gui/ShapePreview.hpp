/** @file ShapePreview.hpp
 *
 *  @brief ***ShapePreview***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef TANGRAM_SHAPEPREVIEW_HPP
#define TANGRAM_SHAPEPREVIEW_HPP

#include <vector>

#include <MLV/MLV_color.h>

#include <tangram/gui/Drawable.hpp>
#include <tangram/geometry/Shape.hpp>


namespace tangram::gui {
    
    /**
     * Draw a Shape in a reduced and framed way, in black and white.
     */
    class ShapePreview : public Drawable {
        private:
            const geometry::Shape shape;
            const int16_t side;
            const int16_t x;
            const int16_t y;
        
        public:
            
            ShapePreview(const geometry::Shape &shape, double scale, int16_t size, int16_t x, int16_t y,
                         MLV_Color color = MLV_COLOR_GREY50);
            
            void draw() const override;
    };
}

#endif //TANGRAM_SHAPEPREVIEW_HPP
