#include <algorithm>
#include <fstream>

#include <MLV/MLV_text.h>
#include <MLV/MLV_shape.h>

#include <tangram/state/Create.hpp>


using namespace tangram;

namespace tangram::state {
    
    void Create::init() {
        auto saveButtonn = new gui::Button(
            BUTTON_X, game::HEIGHT / 2, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Save", "../resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            &save
        );
        auto menuButtonn = new gui::Button(
            BUTTON_X, game::HEIGHT / 2 + 100, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Menu", "../resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { e.stop(); }
        );
        auto quitButtonn = new gui::Button(
            BUTTON_X, game::HEIGHT / 2 + 200, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Quit", "../resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { e.stop(); }
        );
        
        this->player = geometry::Shape::square(geometry::Point16(0, 0));
        
        this->updatables.push_back(&this->player);
        this->updatables.push_back(saveButtonn);
        this->updatables.push_back(menuButtonn);
        this->updatables.push_back(quitButtonn);
        this->drawables.push_back(saveButtonn);
        this->drawables.push_back(menuButtonn);
        this->drawables.push_back(quitButtonn);
        
        this->initialized = true;
    }
    
    
    void Create::save(game::Engine &engine) {
        static constexpr int16_t INBOX_WIDTH = 200;
        static constexpr int16_t INBOX_X = game::WIDTH / 2 - INBOX_WIDTH / 2;
        static constexpr int16_t INBOX_Y = game::HEIGHT / 2 - BUTTON_HEIGHT / 2;
        MLV_Font *font = MLV_load_font((game::FONT_DIR + "helvetica.ttf").c_str(), 20);
        char *tmp;
        
        MLV_wait_input_box_with_font(
            INBOX_X, INBOX_Y, INBOX_WIDTH, BUTTON_HEIGHT,
            MLV_COLOR_BLACK, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            " Title :", &tmp, font
        );
        
        std::string title = std::string(tmp);
        free(tmp);
        free(font);
        
        std::ofstream file = std::ofstream(game::SHAPE_DIR + title + ".shp");
        file << dynamic_cast<Create *>(engine.current())->player;
        file.close();
    }
    
    
    Create *Create::getInstance() {
        static Create create;
        
        if (!create.initialized) {
            create.init();
        }
        return &create;
    }
    
    
    void Create::draw() const {
        MLV_clear_window(MLV_COLOR_BLACK);
        std::for_each(
            this->drawables.begin(), this->drawables.end(),
            [](gui::Drawable *d) { d->draw(); }
        );
        this->player.draw();
        this->goal.draw();
        MLV_draw_line(MENU_SEPARATOR, 0, MENU_SEPARATOR, game::HEIGHT, MLV_COLOR_WHITE);
        MLV_draw_line(PREVIEW_X, PREVIEW_Y, PREVIEW_X + PREVIEW_SIDE, PREVIEW_Y, MLV_COLOR_WHITE);
        MLV_draw_line(PREVIEW_X, PREVIEW_Y, PREVIEW_X, PREVIEW_Y + PREVIEW_SIDE, MLV_COLOR_WHITE);
        MLV_draw_line(
            PREVIEW_X + PREVIEW_SIDE, PREVIEW_Y,
            PREVIEW_X + PREVIEW_SIDE, PREVIEW_Y + PREVIEW_SIDE,
            MLV_COLOR_WHITE
        );
        MLV_draw_line(
            PREVIEW_X, PREVIEW_Y + PREVIEW_SIDE,
            PREVIEW_X + PREVIEW_SIDE, PREVIEW_Y + PREVIEW_SIDE,
            MLV_COLOR_WHITE
        );
    }
    
    
    void Create::update(const game::Event &event, game::Engine &engine) {
        std::for_each(
            this->updatables.begin(), this->updatables.end(),
            [&](game::Updatable *u) { u->update(event, engine); }
        );
        
        this->player.ensureInbounds({ 0, 0 }, { MENU_SEPARATOR, game::HEIGHT });
        this->goal = geometry::Shape(this->player);
        this->goal.scale(PREVIEW_SCALE_FACTOR).translate(PREVIEW_X, PREVIEW_Y).setColor(MLV_COLOR_GREY50);
    }
    
    
    void Create::cleanup() {
    }
    
    
    void Create::pause() {
    }
    
    
    void Create::resume() {
    }
}
