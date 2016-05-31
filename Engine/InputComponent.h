//
// Created by Miles on 2/19/16.
//

#ifndef ENGINE_INPUTCOMPONENT_H
#define ENGINE_INPUTCOMPONENT_H

class GameObject;

class InputComponent
{
public:
    virtual void update(GameObject*, Managers*) = 0;
};


#endif //ENGINE_INPUTCOMPONENT_H
