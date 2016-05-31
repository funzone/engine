//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_LOOPMANAGER_H
#define ENGINE_LOOPMANAGER_H

#include "Manager.h"
#include "util.h"
#include "RealTimeManager.h"

class LoopManager: public Manager
{
public:
    LoopManager(RealTimeManager *_realTimeManager):
        realTimeManager(_realTimeManager)
    {}

    void begin(closure input, closure update, closure render)
    {
        looping = true;

        double previous = realTimeManager->getCurrent();
        double lag = 0.;

        while (looping)
        {
            double current = realTimeManager->getCurrent();
            double elapsed = current - previous;
            previous = current;
            lag += elapsed;

            input();

            while (lag >= update_ms)
            {
                update();
                lag -= update_ms;
            }

            render();
        }
    }

    void cancel()
    {
        looping = false;
    }

    uint32_t getUpdateMs()
    {
        return update_ms;
    }
private:
    bool looping;

    uint32_t update_ms = 1;
    RealTimeManager *realTimeManager;
};


#endif //ENGINE_LOOPMANAGER_H
