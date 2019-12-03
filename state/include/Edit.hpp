#ifndef EDIT_HPP
#define EDIT_HPP

#include <vector>

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Observer.hpp"
#include "../../gui/include/Button.hpp"
#include "../../shape/include/ShapeSet.hpp"

#include "StateAbstract.hpp"


namespace State {
    
    class Edit : public StateAbstract {
        private:
            static Edit instance;
            std::vector<GUI::Drawable *> drawables;
            GUI::Observer observer;
            Shape::ShapeSet goal;
            Shape::ShapeSet player;
            bool initialized = false;
        
            void init() override;
        
        protected:
            Edit() = default;
        
        public:
            static Edit *getInstance();
            void cleanup() override;
            void pause() override;
            void resume() override;
            void update(const Game::Event &event, Game::Engine &engine) override;
            void draw() override;
    };
};

#endif // Edit_HPP
