//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_TEXTURE_H
#define ENGINE_TEXTURE_H

#include <SDL2/SDL.h>
#include "Initializable.h"
#include "Destroyable.h"
#include "Managers.h"
#include "Dimensionable.h"
#include "Positionable.h"
#include "Rotatable.h"
#include "Flippable.h"
#include "Renderable.h"
#include "Croppable.h"

class Texture: public Initializable,
               public Destroyable,

               // renderable
               public Renderable,
               public Flippable,
               public Croppable<int>,
               public Rotatable<int>,
               public Positionable<int>,
               public Dimensionable<int>
{
    SDL_Texture *texture;
    RenderManager *renderManager;

public:
    Texture(SDL_Texture *_texture, RenderManager *_renderManager)
    {
        renderManager = _renderManager;
        texture = _texture;
    }

    void render()
    {
        //renderManager->copy(texture); // etc...
    }
};


#endif //ENGINE_TEXTURE_H
