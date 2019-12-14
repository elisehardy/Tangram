#ifndef PLAY_HPP
#define PLAY_HPP

#include <vector>

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Button.hpp"

#include "../../geometry/include/Shape.hpp"

#include "../../game/include/Engine.hpp"
#include "../../game/include/Updatable.hpp"

#include "StateAbstract.hpp"


namespace tangram::state {
    
    class Play : public StateAbstract {
        
        private:
            static constexpr int16_t goal_x = 10;
            static constexpr int16_t goal_y = game::WIDTH / 2;
            static Play instance;
            
            std::vector<gui::Drawable *> drawables;
            std::vector<game::Updatable *> updatables;
            geometry::Shape player = geometry::Shape();
            geometry::Shape goal = geometry::Shape();
            bool initialized = false;
            
            Play() = default;
            
            void init() override;
        
        public:
            static Play *getInstance();
            void cleanup() override;
            void pause() override;
            void resume() override;
            void update(const game::Event &event, game::Engine &engine) override;
            void draw() const override;
    };
}

#endif // PLAY_HPP
