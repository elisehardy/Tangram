#ifndef PLAY_HPP
#define PLAY_HPP

#include <vector>

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Observer.hpp"
#include "../../gui/include/Button.hpp"
#include "../../shape/include/ShapeSet.hpp"

#include "StateAbstract.hpp"
#include "../../game/include/Engine.hpp"

namespace State {

    class Play : public StateAbstract {

        const std::pair <uint16_t, uint16_t> image_goal = { 10, Game::WIDTH/2 };

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
