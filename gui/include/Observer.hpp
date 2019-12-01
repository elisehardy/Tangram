#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <vector>
#include <algorithm>

#include "../../game/include/Engine.hpp"

#include "Observable.hpp"


namespace GUI {
    
    class Observer {
        private:
            std::vector<Observable *> observed;
        
        public:
            void add(Observable *subject);
            void add(const std::vector<Observable *> &subjects);
            void remove(Observable *subject);
            void remove(const std::vector<Observable *> &subjects);
            void notify(const Game::Event &event, Game::Engine &engine) const;
    };
}

#endif // OBSERVER_HPP
