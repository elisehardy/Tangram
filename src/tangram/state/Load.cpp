#include <algorithm>

#include <MLV/MLV_shape.h>

#include <tangram/state/Load.hpp>
#include <tangram/geometry/Parser.hpp>

#ifdef USE_STD_FILESYSTEM
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

namespace tangram::state {
    
    static void drawDelButton(int16_t x, int16_t y, int16_t w, int16_t h) {
        MLV_draw_filled_rectangle(x, y, w, h, MLV_COLOR_RED);
        MLV_draw_line(x, y, x + w, y + h, MLV_COLOR_BLACK);
        MLV_draw_line(x + w, y, x, y + h, MLV_COLOR_BLACK);
    }
    
    
    static void drawHDelButton(int16_t x, int16_t y, int16_t w, int16_t h) {
        MLV_draw_filled_rectangle(x, y, w, h, MLV_rgba(178, 0, 0, 255));
        MLV_draw_line(x, y, x + w, y + h, MLV_rgba(77, 77, 77, 255));
        MLV_draw_line(x + w, y, x, y + h, MLV_rgba(77, 77, 77, 255));
    }
    
    
    static void drawCDelButton(int16_t x, int16_t y, int16_t w, int16_t h) {
        MLV_draw_filled_rectangle(x, y, w, h, MLV_rgba(102, 0, 0, 255));
        MLV_draw_line(x, y, x + w, y + h, MLV_rgba(153, 153, 153, 255));
        MLV_draw_line(x + w, y, x, y + h, MLV_rgba(153, 153, 153, 255));
    }
    
    
    bool Load::deleteShape(game::Engine &engine, const std::string &path) {
        Load *load = Load::getInstance();
        uint16_t page = load->page;
        
        fs::remove(path);
        load->cleanup();
        load->init();
        load->page = page;
        
        if (load->previews.size() <= page * 6 && page != 0) {
            load->page--;
        }
        
        return true;
    }
    
    
    void Load::init() {
        static constexpr double PREVIEW_SCALE_FACTOR = 0.35;
        static constexpr int16_t PREVIEW_SIDE = static_cast<int16_t>(game::HEIGHT * PREVIEW_SCALE_FACTOR);
        static constexpr int16_t DEL_BUTTON_SIDE = static_cast<int16_t>(PREVIEW_SIDE * 0.1);
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
            
            //            std::cout << "Before emplace" << std::endl;
            this->prevButtons.emplace(
                    entry.path(),
                    gui::ButtonText(
                            x + PREVIEW_SIDE / 4, y + PREVIEW_SIDE + 5, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
                            fs::path(entry).stem(), game::FONT_DIR + "helvetica.ttf",
                            MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                            MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
                            MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
                            MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
                            std::bind([](game::Engine &e, const std::string &s) {
                                e.popState();
                                return e.pushState(
                                        static_cast<state::State *>(Load::getInstance()->nextState->loadShape(s))
                                );
                            }, std::placeholders::_1, entry.path())
                    )
            );
            //            std::cout << "After emplace" << std::endl;
            
            this->delButtons.emplace(
                    entry.path(),
                    gui::ButtonDraw(
                            x + PREVIEW_SIDE - DEL_BUTTON_SIDE - 1, y + 2, DEL_BUTTON_SIDE, DEL_BUTTON_SIDE,
                            drawDelButton, drawHDelButton, drawCDelButton,
                            std::bind(&deleteShape, std::placeholders::_1, entry.path())
                    )
            );
            
            this->prevOrder.push_back(entry.path());
            
            i = (i + 1) % 3;
            if (i == 0) {
                j = (j + 1) % 2;
            }
        }
        
        y = game::HEIGHT - BUTTON_HEIGHT - 20;
        x = game::WIDTH / 2;
        
        this->next = std::make_unique<gui::ButtonText>(
                x + BUTTON_WIDTH * 0.5, y, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
                "-->", game::FONT_DIR + "helvetica.ttf",
                MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
                MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
                MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
                [](game::Engine &e) {
                    Load::getInstance()->page++;
                    return false;
                }
        );
        this->prev = std::make_unique<gui::ButtonText>(
                x - BUTTON_WIDTH * 1.5, y, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
                "<--", game::FONT_DIR + "helvetica.ttf",
                MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
                MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
                MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
                [](game::Engine &e) {
                    Load::getInstance()->page--;
                    return false;
                }
        );
        this->menu = std::make_unique<gui::ButtonText>(
                x - BUTTON_WIDTH / 2, 0, BUTTON_WIDTH, BUTTON_HEIGHT, 1,
                "Menu", game::FONT_DIR + "helvetica.ttf",
                MLV_rgba(0, 0, 0, 255), MLV_COLOR_BLACK, MLV_COLOR_WHITE,
                MLV_COLOR_GREY70, MLV_COLOR_BLACK, MLV_COLOR_GREY70,
                MLV_COLOR_GREY40, MLV_COLOR_BLACK, MLV_COLOR_GREY40,
                MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER,
                [](game::Engine &e) { return e.popState(); }
        );
    }
    
    
    Load *Load::getInstance() {
        static Load menu;
        
        if (!menu.initialized) {
            menu.init();
        }
        
        return &menu;
    }
    
    
    Load *Load::setNextState(ShapeLoaderState *nextState) {
        this->nextState = nextState;
        return this;
    }
    
    
    void Load::pause() {
    }
    
    
    void Load::resume() {
    }
    
    
    void Load::cleanup() {
        this->initialized = false;
        this->prevButtons.clear();
        this->previews.clear();
        this->delButtons.clear();
        this->prevOrder.clear();
    }
    
    
    bool Load::update(const game::Event &event, game::Engine &engine) {
        game::Updatable::update(event, engine);
        
        if (isKeyClicked(MLV_KEYBOARD_ESCAPE)) {
            return engine.popState();
        }
        
        bool lastPage = (page + 1) * 6u >= this->previews.size();
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
        if (this->menu->update(event, engine)) {
            return true;
        }
        
        if (!firstPage && (isKeyClicked(MLV_KEYBOARD_q) || isKeyClicked(MLV_KEYBOARD_LEFT))) {
            this->page--;
        }
        
        if (!lastPage && (isKeyClicked(MLV_KEYBOARD_d) || isKeyClicked(MLV_KEYBOARD_RIGHT))) {
            this->page++;
        }
        
        auto begin = std::next(this->prevOrder.begin(), std::min(static_cast<int>(this->previews.size()), page * 6));
        auto end = std::next(this->prevOrder.begin(), std::min(static_cast<int>(this->previews.size()), page * 6 + 6));
        if (std::find_if(begin, end, [&](const auto &s) { return this->delButtons.at(s).update(event, engine); })
            != end) {
            return false;
        }
        
        return (std::find_if(
                begin, end,
                [&](const auto &s) { return this->prevButtons.at(s).update(event, engine); }
        ) != end);
    }
    
    
    void Load::draw() const {
        MLV_clear_window(MLV_COLOR_BLACK);
        
        std::for_each(
                std::next(this->prevOrder.begin(), std::min(static_cast<int>(this->previews.size()), page * 6)),
                std::next(this->prevOrder.begin(), std::min(static_cast<int>(this->previews.size()), page * 6 + 6)),
                [this](const auto &s) {
                    this->prevButtons.at(s).draw();
                    this->previews.at(s).draw();
                    this->delButtons.at(s).draw();
                }
        );
        
        this->next->draw();
        this->prev->draw();
        this->menu->draw();
        
        MLV_Font *font = MLV_load_font((game::FONT_DIR + "helvetica.ttf").c_str(), 24);
        MLV_draw_text_with_font(
                game::WIDTH / 2 - 3, game::HEIGHT - 47, std::to_string(this->page).c_str(), font, MLV_COLOR_WHITE
        );
        MLV_free_font(font);
    }
}
