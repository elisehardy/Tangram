#ifndef TANGRAM_SHAPELOADERSTATE_HPP
#define TANGRAM_SHAPELOADERSTATE_HPP

#include <string>


namespace tangram::state {
    
    class ShapeLoaderState : public State {
        
        public:
            virtual ShapeLoaderState *loadShape(const std::string &path) = 0;
    };
}

#endif //TANGRAM_SHAPELOADERSTATE_HPP
