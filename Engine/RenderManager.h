//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_RENDERMANAGER_H
#define ENGINE_RENDERMANAGER_H

#include <SDL2/SDL.h>
#include "Manager.h"
#include "CoreManager.h"
#include "vec2.h"

class RenderManager: public Manager
{
    CoreManager *coreManager;

    vec2i render_offset = zvec2i, render_scale = uvec2i;

public:
    RenderManager(CoreManager *_coreManager)
    {
        coreManager = _coreManager;
    }

    void changeRenderOffset(vec2i offset)
    {
        render_offset += offset;
    }

    void changeRenderScale(vec2i scale)
    {
        render_scale = render_scale * scale;
    }

    void clear()
    {
        SDL_SetRenderDrawColor(coreManager->getRenderer(), 0, 0, 0, 0);
        SDL_RenderClear(coreManager->getRenderer());
    }

    void copy(
        SDL_Texture *texture,
        SDL_Rect drect,
        SDL_Rect *srect = nullptr,
        double angle = 0,
        SDL_Point *center = nullptr,
        SDL_RendererFlip flip = SDL_FLIP_NONE
    )
    {

        SDL_RenderCopyEx(
            coreManager->getRenderer(),
            texture,
            srect,
            &drect,
            angle,
            center,
            flip
        );
    }

    void drawRect(vec2i position, vec2i size)
    {
        SDL_Rect box{position.x, position.y, size.x, size.y};
        box = scaledOffsetRect(box);

        SDL_SetRenderDrawColor(coreManager->getRenderer(), 255, 0, 0, 255);
        SDL_RenderFillRect(coreManager->getRenderer(), &box);
    }

    SDL_Rect scaledOffsetRect(SDL_Rect drect)
    {
        drect.x *= render_scale.x;
        drect.y *= render_scale.y;
        drect.x += render_offset.x * render_scale.x;
        drect.y += render_offset.y * render_scale.y;
        return drect;
    }

    void present()
    {
        SDL_RenderPresent(coreManager->getRenderer());
    }
};


#endif //ENGINE_RENDERMANAGER_H
