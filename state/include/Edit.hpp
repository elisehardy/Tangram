#ifndef EDIT_HPP
#define EDIT_HPP

#include <vector>

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Observer.hpp"
#include "../../gui/include/Button.hpp"

#include "../../geometry/include/Shape.hpp"

#include "StateAbstract.hpp"


namespace tangram::state {
    
    class Edit : public StateAbstract {
        private:
            static Edit instance;
            
            std::vector<gui::Drawable *> drawables;
            gui::Observer observer;
            geometry::Shape player = geometry::Shape();
            bool initialized = false;
        
            Edit() = default;
        
            void init() override;
        
        public:
            static Edit *getInstance();
            void cleanup() override;
            void pause() override;
            void resume() override;
            void update(const game::Event &event, game::Engine &engine) override;
            void draw() override;
    };
}

#endif // Edit_HPP
