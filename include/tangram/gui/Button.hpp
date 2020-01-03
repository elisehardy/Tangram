#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/gui/Drawable.hpp>


namespace tangram::gui {
    
    /**
     * Represents a clickable button on the gui.
     */
    class Button : public Drawable, public game::Updatable {
        private:
            const uint16_t x; /**< X coordinate of the north-west corner. */
            const uint16_t y; /**< Y coordinate of the north-west corner. */
            const uint16_t w; /**< Width of the button. */
            const uint16_t h; /**< Height of the button. */
            const uint16_t i; /**< Size of the line spacing. */
            const char *text; /**< Text to be displayed. */
            const MLV_Font *font; /**< Font of the text. */
            const MLV_Color borderColor;      /**< Default color of the border. */
            const MLV_Color textColor;        /**< Default color of the text. */
            const MLV_Color backgroundColor;  /**< Default color of the background. */
            const MLV_Color hBorderColor;     /**< Color of the border when the button is hovered. */
            const MLV_Color hTextColor;       /**< Color of the text when the button is hovered. */
            const MLV_Color hBackgroundColor; /**< Color of the background when the button is hovered. */
            const MLV_Color pBorderColor;     /**< Color of the border when the button is pressed. */
            const MLV_Color pTextColor;       /**< Color of the text when the button is pressed. */
            const MLV_Color pBackgroundColor; /**< Color of the background when the button is pressed. */
            const MLV_Text_justification justification; /**< Justification of the text. */
            const MLV_Horizontal_position horizontalPosition; /**< Horizontal position of the text. */
            const MLV_Vertical_position verticalPosition;     /**< Vertical position of the text. */
            
            void (*execute)(game::Engine &); /**< Function executed when the button is clicked */
        public:
            /**
             * Constructor.
             */
            Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t i, const char *text, const char *font,
                   MLV_Color borderColor, MLV_Color textColor, MLV_Color backgroundColor, MLV_Color hBorderColor,
                   MLV_Color hTextColor, MLV_Color hBackgroundColor, MLV_Color pBorderColor, MLV_Color pTextColor,
                   MLV_Color pBackgroundColor, MLV_Text_justification justification,
                   MLV_Horizontal_position horizontalPosition, MLV_Vertical_position verticalPosition,
                   void (*execute)(game::Engine &));
            
            /**
             * Update `hovered` / `pressed` fields. Execute the `execute` function if the button is clicked.
             *
             * @see Updatable#update()
             */
            void update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // BUTTON_HPP
