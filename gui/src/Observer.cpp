#include "../include/Observer.hpp"


using namespace GUI;


void Observer::add(Observable *const subject) {
    this->observed.push_back(subject);
}


void Observer::add(const std::vector<Observable *> &subjects) {
    std::for_each(subjects.begin(), subjects.end(), [this](Observable *s) { this->add(s); });
}


void Observer::remove(Observable *const subject) {
    this->observed.erase(std::remove(this->observed.begin(), this->observed.end(), subject), this->observed.end());
}


void Observer::remove(const std::vector<Observable *> &subjects) {
    std::for_each(subjects.begin(), subjects.end(), [this](Observable *s) { this->remove(s); });
}


void Observer::notify(const Game::Event &event, Game::Engine &engine) const {
    std::for_each(this->observed.begin(), this->observed.end(),
                  [&event, &engine](Observable *s) { s->update(event, engine); }
    );
}
