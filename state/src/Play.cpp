#include "../include/Play.hpp"


using namespace tangram;
using namespace tangram::state;

Play Play::instance = Play();


void Play::init() {
    this->player = geometry::Shape::square(geometry::Point(100, 100));
    this->goal = geometry::Shape::square(geometry::Point(100, 100));
    uint16_t x = 5 * game::WIDTH / 6;
    
    auto create = new gui::Button(
            x, 0, tangram::state::BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Create", "resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { std::cout << "create" << std::endl; }
    );
    this->initialized = true;
    
    this->observer.add(create);
    this->drawables.push_back(create);
}


Play *Play::getInstance() {
    if (!Play::instance.initialized) {
        Play::instance.init();
    }
    return &Play::instance;
}


void Play::draw() {
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_draw_rectangle(image_goal.first, image_goal.second, game::WIDTH - (2 * 10), game::HEIGHT - (2 * 10),
                       MLV_COLOR_WHITE
    );
    std::for_each(this->drawables.begin(), this->drawables.end(), [](gui::Drawable *d) { d->draw(); });
    this->player.draw();
}


void Play::update(const game::Event &event, game::Engine &engine) {
    observer.notify(event, engine);
    this->player.update(event, engine);
    
    if (this->player == this->goal) {
        // TODO Partie terminée
    }
}


void Play::cleanup() {
    initialized = false;
}


void Play::pause() {
}


void Play::resume() {
}



