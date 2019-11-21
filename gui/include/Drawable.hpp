#ifndef MAIN_DRAWABLE_HPP
#define MAIN_DRAWABLE_HPP

#include <cstdint>
#include <MLV/MLV_all.h>


namespace Tangram::GUI {
    
    class Drawable {
        public:
            /**
             * Draw this polygon on the screen.
             */
            virtual void draw() const = 0;
    };
};

#endif // MAIN_DRAWABLE_HPP
