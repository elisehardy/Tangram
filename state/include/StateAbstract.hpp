#ifndef STATE_HPP
#define STATE_HPP



class Engine;

namespace Tangram::State {
    
    class StateAbstract {
        protected:
            /**
             * Making constructor protected since States will be singletons.
             */
            StateAbstract() {
            };
        
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
