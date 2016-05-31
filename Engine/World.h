//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_WORLD_H
#define ENGINE_WORLD_H


#include "vec2.h"

#include <vector>
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "Dimensionable.h"

using std::vector;




/*
 *
 * a(2, 5) b(4, 9)
 *
 * y = mx + b
 * m = (b.x - a.x) / (b.y - a.y)
 * b = a.y - m * a.x
 * 
 * p.y >= (p.x - a.x) * ((b.x - a.x) / (b.y - a.y)) + a.y
 *
 *
 *
 */
class Platform
{
public:
    vec2d a, b;
    double mm, bb;

    Platform(vec2d _a, vec2d _b)
    {
        a = _a;
        b = _b;
        mm =(b.y == a.y)
            ? 0
            : (b.x - a.x) / (b.y - a.y);
        bb = a.y - mm * a.x;
    }

    bool intersects(vec2d p, double *yint)
    {
        //cout << p.y << " <= " << (p.x - a.x) * ((b.x - a.x) / (b.y - a.y)) + a.y << endl;
        //cout << a.x << " <= " <<  p.x << " <= " << b.x << endl << endl;

        if (p.x >= a.x && p.x <= b.x)
        {
            //cout << p.y << " <= "<< mm<<"*"<<p.x<<"+"<<bb<<endl;
            *yint = mm * p.x + bb;
            return p.y <= *yint;
        }

        return false;
    }
};

class World: public Dimensionable<double>
{
public:
    vec2d gravity = vec2d(0, -.1);
    vector<Platform> platforms;
    World()
    {
        this->setDimension(vec2d(1280, 720));
        // create floor
        platforms.push_back(Platform(vec2d(0, 50), vec2d(getDimension().x, 50)));
    }
};


#endif //ENGINE_WORLD_H
