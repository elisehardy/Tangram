#ifndef VECTOR_H
#define VECTOR_H

#include <utility>
#include <cstdint>
#include <iostream>


namespace Shape {
    
    class Vector : public std::pair<int16_t, int16_t> {
        public:
            using std::pair<int16_t, int16_t>::pair;
            friend std::ostream &operator<<(std::ostream &os, const Vector &dt);
    };
};

#endif // VECTOR_H
