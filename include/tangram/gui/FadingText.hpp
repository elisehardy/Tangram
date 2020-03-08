/** @file FadingText.hpp
 *
 *  @brief ***FadingText***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */

#ifndef TANGRAM_FADINGTEXT_HPP
#define TANGRAM_FADINGTEXT_HPP

#include <cstdint>
#include <MLV/MLV_text.h>

#include <tangram/gui/Drawable.hpp>
#include <tangram/game/Updatable.hpp>


namespace tangram::gui {
    
    /**
     * Represent a element with text fading over time.
     */
    class FadingText : public gui::Drawable {
        private:
            const std::string text;
            const int16_t x;
            const int16_t y;
            const MLV_Color color;
            int32_t width = 0;
            MLV_Font *font;
        
        public:
            
            FadingText(int16_t x, int16_t y, std::string text, MLV_Color color,
                       const std::string &font = "../resources/fonts/helvetica.ttf", int32_t fontSize = 40);
        
            /**
             * Rewind this element in its most visible state.
             */
            void rewind();
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif //TANGRAM_FADINGTEXT_HPP
