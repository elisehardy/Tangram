#include <algorithm>

#include <MLV/MLV_shape.h>

#include <tangram/state/Play.hpp>
#include <tangram/gui/Button.hpp>

namespace tangram::state {
    
    void Play::init() {
        static constexpr uint16_t BUTTON_WIDTH = 140;
        static constexpr uint16_t BUTTON_HEIGHT = 50;
        int16_t x = 5 * game::WIDTH / 6;
        
        auto create = new gui::Button(
            x, 0, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Create", "../resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { std::cout << "create" << std::endl; }
        );
        
        this->player = geometry::Shape::square(geometry::Point16(100, 100));
        this->goal = geometry::Shape::square(geometry::Point16(100, 100));
        
        this->updatables.push_back(create);
        this->updatables.push_back(&this->player);
        this->drawables.push_back(create);
        this->drawables.push_back(&this->player);
        
        this->initialized = true;
    }
    
    
    Play *Play::getInstance() {
        static Play play;
        
        if (!play.initialized) {
            play.init();
        }
        
        return &play;
    }
    
    
    void Play::draw() const {
        MLV_clear_window(MLV_COLOR_BLACK);
        MLV_draw_rectangle(goal_x, goal_y, game::WIDTH - (2 * 10), game::HEIGHT - (2 * 10),
                           MLV_COLOR_WHITE
        );
        std::for_each(this->drawables.begin(), this->drawables.end(), [](gui::Drawable *d) { d->draw(); });
        this->player.draw();
    }
    
    
    void Play::update(const game::Event &event, game::Engine &engine) {
        std::for_each(
            this->updatables.begin(), this->updatables.end(),
            [&](game::Updatable *u) { u->update(event, engine); }
        );
        
        if (this->player == this->goal) {
            // TODO Partie terminée
        }
    }
    
    
    void Play::cleanup() {
    }
    
    
    void Play::pause() {
    }
    
    
    void Play::resume() {
    }
}
