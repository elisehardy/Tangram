#include <algorithm>
#include <cmath>

#include "../include/Shape.hpp"


using namespace tangram::shape;

const uint16_t Shape::HYPOTENUSE = sqrt(SIDE * SIDE * 2);


Shape::Shape(MLV_Color t_color) :
        color(t_color), hovered(false), lpressed(false), rpressed(false) {
}


void Shape::translate(const Vector &p) {
    for (auto &point : this->getPoints()) {
        point = point.translate(p);
    }
}


void Shape::rotate(int16_t angle, const Point &center) {
    for (auto &p : this->getPoints()) {
        p = p.rotate(angle, center);
    }
}


void Shape::rotate(int16_t angle) {
    this->rotate(angle, this->getCenter());
}


bool Shape::contains(const Point &p) const {
    return this->contains(p.first, p.second);
}


void Shape::draw() const {
    std::vector<Point> points = this->getPoints();
    uint8_t size = points.size(), i = 0;
    int32_t X[size], Y[size];
    uint8_t r, g, b, a;
    MLV_Color col;
    
    for (auto &p: points) {
        X[i] = p.first;
        Y[i++] = p.second;
    }
    
    col = this->color;
    if (this->hovered || this->lpressed || this->rpressed) {
        MLV_convert_color_to_rgba(this->color, &r, &g, &b, &a);
        col = MLV_rgba(r * 0.75, g * 0.75, b * 0.75, a);
    }
    
    MLV_draw_filled_polygon(X, Y, size, col);
}


void Shape::update(const game::Event &event, game::Engine &engine) {
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
    if (this->lpressed) { // Moving the Shape
        this->translate(mousePos - this->getCenter());
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


bool Shape::operator==(const Shape &other) const {
    std::vector<Point> point = this->getPoints();
    return std::is_permutation(point.begin(), point.end(), other.getPoints().begin());
}


Point Shape::getCenter() {
    return Point::center(this->getPoints());
}





