//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_COREMANAGER_H
#define ENGINE_COREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Err.h"
#include "Manager.h"

class CoreManager: public Manager
{
    SDL_Window *window;

    SDL_Renderer *renderer;

public:
    void init()
    {
        Err::predicate(SDL_Init(SDL_INIT_EVERYTHING) == 0, "cannot init sdl2");
        Err::predicate(IMG_Init(IMG_INIT_PNG) != 0, "cannot init sdl2_image");
        window = SDL_CreateWindow("CoreManager Window", 0, 0, 1280, 720, SDL_WINDOW_SHOWN);
        Err::predicate(window != nullptr);


        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        Err::predicate(renderer != nullptr);
    }

    void destroy()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_Renderer *getRenderer()
    {
        return renderer;
    }
};


#endif //ENGINE_COREMANAGER_H
