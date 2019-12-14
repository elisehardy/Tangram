#include "../include/Menu.hpp"

#include <algorithm>


using namespace tangram;
using namespace tangram::state;

Menu Menu::instance = Menu();


void Menu::init() {
    uint16_t x = game::WIDTH / 2 - (BUTTON_WIDTH / 2);
    
    auto new_game = new gui::Button(
            x, 1 * game::HEIGHT / NUMBER_BUTTON - (BUTTON_HEIGTH + SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "New game", "resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { e.pushState(state::Play::getInstance()); }
    );
    auto create = new gui::Button(
            x, 2 * game::HEIGHT / NUMBER_BUTTON - (BUTTON_HEIGTH + SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Create", "resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { std::cout << "create" << std::endl; }
    );
    auto edit = new gui::Button(
            x, 3 * game::HEIGHT / NUMBER_BUTTON - (BUTTON_HEIGTH + SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Edit", "resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { e.pushState(state::Edit::getInstance()); }
    );
    auto quit = new gui::Button(
            x, 4 * game::HEIGHT / NUMBER_BUTTON - (BUTTON_HEIGTH + SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Exit", "resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { e.stop(); }
    );
    
    this->drawables.push_back(new_game);
    this->drawables.push_back(create);
    this->drawables.push_back(edit);
    this->drawables.push_back(quit);
    this->updatables.push_back(new_game);
    this->updatables.push_back(create);
    this->updatables.push_back(edit);
    this->updatables.push_back(quit);
}


Menu *Menu::getInstance() {
    if (!Menu::instance.initialized) {
        Menu::instance.init();
    }
    return &Menu::instance;
}


void Menu::draw() const {
    MLV_clear_window(MLV_COLOR_BLACK);
    std::for_each(this->drawables.begin(), this->drawables.end(), [](gui::Drawable *d) { d->draw(); });
}


void Menu::update(const game::Event &event, game::Engine &engine) {
    std::for_each(
            this->updatables.begin(), this->updatables.end(),
            [&](game::Updatable *u) { u->update(event, engine); }
    );
}


void Menu::cleanup() {
}


void Menu::pause() {
}


void Menu::resume() {
}



