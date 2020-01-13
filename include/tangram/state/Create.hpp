#ifndef Create_HPP
#define Create_HPP

#include <vector>
#include <memory>

#include <tangram/game/Updatable.hpp>
#include <tangram/geometry/Shape.hpp>
#include <tangram/gui/Drawable.hpp>
#include <tangram/state/State.hpp>


namespace tangram::state {
    
    class Create : public State {
        
        private:
            static constexpr int16_t MENU_SEPARATOR = game::HEIGHT;
        
        private:
            std::vector<std::shared_ptr<game::Updatable>> updatables = {};
            std::vector<std::shared_ptr<gui::Drawable>> drawables = {};
            geometry::Shape player = geometry::Shape();
            
            Create() = default;
            
            void init() override;
            
            static bool save(game::Engine &engine);
        
        public:
            static Create *getInstance();
            
            void cleanup() override;
            
            void pause() override;
            
            void resume() override;
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // Create_HPP
