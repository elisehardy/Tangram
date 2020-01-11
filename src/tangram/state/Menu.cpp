#include <algorithm>
#include <memory>

#include <tangram/state/Create.hpp>
#include <tangram/state/Menu.hpp>
#include <tangram/state/Load.hpp>

namespace tangram::state {
    
    void Menu::init() {
        static constexpr uint16_t BUTTON_WIDTH = 140;
        static constexpr uint16_t BUTTON_HEIGHT = 50;
        static constexpr uint16_t NUMBER_BUTTON = 5;
        static constexpr uint16_t SPACE_2_BUTTON = 5;
        
        uint16_t x = game::WIDTH / 2 - (BUTTON_WIDTH / 2);
        
        auto new_game = std::make_shared<gui::ButtonText>(
            x, 1 * game::HEIGHT / NUMBER_BUTTON - (BUTTON_HEIGHT + SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "New game", game::FONT_DIR + "helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { return e.pushState(Play::getInstance()); }
        );
        auto create = std::make_shared<gui::ButtonText>(
            x, 2 * game::HEIGHT / NUMBER_BUTTON - (BUTTON_HEIGHT + SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Create", game::FONT_DIR + "helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { return e.pushState(Create::getInstance()); }
        );
        auto edit = std::make_shared<gui::ButtonText>(
            x, 3 * game::HEIGHT / NUMBER_BUTTON - (BUTTON_HEIGHT + SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Edit", game::FONT_DIR + "helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { return e.pushState(Load::getInstance()); }
        );
        auto quit = std::make_shared<gui::ButtonText>(
            x, 4 * game::HEIGHT / NUMBER_BUTTON - (BUTTON_HEIGHT + SPACE_2_BUTTON), BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Exit", game::FONT_DIR + "helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { return e.stop(); }
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
        static Menu menu;
        
        if (!menu.initialized) {
            menu.init();
        }
        return &menu;
    }
    
    
    void Menu::draw() const {
        MLV_clear_window(MLV_COLOR_BLACK);
        std::for_each(this->drawables.begin(), this->drawables.end(), [](const auto &d) { d->draw(); });
    }
    
    
    bool Menu::update(const game::Event &event, game::Engine &engine) {
        return (std::find_if(
            this->updatables.begin(), this->updatables.end(),
            [&](auto u) { return u->update(event, engine); }
        ) != this->updatables.end());
    }
    
    
    void Menu::cleanup() {
        this->initialized = false;
        this->drawables.clear();
        this->updatables.clear();
    }
    
    
    void Menu::pause() {
    }
    
    
    void Menu::resume() {
    }
}
