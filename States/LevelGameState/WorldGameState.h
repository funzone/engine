//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_LEVELGAMESTATE_H
#define ENGINE_LEVELGAMESTATE_H

#include "../../Engine/Engine.h"
#include "BoxGameObject.h"

class WorldGameState : public GameState
{
public:
    World world;
    vector<GameObject> gameObjects;
    BoxGameObject box_a;

    void init()
    {
        box_a.setPosition(vec2d(500, 500));
        gameObjects.push_back(box_a);
    }

    void update(Managers *managers)
    {
        for (int i = 0; i < gameObjects.size(); i++)
        {
            gameObjects[i].update(&world, managers);
        }
    }

    void render(Managers *managers)
    {
        managers->renderManager.changeRenderScale(vec2i(1, -1));
        managers->renderManager.changeRenderOffset(vec2i(0, (int) -world.getDimension().y));

        for (int i = 0; i < gameObjects.size(); i++)
        {
            gameObjects[i].render(managers);
        }

        managers->renderManager.changeRenderScale(vec2i(1, -1));
        managers->renderManager.changeRenderOffset(vec2i(0, (int) world.getDimension().y));
    }
};


#endif //ENGINE_LEVELGAMESTATE_H
