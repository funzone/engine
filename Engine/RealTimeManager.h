//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_REALTIMEMANAGER_H
#define ENGINE_REALTIMEMANAGER_H

#include <SDL2/SDL.h>
#include "Manager.h"

class RealTimeManager: Manager
{
public:
    void init()
    {
        start = SDL_GetTicks();
    }

    uint32_t getCurrent()
    {
        return SDL_GetTicks();
    }

    void update()
    {
        last_update = getCurrent();
    }

    uint32_t getLastUpdated()
    {
        return last_update;
    }

    uint32_t getDelta()
    {
        return getCurrent() - last_update;
    }

private:
    uint32_t start, last_update;
};


#endif //ENGINE_REALTIMEMANAGER_H
