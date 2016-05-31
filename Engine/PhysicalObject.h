//
// Created by Miles on 2/19/16.
//

#ifndef ENGINE_PHYSICALOBJECT_H
#define ENGINE_PHYSICALOBJECT_H

#include "Positionable.h"
#include "Dimensionable.h"
#include "Rotatable.h"
#include "World.h"

class PhysicalObject: public Positionable<double>, public Dimensionable<double>
{
public:
    void updatePhysics(World *world, Managers *m)
    {
        uint32_t t = m->loopManager.getUpdateMs();
        vec2d p = getPosition();
        vec2d v = getVelocity();
        vec2d g = world->gravity;

        v.x += t * (g.x);
        v.y += t * (g.y);
        p.x += t * (v.x);
        p.y += t * (v.y);

        double yint;

        if (world->platforms[0].intersects(p, &yint))
        {
            p.y = yint;
        }

        setVelocity(v);
        setPosition(p);
    }

    vec2d getAcceleration()
    {
        return acceleration;
    }

    void setAcceleration(vec2d a)
    {
        acceleration = a;
    }

    vec2d getVelocity()
    {
        return velocity;
    }

    void setVelocity(vec2d v)
    {
        velocity = v;
    }

    double getMass()
    {
        return mass;
    }

    void setMass(double m)
    {
        mass = m;
    }

private:
    vec2d acceleration, velocity;
    double mass;
};


#endif //ENGINE_PHYSICALOBJECT_H
