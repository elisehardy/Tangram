/** @file Menu.hpp
 *
 *  @brief ***Menu***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <memory>
#include <vector>

#include <MLV/MLV_window.h>
#include <MLV/MLV_color.h>

#include <tangram/gui/Drawable.hpp>
#include <tangram/gui/ButtonText.hpp>
#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/state/State.hpp>
#include <tangram/state/Edit.hpp>
#include <tangram/state/Play.hpp>


namespace tangram::state {
    
    /**
     * State representing the Main Menu of the Tangram.
     */
    class Menu : public State {
        
        private:
            std::vector<std::shared_ptr<game::Updatable>> updatables = {};
            std::vector<std::shared_ptr<gui::Drawable>> drawables = {};
            
            Menu() = default;
            
            void init() override;
        
        public:
        
            /**
             * Return the instance of the Singleton corresponding to this State.
             *
             * @return The instance of the Singleton corresponding to this State.
             */
            static Menu *getInstance();
            
            void cleanup() override;
            
            void pause() override;
            
            void resume() override;
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // MENU_HPP
