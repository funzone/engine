//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_FLIPABLE_H
#define ENGINE_FLIPABLE_H


#include <SDL2/SDL_render.h>

class Flippable
{
    SDL_RendererFlip flip_type = SDL_FLIP_NONE;
public:
    void setFlip(SDL_RendererFlip _flip_type)
    {
        flip_type = _flip_type;
    }
    SDL_RendererFlip getFlip()
    {
        return flip_type;
    }
};


#endif //ENGINE_FLIPABLE_H
