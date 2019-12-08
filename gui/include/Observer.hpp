#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <vector>
#include <algorithm>

#include "../../game/include/Engine.hpp"

#include "Observable.hpp"


namespace tangram::gui {
    
    class Observer {
        private:
            std::vector<Observable *> observed;
        
        public:
            Observer() = default;
            
            void add(Observable *subject);
            
            void add(const std::vector<Observable *> &subjects);
            
            void remove(Observable *subject);
            
            void remove(const std::vector<Observable *> &subjects);
            
            void notify(const game::Event &event, game::Engine &engine) const;
    };
}

#endif // OBSERVER_HPP
