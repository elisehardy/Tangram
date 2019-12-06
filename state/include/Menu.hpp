#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <vector>

#include <MLV/MLV_window.h>
#include <MLV/MLV_color.h>

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Observer.hpp"
#include "../../gui/include/Button.hpp"
#include "../../game/include/Engine.hpp"

#include "StateAbstract.hpp"
#include "Play.hpp"


namespace tangram::state {

    const uint16_t BUTTON_WIDTH = 140;
    const uint16_t BUTTON_HEIGTH = 50;
    const uint16_t NUMBER_BUTTON = 5;
    const uint16_t SPACE_2_BUTTON = 5;


    class Menu : public StateAbstract {
        private:
            static Menu instance;
            gui::Observer observer;
            std::vector<gui::Drawable *> drawables;
            bool initialized = false;
            
            void init() override;
        
        protected:
            Menu() = default;
        
        public:
            static Menu *getInstance();
            void cleanup() override;
            void pause() override;
            void resume() override;
            void update(const game::Event &event, game::Engine &engine) override;
            void draw() override;
    };
};

#endif // MENU_HPP
