//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_MANAGERS_H
#define ENGINE_MANAGERS_H

#include <vector>
#include "Manager.h"
#include "RenderManager.h"
#include "Destroyable.h"
#include "Initializable.h"
#include "EventManager.h"
#include "GameControllerManager.h"
#include "RealTimeManager.h"
#include "LoopManager.h"

class Managers: public Initializable, public Destroyable
{
    std::vector<Manager*> managers;
public:
    CoreManager coreManager;
    RenderManager renderManager;
    EventManager eventManager;
    GameControllerManager gameControllerManager;
    RealTimeManager realTimeManager;
    LoopManager loopManager;

    Managers():
        renderManager(&coreManager),
        gameControllerManager(&eventManager),
        loopManager(&realTimeManager)
    {
        managers.push_back(&coreManager);
        managers.push_back(&renderManager);
        managers.push_back(&eventManager);
        managers.push_back(&gameControllerManager);
        managers.push_back(&loopManager);
    };

    void init()
    {
        for (unsigned long i = 0; i < managers.size(); i++)
        {
            managers[i]->init();
        }
    }

    void destroy()
    {
        for (unsigned long i = managers.size() - 1; i < managers.size(); i--)
        {
            managers[i]->destroy();
        }
    }
};


#endif //ENGINE_MANAGERS_H
