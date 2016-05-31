//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_POSITIONABLE_H
#define ENGINE_POSITIONABLE_H


#include "vec2.h"

template <typename T>
class Positionable
{
    vec2<T> position;

public:
    void setPosition(vec2<T> _position)
    {
        position = _position;
    }

    vec2<T> getPosition()
    {
        return position;
    }
};




#endif //ENGINE_POSITIONABLE_H
