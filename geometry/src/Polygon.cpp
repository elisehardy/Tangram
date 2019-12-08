#include <algorithm>

#include "../include/Polygon.hpp"


using namespace tangram::geometry;


Polygon::Polygon(MLV_Color t_color) :
        color(t_color) {
}


Polygon Polygon::custom(const std::vector<Triangle> &triangles, MLV_Color color) {
    Polygon p = Polygon(color);
    p.add(triangles);
    return p;
}


Polygon Polygon::smallTriangle(const Point &offset, MLV_Color color) {
    // TODO
    return Polygon(color);
}


Polygon Polygon::mediumTriangle(const Point &offset, MLV_Color color) {
    // TODO
    return Polygon(color);
}


Polygon Polygon::largeTriangle(const Point &offset, MLV_Color color) {
    // TODO
    return Polygon(color);
}


Polygon Polygon::parallelogram(const Point &offset, MLV_Color color) {
    // TODO
    return Polygon(color);
}


Polygon Polygon::square(const Point &offset, MLV_Color color) {
    Triangle t1(offset);
    return custom(
            {t1, t1.rotate(180, offset).translate({Triangle::SIDE, Triangle::SIDE})},
            color
    );
}


Polygon Polygon::translate(const Vector &v) const {
    std::vector<Triangle> triangles;
    
    std::for_each(
            this->triangles.begin(), this->triangles.end(),
            [&](const Triangle &t) { triangles.push_back(t.translate(v)); }
    );
    
    return Polygon::custom(triangles, color);
}


Polygon Polygon::translate(int16_t x, int16_t y) const {
    return this->translate({x, y});
}


Polygon Polygon::rotate(int16_t n, const Point &center) const {
    std::vector<Triangle> triangles;
    
    std::for_each(
            this->triangles.begin(), this->triangles.end(),
            [&](const Triangle &t) { triangles.push_back(t.rotate(n, center)); }
    );
    
    return Polygon::custom(triangles, color);
}


Polygon Polygon::rotate(int16_t n) const {
    return this->rotate(n, Point::center(this->getPoints()));
}


std::vector<Point> Polygon::getPoints() const {
    std::vector<Point> points = {};
    
    for (const Triangle &t: this->triangles) {
        auto trianglePoints = t.getPoints();
        std::for_each(
                trianglePoints.begin(), trianglePoints.end(),
                [&points](const Point &p) { points.push_back(Point(p)); }
        );
    }
    
    return points;
}


bool Polygon::contains(const Point &p) const {
    return std::any_of(
            this->triangles.begin(), this->triangles.end(),
            [&p](const Triangle &t) { return t.contains(p); }
    );
}


void Polygon::add(const Triangle &t) {
    this->triangles.push_back(t);
}


void Polygon::add(const std::vector<Triangle> &triangles) {
    std::for_each(triangles.begin(), triangles.end(), [this](const Triangle &t) { this->add(t); });
}


void Polygon::update(const game::Event &event, game::Engine &engine) {
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
        *this = this->translate(mousePos - Point::center(this->getPoints()));
    }
    
    if (this->hovered && rightClick && event.state == MLV_PRESSED) {  // Pressed on  right button
        this->rpressed = true;
    }
    else if (this->rpressed && rightClick && event.state == MLV_RELEASED) { // Left click released
        if (this->hovered) { // Released on button
            this->rpressed = false;
            *this = this->rotate(1);
        }
        else { // Released outside button
            this->rpressed = false;
        }
    }
}


void Polygon::draw() const {
    uint8_t r, g, b, a;
    MLV_Color color;
    
    color = this->color;
    if (this->hovered) {
        MLV_convert_color_to_rgba(this->color, &r, &g, &b, &a);
        color = MLV_rgba(r * 0.80, g * 0.80, b * 0.80, a);
    }
    else if (this->lpressed || this->rpressed) {
        MLV_convert_color_to_rgba(this->color, &r, &g, &b, &a);
        color = MLV_rgba(r * 0.60, g * 0.60, b * 0.60, a);
    }
    
    std::for_each(this->triangles.begin(), this->triangles.end(), [color](const Triangle &t) { t.draw(color); });
}
