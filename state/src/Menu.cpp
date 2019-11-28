#include "../include/Menu.hpp"


using namespace State;

Menu Menu::instance = Menu();


void Menu::init() {
    auto *b = new GUI::Button(
            100, 100, 200, 50, 1,
            "Coucou", "resources/fonts/helvetica.ttf",
            MLV_COLOR_GREY60, MLV_COLOR_BLACK, MLV_COLOR_GREY80,
            MLV_COLOR_GREY50, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY60,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { e.pushState(Play::getInstance()); }
    );
    
    this->drawables.push_back(b);
    this->observer.add(b);
    this->initialized = true;
}


Menu *Menu::getInstance() {
    if (!Menu::instance.initialized) {
        Menu::instance.init();
    }
    return &Menu::instance;
}


void Menu::draw() {
    MLV_clear_window(MLV_COLOR_GREY80);
    std::for_each(this->drawables.begin(), this->drawables.end(), [](GUI::Drawable *d) { d->draw(); });
    MLV_actualise_window();
}


void Menu::update(const Game::Event &event, Game::Engine &engine) {
    observer.notify(event, engine);
}


void Menu::cleanup() {
}


void Menu::pause() {
}


void Menu::resume() {
}



