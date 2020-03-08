/** @file State.hpp
 *
 *  @brief ***State***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef STATE_HPP
#define STATE_HPP

#include <tangram/game/Event.hpp>
#include <tangram/game/Updatable.hpp>

#include <tangram/gui/Drawable.hpp>


namespace tangram::game {
    class Engine;
}

namespace tangram::state {
    
    /**
     * Common interface for every State of the game.
     */
    class State : public gui::Drawable {
        
        protected:
            bool initialized = false;
            
            State() = default;
        
        public:
            
            /**
             * Initialize this State.
             */
            virtual void init() = 0;
        
            /**
             * Pause this State.
             */
            virtual void pause() = 0;
            
            /**
             * Resume this State.
             */
            virtual void resume() = 0;
            
            /**
             * Cleanup this state.
             */
            virtual void cleanup() = 0;
    };
}

#endif // STATE_HPP
