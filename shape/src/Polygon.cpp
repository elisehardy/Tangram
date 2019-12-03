#include "../include/Polygon.hpp"


using namespace Shape;


Polygon::Polygon(MLV_Color t_color) :
        color(t_color), hovered(false), lpressed(false), rpressed(false) {
}


void Polygon::updateCenter() {
    this->center = Point::center(points);
}


std::vector<Point> Polygon::getPoints() const {
    return this->points;
}


void Polygon::translate(const Vector &p) {
    for (auto &point : this->points) {
        point = point.translate(p);
    }
    this->updateCenter();
}


void Polygon::rotate(int8_t n) {
    int8_t angle = n * ANGLE_STEP;
    for (auto &p : points) {
        p = p.rotate(angle, this->center);
    }
}


bool Polygon::contains(const Point &p) {
    return this->contains(p.first, p.second);
}


void Polygon::draw() const {
    uint8_t size = this->points.size(), i = 0;
    int32_t X[size], Y[size];
    uint8_t r, g, b, a;
    MLV_Color col;
    
    for (auto &p: this->points) {
        X[i] = p.first;
        Y[i++] = p.second;
    }
    
    col = this->color;
    if (this->hovered) {
        MLV_convert_color_to_rgba(this->color, &r, &g, &b, &a);
        col = MLV_rgba(r * 0.5, g * 0.5, b * 0.5, a);
    }
    
    MLV_draw_filled_polygon(X, Y, size, col);
}


void Polygon::update(const Game::Event &event, Game::Engine &engine) {
    Point mousePos = Point(event.mousePos.first, event.mousePos.second);
    bool leftClick = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_LEFT;
    bool rightClick = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_RIGHT;
    
    this->hovered = this->contains(mousePos);
    
    if (this->hovered && leftClick && event.state == MLV_PRESSED) {  // Pressed on left button
        this->lpressed = true;
    }
    if (this->hovered && leftClick && event.state == MLV_RELEASED) {  // Left button released
        this->lpressed = false;
    }
    if (this->lpressed) { // Moving the Polygon
        this->translate(mousePos - this->center);
    }
    
    if (this->hovered && rightClick && event.state == MLV_PRESSED) {  // Pressed on  right button
        this->rpressed = true;
    }
    else if (this->rpressed && rightClick && event.state == MLV_RELEASED) { // Left click released
        if (this->hovered) { // Released on button
            this->rpressed = false;
            this->rotate(1);
        }
        else { // Released outside button
            this->rpressed = false;
        }
    }
}





