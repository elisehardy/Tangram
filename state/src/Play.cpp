#include "../include/Menu.hpp"
#include "../include/Play.hpp"


using namespace State;
using namespace Game;

Play Play::instance = Play();


void Play::init() {
    uint16_t x = 5*WIDTH / 6 ;
    uint16_t y = 0;

    auto create = new GUI::Button(
            x, 2 * y, BUTTON_WIDTH, BUTTON_HEIGTH, 1,
            "Create", "resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](Game::Engine &e) { std::cout << "create" << std::endl; }
    );
    this->player = Shape::ShapeSet(Shape::Point(100, 100));
    this->goal = Shape::ShapeSet(Shape::Point(100, 100));
    this->initialized = true;
    
    for (Shape::Polygon *p: this->player) {
        this->observer.add(p);
    }
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
    MLV_draw_rectangle(image_goal.first, image_goal.second, Game::WIDTH-(2*10), Game::HEIGHT-(2*10), MLV_COLOR_WHITE);
    std::for_each(this->drawables.begin(), this->drawables.end(), [](GUI::Drawable *d) { d->draw(); });
    this->player.draw();
}


void Play::update(const Game::Event &event, Game::Engine &engine) {
    observer.notify(event, engine);
}


void Play::cleanup() {
}


void Play::pause() {
}


void Play::resume() {
}



