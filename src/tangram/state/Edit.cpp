#include <algorithm>
#include <fstream>
#include <filesystem>

#include <MLV/MLV_text.h>

#include <tangram/state/Edit.hpp>
#include <tangram/geometry/Parser.hpp>
#include <tangram/gui/Button.hpp>
#include <tangram/gui/ShapePreview.hpp>
#include <tangram/gui/Line.hpp>


namespace fs = std::filesystem;

namespace tangram::state {
    
    void Edit::init() {
        static constexpr int16_t BUTTON_WIDTH = 140;
        static constexpr int16_t BUTTON_HEIGHT = 50;
        static constexpr int16_t BUTTON_X = MENU_SEPARATOR + ((game::WIDTH - MENU_SEPARATOR) / 2) - (BUTTON_WIDTH / 2);
        
        this->hovered = true;
        
        auto saveButton = std::make_shared<gui::Button>(
            BUTTON_X, game::HEIGHT / 2, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Save", "../resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            &save
        );
        auto menuButton = std::make_shared<gui::Button>(
            BUTTON_X, game::HEIGHT / 2 + 100, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Menu", "../resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { e.popState(); }
        );
        auto quitButton = std::make_shared<gui::Button>(
            BUTTON_X, game::HEIGHT / 2 + 200, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "Quit", "../resources/fonts/helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { e.stop(); }
        );
        
        this->updatables.push_back(saveButton);
        this->updatables.push_back(menuButton);
        this->updatables.push_back(quitButton);
        
        this->drawables.push_back(saveButton);
        this->drawables.push_back(menuButton);
        this->drawables.push_back(quitButton);
        this->drawables.push_back(std::make_shared<gui::Line>(
            MLV_COLOR_WHITE, MENU_SEPARATOR, 0, MENU_SEPARATOR, game::HEIGHT
        ));
        
        this->initialized = true;
    }
    
    
    void Edit::save(game::Engine &engine) {
        Edit *edit = dynamic_cast<Edit *>(engine.current());
        std::ofstream file = std::ofstream(game::SHAPE_DIR + edit->title + ".shp");
        file << edit->player;
        file.close();
    }
    
    
    Edit *Edit::getInstance() {
        static Edit Edit;
        
        if (!Edit.initialized) {
            Edit.init();
        }
        return &Edit;
    }
    
    
    Edit *Edit::loadShape(const std::string &path) {
        geometry::Parser parser;
        this->title = fs::path(path).stem();
        this->player = parser(path);
        this->cleanup();
        this->init();
        
        return this;
    }
    
    
    void Edit::draw() const {
        static constexpr double PREVIEW_SCALE_FACTOR = 0.40;
        static constexpr int16_t PREVIEW_SIDE = static_cast<int16_t>(MENU_SEPARATOR * PREVIEW_SCALE_FACTOR);
        static constexpr int16_t PREVIEW_X = MENU_SEPARATOR + ((game::WIDTH - MENU_SEPARATOR) / 2) - (PREVIEW_SIDE / 2);
        static constexpr int16_t PREVIEW_Y = 50;
        
        MLV_clear_window(MLV_COLOR_BLACK);
        
        std::for_each(
            this->drawables.begin(), this->drawables.end(),
            [](auto d) { d.get()->draw(); }
        );
        
        this->player.draw();
        
        gui::ShapePreview(
            this->player, PREVIEW_SCALE_FACTOR, MENU_SEPARATOR, PREVIEW_X, PREVIEW_Y, MLV_COLOR_GREY50
        ).draw();
    }
    
    
    void Edit::update(const game::Event &event, game::Engine &engine) {
        game::Updatable::update(event, engine);
        
        if (isKeyClicked(MLV_KEYBOARD_ESCAPE)) {
            engine.popState();
            return;
        }
        
        std::for_each(
            this->updatables.begin(), this->updatables.end(),
            [&](auto u) { u->update(event, engine); }
        );
        
        this->player.update(event, engine);
        this->player.ensureInbounds({ 0, 0 }, { MENU_SEPARATOR, game::HEIGHT });
    }
    
    
    void Edit::cleanup() {
        this->initialized = false;
        this->drawables.clear();
        this->updatables.clear();
    }
    
    
    void Edit::pause() {
    }
    
    
    void Edit::resume() {
    }
}
