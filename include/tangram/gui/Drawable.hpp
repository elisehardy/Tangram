#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <cstdint>

#include <MLV/MLV_text.h>


namespace tangram::gui {
    
    class Drawable {
        public:
            
            /**
             * Draw this drawable on the screen.
             */
            virtual ~Drawable() = default;
            
            virtual void draw() const = 0;
    };
}

#endif // DRAWABLE_HPP
