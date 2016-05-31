//
// Created by Miles on 2/19/16.
//

#ifndef ENGINE_RENDERCOMPONENT_H
#define ENGINE_RENDERCOMPONENT_H

class GameObject;

class RenderComponent
{
public:
    virtual void render(GameObject*, Managers*) = 0;
};


#endif //ENGINE_RENDERCOMPONENT_H
