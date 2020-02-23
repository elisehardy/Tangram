/** @file InputState.hpp
 *
 *  @brief ***InputState***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef TANGRAM_INPUT_HPP
#define TANGRAM_INPUT_HPP

#include <tangram/geometry/Point.hpp>


namespace tangram::game {
    
    /**
     * Struct used to store the state of an key / mouse button.
     *
     * A button/key 'pressed' boolean is true if it has been pressed while hovering the element. Setting 'pressed' set
     * 'pressedPoint'. It stay true only for one loop.
     *
     * A button/key 'held' boolean is true if it has been pressed while hovering the element. It stay true as long as the
     * button/key is held.
     *
     * A button/key 'released' boolean is true if it has been released while hovering the element, whether its 'pressed'
     * boolean is true or not. It stay true only for one loop.
     *
     * A button/key 'clicked' boolean is true if it has been released while hovering the element and its 'pressed' boolean
     * was true. It stay true only for one loop.
     */
    struct InputState {
        geometry::Point16 pressedPoint = { 0, 0 };  /**< Where the mouse was when the key/button was first pressed. */
        bool released = false;                      /**< Whether the key/button has been released this loop. */
        bool pressed = false;                       /**< Whether the key/button has been pressed this loop. */
        bool clicked = false;                       /**< Whether the key/button has been clicked this loop. */
        bool held = false;                          /**< Whether the key/button is currently held. */
        
        InputState() = default;
        
        friend std::ostream &operator<<(std::ostream &os, const InputState &inputState);
        
        /**
         * Reset this InputState by setting 'released', 'pressed' and 'clicked' to false.
         * 'held' and 'pressedPoint' should be managed by the consumer class.
         */
        void reset();
    };
}

#endif //TANGRAM_INPUT_HPP
