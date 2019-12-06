#ifndef PLAY_HPP
#define PLAY_HPP

#include <vector>

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Observer.hpp"
#include "../../gui/include/Button.hpp"

#include "../../shape/include/Polygon.hpp"

#include "StateAbstract.hpp"


namespace tangram::state {
    
    class Play : public StateAbstract {
        private:
            static Play instance;
            
            std::vector<gui::Drawable *> drawables;
            gui::Observer observer;
            shape::Polygon player;
            shape::Polygon goal;
            bool initialized = false;
        
            void init() override;
        
        protected:
            Play() = default;
        
        public:
            static Play *getInstance();
            void cleanup() override;
            void pause() override;
            void resume() override;
            void update(const game::Event &event, game::Engine &engine) override;
            void draw() override;
    };
};

#endif // PLAY_HPP
