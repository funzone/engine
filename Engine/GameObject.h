//
// Created by Miles on 2/19/16.
//

#ifndef ENGINE_GAMEOBJECT_H
#define ENGINE_GAMEOBJECT_H


#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "PhysicalObject.h"

class GameObject: public PhysicalObject
{
public:
    GameObject(
        InputComponent *_input_,
        PhysicsComponent *_physics_,
        RenderComponent *_render_
    ):
        input_(_input_),
        physics_(_physics_),
        render_(_render_)
    {}

    void update(World* world, Managers* m)
    {
        input_->update(this, m);
        physics_->update(this, world, m);
        this->updatePhysics(world, m);
    }

    void render(Managers *managers)
    {
        render_->render(this, managers);
    }

private:
    InputComponent* input_ = nullptr;
    PhysicsComponent* physics_ = nullptr;
    RenderComponent* render_ = nullptr;
};


#endif //ENGINE_GAMEOBJECT_H
