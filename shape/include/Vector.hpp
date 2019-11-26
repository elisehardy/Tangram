//
// Created by ehardy on 11/23/19.
//

#ifndef TANGRAM_VECTOR_H
#define TANGRAM_VECTOR_H

#include <utility>
#include <cstdint>
#include <iostream>


namespace Tangram::Shape {

    class Vector : public std::pair<int16_t, int16_t> {
    public:
        using std::pair<int16_t, int16_t>::pair;
        Vector dotProduct(const Vector &v2) const;
        friend std::ostream& operator<<(std::ostream& os, const Vector& dt);

    };
};


#endif //TANGRAM_VECTOR_H
