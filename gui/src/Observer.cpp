#include "../include/Observer.hpp"


using namespace GUI;


void Observer::add(Observable *const subject) {
    this->observed.push_back(subject);
}


void Observer::remove(Observable *const subject) {
    this->observed.erase(std::remove(this->observed.begin(), this->observed.end(), subject), this->observed.end());
}


void Observer::notify(const Game::Event &event, Game::Engine &engine) const {
    std::for_each(this->observed.begin(), this->observed.end(),
                  [&event, &engine](Observable *subject) { subject->update(event, engine); }
    );
}
