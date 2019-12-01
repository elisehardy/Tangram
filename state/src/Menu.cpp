#include "../include/Menu.hpp"

using namespace State;
using namespace Game;

Menu Menu::instance = Menu();


void Menu::init() {
    auto new_game = new GUI::Button(
            WIDTH/2-(BUTTON_WIDTH/2), 1*HEIGHT/NUMBER_BUTTON - (BUTTON_HEIGTH+SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "New Game", "resources/fonts/helvetica.ttf",
            MLV_rgba(0,0,0,255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { std::cout << "new Game" << std::endl; }
    );
    
    auto create = new GUI::Button(
            WIDTH/2-(BUTTON_WIDTH/2), 2*HEIGHT/NUMBER_BUTTON - (BUTTON_HEIGTH+SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Create", "resources/fonts/helvetica.ttf",
            MLV_rgba(0,0,0,255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { std::cout << "create" << std::endl; }
    );

    auto edit = new GUI::Button(
            WIDTH/2-(BUTTON_WIDTH/2), 3*HEIGHT/NUMBER_BUTTON - (BUTTON_HEIGTH+SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Edit", "resources/fonts/helvetica.ttf",
            MLV_rgba(0,0,0,255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { std::cout << "edit" << std::endl; }
    );
    auto quit = new GUI::Button(
            WIDTH/2-(BUTTON_WIDTH/2), 4*HEIGHT/NUMBER_BUTTON - (BUTTON_HEIGTH+SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Exit", "resources/fonts/helvetica.ttf",
            MLV_rgba(0,0,0,255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { e.stop(); }
    );
    this->observer.add({new_game, create, edit, quit});
    this->drawables.push_back(new_game);
    this->drawables.push_back(create);
    this->drawables.push_back(edit);
    this->drawables.push_back(quit);
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



