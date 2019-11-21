#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <MLV/MLV_window.h>
#include <MLV/MLV_color.h>

#include "StateAbstract.hpp"


namespace Tangram::State {
    
    class Menu : public StateAbstract {
        private:
            static Menu instance;
        
        protected:
            /**
             * Making constructor protected since States will be singletons.
             */
            Menu() {
            };
        
        public:
            static Menu *Instance();
            void init();
            void cleanup();
            void pause();
            void resume();
            void handleEvents();
            void update();
            void draw();
            void changeState();
    };
};

#endif //MAIN_MENU_HPP
