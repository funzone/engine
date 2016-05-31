//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_ROTATABLE_H
#define ENGINE_ROTATABLE_H


#include "vec2.h"

template <typename T>
class Rotatable
{
    double rotation;
    vec2<T> center;

public:
    virtual void setRotation(double _rotation)
    {
        rotation = _rotation;
    }

    virtual double getRotation()
    {
        return rotation;
    }

    virtual void setRotationCenter(vec2<T> _center)
    {
        center = _center;
    }

    virtual vec2<T> getRotationCenter()
    {
        return center;
    }
};


#endif //ENGINE_ROTATABLE_H
