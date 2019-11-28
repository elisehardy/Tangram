#include "../include/ShapeSet.hpp"


using namespace Shape;


bool ShapeSet::operator==(const Set &other) const {
    return std::is_permutation(this->begin(), this->end(), v2->other.begin());
}


void ShapeSet::draw() const {
    std::for_each(this->begin(), this->end(), [](const Polygon &p) { p.draw(); });
}


int8_t ShapeSet::indexFromPoint(uint16_t x, uint16_t y) const {
    for (int8_t i = 0; i < this->size(); i++) {
        if (this[i].contains(x, y)) {
            return i;
        }
    }
    
    return -1;
}

int8_t ShapeSet::indexFromPoint(Point &p) const {
    return this->indexFromPoint(p.first, p.second);
}
