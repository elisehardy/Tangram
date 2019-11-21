#include "../include/Menu.hpp"


using namespace Tangram::State;

Menu Menu::instance;


Menu *Menu::Instance() {
    return &Menu::instance;
}


void Menu::init() {
}


void Menu::draw() {
    MLV_clear_window(MLV_COLOR_GREY80);
    
    MLV_actualise_window();
}


void Menu::update() {
}


void Menu::cleanup() {
}


void Menu::changeState() {
}


void Menu::handleEvents() {
}


void Menu::pause() {
}


void Menu::resume() {
}
