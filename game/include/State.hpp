#ifndef STATE_HPP
#define STATE_HPP

class Engine;

namespace Tangram::Game {
    
    class State {
        private:
            /**
             * Destructor
             */
            virtual ~State() = 0;
        
        public:
            virtual void init() = 0;
            virtual void cleanup() = 0;
            virtual void pause() = 0;
            virtual void resume() = 0;
            virtual void handleEvents() = 0;
            virtual void update() = 0;
            virtual void draw() = 0;
            
            void changeState();
    };
};

#endif // STATE_HPP
