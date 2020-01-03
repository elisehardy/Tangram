#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <vector>

#include <MLV/MLV_window.h>
#include <MLV/MLV_color.h>

#include <tangram/gui/Drawable.hpp>
#include <tangram/gui/Button.hpp>
#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/state/StateAbstract.hpp>
#include <tangram/state/Edit.hpp>
#include <tangram/state/Play.hpp>


namespace tangram::state {
    
    class Menu : public StateAbstract {
        private:
            static Menu instance;
            std::vector<gui::Drawable *> drawables;
            std::vector<game::Updatable *> updatables;
            bool initialized = false;
            
            Menu() = default;
            
            void init() override;
        
        public:
            static Menu *getInstance();
            void cleanup() override;
            void pause() override;
            void resume() override;
            void update(const game::Event &event, game::Engine &engine) override;
            void draw() const override;
    };
}

#endif // MENU_HPP