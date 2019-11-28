#include "../include/Vector.hpp"


using namespace Shape;

namespace Shape {
    std::ostream &operator<<(std::ostream &os, const Vector &v) {
        os << "(" << v.first << ", " << v.second << ")";
        return os;
    }
}
