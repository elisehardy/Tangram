#include <filesystem>
#include <algorithm>

#include <tangram/state/Load.hpp>
#include <tangram/geometry/Parser.hpp>


namespace fs = std::filesystem;

namespace tangram::state {
    
    void Load::init() {
        static constexpr double PREVIEW_SCALE_FACTOR = 0.35;
        static constexpr int16_t PREVIEW_SIDE = static_cast<int16_t>(game::HEIGHT * PREVIEW_SCALE_FACTOR);
        static constexpr int16_t OFFSET_X = (game::WIDTH - PREVIEW_SIDE * 3) / 4;
        static constexpr int16_t OFFSET_Y = (game::HEIGHT - PREVIEW_SIDE * 2) / 4;
        static constexpr int16_t BUTTON_WIDTH = PREVIEW_SIDE / 2;
        static constexpr int16_t BUTTON_HEIGHT = 30;
        
        int16_t i = 0, j = 0, x, y;
        geometry::Parser parser;
        
        this->initialized = true;
        this->hovered = true;
        this->page = 0;
        
        for (const auto &entry : fs::directory_iterator(game::SHAPE_DIR)) {
            x = OFFSET_X + i * OFFSET_X + i * PREVIEW_SIDE;
            y = OFFSET_Y + j * OFFSET_Y + j * PREVIEW_SIDE;
            
            this->previews.emplace(
                entry.path(),
                gui::ShapePreview(parser(entry.path()), PREVIEW_SCALE_FACTOR, game::HEIGHT, x, y)
            );
            
            std::cout << "Before empalce" << std::endl;
            this->prevButtons.emplace(
                entry.path(),
                gui::Button(
                    x + PREVIEW_SIDE / 4, y + PREVIEW_SIDE + 5, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
                    fs::path(entry).stem(), game::FONT_DIR + "helvetica.ttf",
                    MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                    MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
                    MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
                    MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
                    [](game::Engine &e) { e.stop(); }
                )
            );
            std::cout << "After emplace" << std::endl;
            i = (i + 1) % 3;
            if (i == 0) {
                j = (j + 1) % 2;
            }
        }
        
        y = game::HEIGHT - BUTTON_HEIGHT - 20;
        x = game::WIDTH / 2;
        
        this->next = std::make_unique<gui::Button>(
            x + BUTTON_WIDTH * 0.5, y, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "-->", game::FONT_DIR + "helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { dynamic_cast<Load *>(e.current())->page++; }
        );
        this->prev = std::make_unique<gui::Button>(
            x - BUTTON_WIDTH * 1.5, y, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
            "<--", game::FONT_DIR + "helvetica.ttf",
            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
            [](game::Engine &e) { dynamic_cast<Load *>(e.current())->page--; }
        );
    }
    
    
    Load *Load::getInstance() {
        static Load menu;
        
        if (!menu.initialized) {
            menu.init();
        }
        
        return &menu;
    }
    
    
    void Load::pause() {
    }
    
    
    void Load::resume() {
    }
    
    
    void Load::cleanup() {
        this->initialized = false;
        this->prevButtons.clear();
        this->previews.clear();
    }
    
    
    void Load::update(const game::Event &event, game::Engine &engine) {
        game::Updatable::update(event, engine);
        
        if (isKeyClicked(MLV_KEYBOARD_ESCAPE)) {
            engine.popState();
            return;
        }
        
        std::for_each(
            std::next(this->prevButtons.begin(), page * 6),
            std::next(this->prevButtons.begin(), std::max(static_cast<int>(this->prevButtons.size()), page * 6 + 6)),
            [&](auto &b) { b.second.update(event, engine); }
        );
    
        bool lastPage = (page + 1) * 6 >= this->previews.size();
        bool firstPage = page == 0;
        this->next->enable();
        this->prev->enable();
        if (firstPage) {
            this->prev->disable();
        }
        if (lastPage) {
            this->next->disable();
        }
        
        this->next->update(event, engine);
        this->prev->update(event, engine);
    
        
        if (!firstPage && (isKeyClicked(MLV_KEYBOARD_q) || isKeyClicked(MLV_KEYBOARD_LEFT))) {
            this->page--;
        }
        
        if (!lastPage && (isKeyClicked(MLV_KEYBOARD_d) || isKeyClicked(MLV_KEYBOARD_RIGHT))) {
            this->page++;
        }
    }
    
    
    void Load::draw() const {
        int32_t boffset = std::min(static_cast<int>(this->previews.size()), page * 6);
        int32_t eoffset = std::min(static_cast<int>(this->previews.size()), page * 6 + 6);
        
        MLV_clear_window(MLV_COLOR_BLACK);
        
        std::for_each(
            std::next(this->previews.begin(), boffset),
            std::next(this->previews.begin(), eoffset),
            [](const auto &p) { p.second.draw(); }
        );
        
        std::for_each(
            std::next(this->prevButtons.begin(), boffset),
            std::next(this->prevButtons.begin(), eoffset),
            [](const auto &b) { b.second.draw(); }
        );
        
        this->next->draw();
        this->prev->draw();
        
        MLV_Font *font = MLV_load_font((game::FONT_DIR + "helvetica.ttf").c_str(), 24);
        MLV_draw_text_with_font(game::WIDTH / 2 - 3, game::HEIGHT - 47, std::to_string(this->page).c_str(), font, MLV_COLOR_WHITE);
        MLV_free_font(font);
    }
}
