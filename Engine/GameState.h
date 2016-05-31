//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_GAMESTATE_H
#define ENGINE_GAMESTATE_H

#include "Managers.h"
#include "Renderable.h"
#include "Updatable.h"
#include "Initializable.h"
#include "Destroyable.h"


class GameState: public Initializable,
                 public Destroyable
{
public:
    virtual void update(Managers*) = 0;
    virtual void render(Managers*) = 0;
};


#endif //ENGINE_GAMESTATE_H
