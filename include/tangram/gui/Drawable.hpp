/** @file Drawable.hpp
 *
 *  @brief ***Drawable***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <cstdint>

#include <MLV/MLV_text.h>


namespace tangram::gui {
    
    /**
     * Common interface for every Drawable element of the Tangram.
     */
    class Drawable {
        public:
            
            /**
             * Draw this drawable on the screen.
             */
            virtual ~Drawable() = default;
            
            /**
             * Draw this element on screen.
             */
            virtual void draw() const = 0;
    };
}

#endif // DRAWABLE_HPP
