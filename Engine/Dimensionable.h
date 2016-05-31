//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_DIMENSIONABLE_H
#define ENGINE_DIMENSIONABLE_H

#include "vec2.h"

template <typename T>
class Dimensionable
{
    vec2<T> dimension;

public:
    void setDimension(vec2<T> _dimension)
    {
        dimension = _dimension;
    }

    vec2<T> getDimension()
    {
        return dimension;
    }
};


#endif //ENGINE_DIMENSIONABLE_H
