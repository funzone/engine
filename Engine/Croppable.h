//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_CROPPABLE_H
#define ENGINE_CROPPABLE_H

#include "vec2.h"

template <typename T>
class Croppable
{
    vec2<T> position;
    vec2<T> dimension;
public:
    void setCropPosition(vec2<T> _crop_position)
    {
        position = _crop_position;
    }

    vec2<T> getCropPosition()
    {
        return position;
    }

    void setCropDimension(vec2<T> _crop_dimension)
    {
        dimension = _crop_dimension;
    }

    vec2<T> getCropDimension()
    {
        return dimension;
    }
};


#endif //ENGINE_CROPPABLE_H
