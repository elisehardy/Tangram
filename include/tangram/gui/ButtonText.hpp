/** @file ButtonText.hpp
 *
 *  @brief ***ButtonText***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <functional>

#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/gui/Drawable.hpp>
#include <tangram/gui/ButtonAbstract.hpp>


namespace tangram::gui {
    
    /**
     * Represents a clickable button with text on the gui.
     */
    class ButtonText final : public ButtonAbstract {
        private:
            const int16_t i;                                  /**< Size of the line spacing. */
            const std::string text;                           /**< Text to be displayed. */
            MLV_Font *font;                                   /**< Font of the text. */
            const MLV_Color borderColor;                      /**< Default color of the border. */
            const MLV_Color textColor;                        /**< Default color of the text. */
            const MLV_Color backgroundColor;                  /**< Default color of the background. */
            const MLV_Color hBorderColor;                     /**< Border's color border when the button is hovered. */
            const MLV_Color hTextColor;                       /**< Text's color when the button is hovered. */
            const MLV_Color hBackgroundColor;                 /**< Background's color when the button is hovered. */
            const MLV_Color pBorderColor;                     /**< Border's color when the button is pressed. */
            const MLV_Color pTextColor;                       /**< Text's color when the button is pressed. */
            const MLV_Color pBackgroundColor;                 /**< Background's color when the button is pressed. */
            const MLV_Text_justification justification;       /**< Justification of the text. */
            const MLV_Horizontal_position horizontalPosition; /**< Horizontal position of the text. */
            const MLV_Vertical_position verticalPosition;     /**< Vertical position of the text. */
        
        public:
            
            ButtonText(int16_t x, int16_t y, int16_t w, int16_t h, int8_t i, std::string text, const std::string &font,
                       MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor, MLV_Color hBorderColor,
                       MLV_Color hTextColor, MLV_Color hBackgroundColor, MLV_Color pBorderColor, MLV_Color pTextColor,
                       MLV_Color pBackgroundColor, MLV_Text_justification justification,
                       MLV_Horizontal_position horizontalPosition, MLV_Vertical_position verticalPosition,
                       const std::function<bool(game::Engine &)> &execute);
            
            ~ButtonText() override;
            
            void draw() const override;
    };
}

#endif // BUTTON_HPP
