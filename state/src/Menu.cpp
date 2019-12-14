#include "../include/Menu.hpp"


using namespace tangram;
using namespace tangram::state;

Menu Menu::instance = Menu();


void Menu::init() {}


Menu *Menu::getInstance() {
    return nullptr;
}


void Menu::draw() const {}


void Menu::update(const game::Event &event, game::Engine &engine) {}


void Menu::cleanup() {}


void Menu::pause() {}


void Menu::resume() {}



