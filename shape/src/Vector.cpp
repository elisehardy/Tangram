#include "../include/Vector.hpp"


using namespace Tangram::Shape;

namespace Tangram::Shape {
    std::ostream &operator<<(std::ostream &os, const Vector &v) {
        os << "(" << v.first << ", " << v.second << ")";
        return os;
    }
}





Vector Vector::dotProduct(const Vector &v2) const {
    return {this->first * v2.first, this->second * v2.second};
}
