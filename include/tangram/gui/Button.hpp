#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/gui/Drawable.hpp>
#include <bits/unique_ptr.h>


namespace tangram::gui {
    
    /**
     * Represents a clickable button on the gui.
     */
    class Button final : public Drawable, public game::Updatable {
        private:
            const int16_t x;                                  /**< X coordinate of the north-west corner. */
            const int16_t y;                                  /**< Y coordinate of the north-west corner. */
            const int16_t w;                                  /**< Width of the button. */
            const int16_t h;                                  /**< Height of the button. */
            const int16_t i;                                  /**< Size of the line spacing. */
            const std::string text;                           /**< Text to be displayed. */
            MLV_Font* font;                                   /**< Font of the text. */
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
            
            void (*execute)(game::Engine &); /**< Function executed when the button is clicked */
        
        public:

            Button(int16_t x, int16_t y, int16_t w, int16_t h, int8_t i, std::string text, const std::string& font,
                   MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor, MLV_Color hBorderColor,
                   MLV_Color hTextColor, MLV_Color hBackgroundColor, MLV_Color pBorderColor, MLV_Color pTextColor,
                   MLV_Color pBackgroundColor, MLV_Text_justification justification,
                   MLV_Horizontal_position horizontalPosition, MLV_Vertical_position verticalPosition,
                   void (*execute)(game::Engine &));
            
            ~Button() override;
            
            
            void update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // BUTTON_HPP
