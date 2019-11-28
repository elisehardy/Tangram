#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <vector>

#include <MLV/MLV_window.h>
#include <MLV/MLV_color.h>

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Observer.hpp"
#include "../../gui/include/Button.hpp"

#include "StateAbstract.hpp"


namespace State {
    
    class Menu : public StateAbstract {
        private:
            static Menu instance;
            GUI::Observer observer;
            std::vector<GUI::Drawable *> drawables;
            bool initialized = false;
            
            void init() override;
        
        protected:
            Menu() = default;
        
        public:
            static Menu *getInstance();
            void cleanup() override;
            void pause() override;
            void resume() override;
            void update(const Game::Event &event, Game::Engine &engine) override;
            void draw() override;
    };
};

#endif // MENU_HPP
