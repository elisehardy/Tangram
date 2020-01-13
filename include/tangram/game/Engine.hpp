#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <stack>
#include <cstdint>

#include <MLV/MLV_window.h>
#include <MLV/MLV_time.h>

#include <tangram/game/Event.hpp>


namespace tangram::state {
    class State;
}

namespace tangram::game {
    
    static const std::string DEFAULT_SHAPE_PATH = "../resources/default.shp"; /**< Path to the default shape. */
    static const std::string SHAPE_DIR = "../resources/shapes/"; /**< Path to the directory containing saved shapes. */
    static const std::string FONT_DIR = "../resources/fonts/"; /**< Path to the directory containing fonts used. */
    
    static constexpr uint16_t FRAME_RATE = 800; /**< Frame rate of the game. */
    static constexpr uint16_t WIDTH = 1200;     /**< Width of the window. */
    static constexpr uint16_t HEIGHT = 800;     /**< Height of the window. */
    
    
    /**
     * Class representing a whole game, it store the game's States and main constants.
     */
    class Engine {
        private:
            std::stack<state::State *> states = {}; /**< Stack containing the current States of the game. */
            bool running = false; /**< Boolean indicating if the game is running or should cleanup and quit. */
        
        public:
            
            /**
             * Initialize the game by creating the window and setting the framerate.
             */
            void init();
            
            /**
             * Cleanup the whole game.
             */
            void cleanup();
            
            /**
             * Push a new State of the stack.
             *
             * @param state State being pushed on the stack.
             *
             * @return true
             */
            bool pushState(state::State *state);
            
            /**
             * Remove the current State above the stack
             *
             * @return true
             */
            bool popState();
            
            /**
             * Update the State at the top of the stack. Stops the game if no
             * State is in the stack.
             *
             * @param event An instance of Event containing the inputs of the user.
             */
            void update(const game::Event &event);
            
            /**
             * Draw the State at the top of the stack.
             */
            void draw();
            
            /**
             * Return whether the game is currently running or should be cleaned-up and closes.
             */
            bool isRunning();
            
            /**
             * Stops the game.
             *
             * @return true
             */
            bool stop();
    };
}

#endif // ENGINE_HPP
