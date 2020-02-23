/** @file ButtonAbstract.hpp
 *
 *  @brief ***ButtonAbstract***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef TANGRAM_BUTTONABSTRACT_HPP
#define TANGRAM_BUTTONABSTRACT_HPP

#include <functional>

#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>
#include <tangram/gui/Drawable.hpp>


namespace tangram::gui {
    
    /**
     * Abstract class used to represent a Button.
     */
    class ButtonAbstract : public game::Updatable, public Drawable {
        protected:
            const int16_t x; /**< X coordinate of the north-west corner. */
            const int16_t y; /**< Y coordinate of the north-west corner. */
            const int16_t w; /**< Width of the button. */
            const int16_t h; /**< Height of the button. */
            
            const std::function<bool(game::Engine &)> execute;  /** Function executed when the button is clicked */
        
        public:
            
            ButtonAbstract(int16_t x, int16_t y, int16_t w, int16_t h, std::function<bool(game::Engine &)> execute);
            
            bool update(const game::Event &event, game::Engine &engine) override;
    };
}

#endif //TANGRAM_BUTTONABSTRACT_HPP
