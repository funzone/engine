//
// Created by Miles on 2/19/16.
//

#ifndef ENGINE_GAMECONTROLLERMANAGER_H
#define ENGINE_GAMECONTROLLERMANAGER_H


#include <iostream>
#include "vec2.h"
#include "EventManager.h"

class GameControllerManager: public Manager
{
public:
    GameControllerManager(EventManager *_eventManager):
        eventManager(_eventManager)
    {}

    vec2d getLeftStick()
    {
        return left_stick;
    }

    void init()
    {
        if (SDL_NumJoysticks() > 0)
        {
            SDL_JoystickOpen(0);
        }

        eventManager->on(SDL_KEYDOWN, [this](SDL_Event e)
        {
            switch(e.key.keysym.sym)
            {
                case SDLK_LEFT:
                    left_stick.x -= 1;
                    break;
                case SDLK_RIGHT:
                    left_stick.x += 1;
                    break;
                case SDLK_DOWN:
                    left_stick.y -= 1;
                    break;
                case SDLK_UP:
                    left_stick.y += 1;
                    break;
            }
        });

        eventManager->on(SDL_KEYUP, [this](SDL_Event e)
        {

            switch(e.key.keysym.sym)
            {
                case SDLK_LEFT:
                    left_stick.x += 1;
                    break;
                case SDLK_RIGHT:
                    left_stick.x -= 1;
                    break;
                case SDLK_DOWN:
                    left_stick.y += 1;
                    break;
                case SDLK_UP:
                    left_stick.y -= 1;
                    break;
            }
        });

        e_jaxis = eventManager->on(SDL_JOYAXISMOTION, [this](SDL_Event e)
        {
            double ratio = e.jaxis.value / double(0x7fff);
            switch(e.jaxis.axis)
            {
                case 0: left_stick.x = ratio; break;
                case 1: left_stick.y = ratio; break;
                default: break;
            }
        });
    }

    void destroy()
    {
        eventManager->off(e_jaxis);
    }

private:
    SDL_Joystick *joystick = nullptr;

    // backup stick for no controller
    vec2d left_stick;
    EventManager *eventManager;
    Uint32 e_jaxis;

};


#endif //ENGINE_GAMECONTROLLERMANAGER_H
