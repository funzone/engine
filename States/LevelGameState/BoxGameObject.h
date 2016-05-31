//
// Created by Miles on 2/19/16.
//

#ifndef ENGINE_BOXGAMEOBJECT_H
#define ENGINE_BOXGAMEOBJECT_H

#include "../../Engine/Engine.h"

class BoxPhysicsComponent: public PhysicsComponent
{
public:
    void update(GameObject *gameObject, World *world, Managers *m)
    {
        gameObject->updatePhysics(world, m);
    }
};



class BoxInputComponent: public InputComponent
{
public:
    void update(GameObject *gameObject, Managers *m)
    {
        gameObject->setVelocity(m->gameControllerManager.getLeftStick());
    }
};


class BoxRenderComponent: public RenderComponent
{
public:
    void render(GameObject *gameObject, Managers *m)
    {
        vec2d p = gameObject->getPosition();
        vec2d d = gameObject->getDimension();
        m->renderManager.drawRect(vec2i(p.x, p.y), vec2i(d.x, d.y));
    }
};



class BoxGameObject: public GameObject
{

public:
    BoxGameObject():
        GameObject(&_input_, &_physics_, &_render_)
    {
        setDimension(vec2d(5, 5));
    }

private:
    BoxInputComponent _input_;
    BoxPhysicsComponent _physics_;
    BoxRenderComponent _render_;
};


#endif //ENGINE_BOXGAMEOBJECT_H
