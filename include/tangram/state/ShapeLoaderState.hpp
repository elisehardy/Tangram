/** @file ShapeLoaderState.hpp
 *
 *  @brief ***ShapeLoaderState***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef TANGRAM_SHAPELOADERSTATE_HPP
#define TANGRAM_SHAPELOADERSTATE_HPP

#include <string>


namespace tangram::state {
    
    /**
     * Common interface for State needing to load a Shape.
     */
    class ShapeLoaderState : public State {
        
        public:
            
            /**
             * Load a shape into this State.
             *
             * @param path Path to the Shape to be laoded.
             *
             * @return A reference to the State.
             */
            virtual ShapeLoaderState *loadShape(const std::string &path) = 0;
    };
}

#endif //TANGRAM_SHAPELOADERSTATE_HPP
