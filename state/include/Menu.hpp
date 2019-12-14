#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <vector>

#include <MLV/MLV_window.h>
#include <MLV/MLV_color.h>

#include "../../gui/include/Drawable.hpp"
#include "../../game/include/Updatable.hpp"
#include "../../gui/include/Button.hpp"
#include "../../game/include/Engine.hpp"

#include "StateAbstract.hpp"
#include "Edit.hpp"
#include "Play.hpp"


namespace tangram::state {
    
    class Menu : public StateAbstract {
        private:
            static Menu instance;
            std::vector<game::Updatable *> updatables;
            std::vector<gui::Drawable *> drawables;
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
