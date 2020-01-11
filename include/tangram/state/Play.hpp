#ifndef PLAY_HPP
#define PLAY_HPP

#include <vector>

#include <tangram/gui/Drawable.hpp>
#include <tangram/geometry/Shape.hpp>
#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/state/StateAbstract.hpp>


namespace tangram::state {
    
    class Play : public StateAbstract {
        
        private:
            static constexpr int16_t goal_x = 10;
            static constexpr int16_t goal_y = game::WIDTH / 2;
            
            std::vector<gui::Drawable *> drawables;
            std::vector<game::Updatable *> updatables;
            geometry::Shape player = geometry::Shape();
            geometry::Shape goal = geometry::Shape();
            
            Play() = default;
            
            void init() override;
        
        public:
            static Play *getInstance();
            
            void pause() override;
            
            void resume() override;
            
            void cleanup() override;
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // PLAY_HPP
