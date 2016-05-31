//
// Created by Miles on 2/19/16.
//

#ifndef ENGINE_PHYSICSCOMPONENT_H
#define ENGINE_PHYSICSCOMPONENT_H

class GameObject;
class World;

class PhysicsComponent
{
public:
    virtual void update(GameObject*, World*, Managers*) = 0;
};


#endif //ENGINE_PHYSICSCOMPONENT_H
