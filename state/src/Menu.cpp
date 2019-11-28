#include "../include/Menu.hpp"

using namespace State;
using namespace Game;

Menu Menu::instance = Menu();


void Menu::init() {
    this->drawables.push_back(new GUI::Button(
            WIDTH/2-(BUTTON_WIDTH/2), 1*HEIGHT/NUMBER_BUTTON - (BUTTON_HEIGTH+SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "New Game", "resources/fonts/helvetica.ttf",
            MLV_rgba(0,0,0,255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { std::cout << "new Game" << std::endl; }
    ));
    std::for_each(this->drawables.begin(), this->drawables.end(), [this](GUI::Drawable *d) { this->observer.add(d); });
    this->drawables.push_back(new GUI::Button(
            WIDTH/2-(BUTTON_WIDTH/2), 2*HEIGHT/NUMBER_BUTTON - (BUTTON_HEIGTH+SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Create", "resources/fonts/helvetica.ttf",
            MLV_rgba(0,0,0,255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { std::cout << "create" << std::endl; }
    ));
    std::for_each(this->drawables.begin(), this->drawables.end(), [this](GUI::Drawable *d) { this->observer.add(d); });
    this->drawables.push_back(new GUI::Button(
            WIDTH/2-(BUTTON_WIDTH/2), 3*HEIGHT/NUMBER_BUTTON - (BUTTON_HEIGTH+SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Edit", "resources/fonts/helvetica.ttf",
            MLV_rgba(0,0,0,255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { std::cout << "edit" << std::endl; }
    ));
    std::for_each(this->drawables.begin(), this->drawables.end(), [this](GUI::Drawable *d) { this->observer.add(d); });
    this->drawables.push_back(new GUI::Button(
            WIDTH/2-(BUTTON_WIDTH/2), 4*HEIGHT/NUMBER_BUTTON - (BUTTON_HEIGTH+SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Exit", "resources/fonts/helvetica.ttf",
            MLV_rgba(0,0,0,255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { std::cout << "exit" << std::endl; }
    ));
    std::for_each(this->drawables.begin(), this->drawables.end(), [this](GUI::Drawable *d) { this->observer.add(d); });
}


Menu *Menu::getInstance() {
    if (!Menu::instance.initialized) {
        Menu::instance.init();
    }
    return &Menu::instance;
}


void Menu::draw() {
    MLV_clear_window(MLV_COLOR_BLACK);
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



