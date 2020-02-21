#include <algorithm>
#include <fstream>

#include <MLV/MLV_text.h>
#include <MLV/MLV_shape.h>

#include <tangram/state/Play.hpp>
#include <tangram/gui/ButtonText.hpp>
#include <tangram/gui/ShapePreview.hpp>


#ifdef USE_STD_FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif


namespace tangram::state {
    
    void Play::init() {
        static constexpr int16_t BUTTON_WIDTH = 140;
        static constexpr int16_t BUTTON_HEIGHT = 50;
        static constexpr int16_t BUTTON_X = MENU_SEPARATOR + ((game::WIDTH - MENU_SEPARATOR) / 2) - (BUTTON_WIDTH / 2);
        
        this->hovered = true;
        this->success = false;
        this->player = geometry::Shape::square();
        
        auto menuButton = std::make_shared<gui::ButtonText>(
                BUTTON_X, game::HEIGHT / 2 + 50, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
                "Menu", "../resources/fonts/helvetica.ttf",
                MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
                MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
                MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
                [](game::Engine &e) { return e.popState(); }
        );
        auto quitButton = std::make_shared<gui::ButtonText>(
                BUTTON_X, game::HEIGHT / 2 + 150, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
                "Quit", "../resources/fonts/helvetica.ttf",
                MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
                MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
                MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
                [](game::Engine &e) { return e.stop(); }
        );
        
        this->updatables.push_back(menuButton);
        this->updatables.push_back(quitButton);
        
        this->drawables.push_back(menuButton);
        this->drawables.push_back(quitButton);
        
        this->initialized = true;
    }
    
    
    Play *Play::getInstance() {
        static Play Play;
        
        if (!Play.initialized) {
            Play.init();
        }
        return &Play;
    }
    
    
    Play *Play::loadShape(const std::string &path) {
        this->title = fs::path(path).stem();
        this->goal = geometry::Shape::load(path);
        this->shadow = this->goal.getRandomPolygon();
        this->shadow.setColor(MLV_COLOR_GREY10);
        this->cleanup();
        this->init();
        
        return this;
    }
    
    
    void Play::draw() const {
        static constexpr double PREVIEW_SCALE_FACTOR = 0.40;
        static constexpr int16_t PREVIEW_SIDE = static_cast<int16_t>(MENU_SEPARATOR * PREVIEW_SCALE_FACTOR);
        static constexpr int16_t PREVIEW_X = MENU_SEPARATOR + ((game::WIDTH - MENU_SEPARATOR) / 2) - (PREVIEW_SIDE / 2);
        static constexpr int16_t PREVIEW_Y = 100;
        
        MLV_clear_window(MLV_COLOR_BLACK);
        
        int32_t titleWidth, titleHeight, titleX, titleY;
        MLV_Font *font = MLV_load_font((game::FONT_DIR + "helvetica.ttf").c_str(), 40);
        MLV_get_size_of_text_with_font(this->title.c_str(), &titleWidth, &titleHeight, font);
        titleX = MENU_SEPARATOR + ((game::WIDTH - MENU_SEPARATOR) / 2) - (titleWidth / 2);
        titleY = PREVIEW_Y / 2 - titleHeight / 2;
        MLV_draw_text_with_font(titleX, titleY, this->title.c_str(), font, MLV_COLOR_WHITE);
        MLV_free_font(font);
        
        MLV_draw_line(MENU_SEPARATOR, 0, MENU_SEPARATOR, game::HEIGHT, MLV_COLOR_WHITE);
        
        std::for_each(
                this->drawables.begin(), this->drawables.end(),
                [](auto d) { d->draw(); }
        );
        
        this->shadow.draw();
        this->player.draw();
        
        gui::ShapePreview(
                this->goal, PREVIEW_SCALE_FACTOR, MENU_SEPARATOR, PREVIEW_X, PREVIEW_Y, MLV_COLOR_GREY50
        ).draw();
        
        if (this->success) {
            font = MLV_load_font((game::FONT_DIR + "helvetica.ttf").c_str(), 40);
            MLV_get_size_of_text_with_font("Win !", &titleWidth, &titleHeight, font);
            MLV_draw_text_with_font(game::HEIGHT / 2 - titleWidth / 2, game::HEIGHT / 2 - titleHeight / 2, "Win !",
                                    font, MLV_COLOR_WHITE
            );
            MLV_free_font(font);
        }
    }
    
    
    bool Play::update(const game::Event &event, game::Engine &engine) {
        game::Updatable::update(event, engine);
        
        if (isKeyClicked(MLV_KEYBOARD_ESCAPE)) {
            return engine.popState();
        }
        
        if (!this->success) {
            this->player.update(event, engine);
            this->player.ensureInbounds({ 0, 0 }, { MENU_SEPARATOR, game::HEIGHT });
        }
        
        if (this->player == this->goal) {
            this->player.setColor(MLV_COLOR_GREY50);
            this->success = true;
        }
        
        return (std::find_if(
                this->updatables.begin(), this->updatables.end(),
                [&](auto u) { return u->update(event, engine); }
        ) != this->updatables.end());
    }
    
    
    void Play::cleanup() {
        this->initialized = false;
        this->drawables.clear();
        this->updatables.clear();
    }
    
    
    void Play::pause() {
    }
    
    
    void Play::resume() {
    }
}
