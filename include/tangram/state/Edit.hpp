#ifndef EDIT_HPP
#define EDIT_HPP

#include <vector>

#include <tangram/game/Updatable.hpp>
#include <tangram/geometry/Shape.hpp>
#include <tangram/gui/Drawable.hpp>
#include <tangram/state/StateAbstract.hpp>


namespace tangram::state {
    
    class Edit : public StateAbstract {
        
        private:
            static constexpr int16_t MENU_SEPARATOR = game::HEIGHT;
            
            static constexpr uint16_t BUTTON_WIDTH = 140;
            static constexpr uint16_t BUTTON_HEIGHT = 50;
            static constexpr uint16_t BUTTON_X = (
                MENU_SEPARATOR + ((game::WIDTH - MENU_SEPARATOR) / 2) - (BUTTON_WIDTH / 2)
            );
            
            static constexpr double PREVIEW_SCALE_FACTOR = 0.40;
            static constexpr int16_t PREVIEW_SIDE = static_cast<int16_t>(MENU_SEPARATOR * PREVIEW_SCALE_FACTOR);
            static constexpr int16_t PREVIEW_X = (
                MENU_SEPARATOR + ((game::WIDTH - MENU_SEPARATOR) / 2) - (PREVIEW_SIDE / 2)
            );
            static constexpr int16_t PREVIEW_Y = 50;
        
        private:
            std::vector<gui::Drawable *> drawables;
            std::vector<game::Updatable *> updatables;
            geometry::Shape player = geometry::Shape();
            geometry::Shape goal = geometry::Shape();
            std::string title = "";
            
            Edit() = default;
            
            void init() override;
            
            static void save(game::Engine &engine);
        
        public:
            static Edit *getInstance();
            
            static Edit *load(std::string title);
            
            void pause() override;
            
            void resume() override;
            
            void cleanup() override;
            
            void update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // Edit_HPP
