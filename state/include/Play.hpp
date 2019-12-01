#ifndef PLAY_HPP
#define PLAY_HPP

#include <vector>

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Observer.hpp"
#include "../../gui/include/Button.hpp"
#include "../../shape/include/ShapeSet.hpp"

#include "StateAbstract.hpp"


namespace State {
    
    class Play : public StateAbstract {
        private:
            static Play instance;
            std::vector<GUI::Drawable *> drawables;
            GUI::Observer observer;
            Shape::ShapeSet goal;
            Shape::ShapeSet player;
            bool initialized = false;
        
            void init() override;
        
        protected:
            Play() = default;
        
        public:
            static Play *getInstance();
            void cleanup() override;
            void pause() override;
            void resume() override;
            void update(const Game::Event &event, Game::Engine &engine) override;
            void draw() override;
    };
};

#endif // PLAY_HPP
