#include <algorithm>

#include "../include/Polygon.hpp"


using namespace tangram::geometry;


Polygon::Polygon(MLV_Color t_color) :
        currentRotation(0), pressedPoint(0, 0), lpressed(false), rpressed(false), hovered(false), color(t_color) {
}


Polygon Polygon::custom(const std::vector<Triangle> &triangles, MLV_Color color) {
    Polygon p = Polygon(color);
    p.add(triangles);
    return p;
}


Polygon Polygon::smallTriangle(const Point &offset, MLV_Color color) {
    return custom({Triangle(offset)}, color);
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


Polygon &Polygon::translate(const Vector &v) {
    std::for_each(
            this->triangles.begin(), this->triangles.end(),
            [&](Triangle &t) { t = t.translate(v); }
    );
    
    this->pressedPoint = this->pressedPoint.translate(v);
    
    return *this;
}


Polygon &Polygon::translate(int16_t x, int16_t y) {
    return this->translate({x, y});
}


Polygon &Polygon::rotate(int16_t n, const Point &center) {
    std::for_each(
            this->triangles.begin(), this->triangles.end(),
            [&](Triangle &t) { t = t.rotate(n, center); }
    );
    
    return *this;
}


Polygon &Polygon::rotate(int16_t n) {
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
    Point mousePos = Point(event.mousePos.x, event.mousePos.y);
    bool leftClick = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_LEFT;
    bool rightClick = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_RIGHT;
    
    this->hovered = this->contains(mousePos);
    
    if (this->hovered && leftClick && event.state == MLV_PRESSED) {  // Left button pressed
        this->pressedPoint = Point(mousePos);
        this->lpressed = true;
    }
    else if (this->lpressed && leftClick && event.state == MLV_RELEASED) {  // Left button released
        this->lpressed = false;
    }
    
    if (this->lpressed) { // Moving the Shape
        this->translate(mousePos - this->pressedPoint);
    }
    
    if (this->hovered && rightClick && event.state == MLV_PRESSED) {  // Right button pressed
        this->pressedPoint = Point(mousePos);
        this->currentRotation = 0;
        this->rpressed = true;
    }
    else if (this->rpressed && rightClick && event.state == MLV_RELEASED) { // Left click released
        this->rpressed = false;
    }
    
    if (this->rpressed) { // Rotating the shape
        int16_t angle = (pressedPoint.x - mousePos.x) / 10;
        this->rotate((angle - this->currentRotation) * Triangle::ANGLE_STEP);
        this->currentRotation = angle;
    }
}


void Polygon::draw() const {
    uint8_t r, g, b, a;
    MLV_Color color;
    
    color = this->color;
    if (this->hovered) {
        MLV_convert_color_to_rgba(this->color, &r, &g, &b, &a);
        color = MLV_rgba(uint8_t(r * 0.80), uint8_t(g * 0.80), uint8_t(b * 0.80), a);
    }
    else if (this->lpressed || this->rpressed) {
        MLV_convert_color_to_rgba(this->color, &r, &g, &b, &a);
        color = MLV_rgba(uint8_t(r * 0.60), uint8_t(g * 0.60), uint8_t(b * 0.60), a);
    }
    
    std::for_each(this->triangles.begin(), this->triangles.end(), [color](const Triangle &t) { t.draw(color); });
}
