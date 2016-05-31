//
// Created by Miles on 2/18/16.
//

#ifndef ENGINE_ASSETMANAGER_H
#define ENGINE_ASSETMANAGER_H

#include <map>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Manager.h"
#include "Texture.h"
#include "Err.h"
#include "CoreManager.h"

using std::map;
using std::string;
using std::cout;
using std::endl;

class AssetManager: public Manager
{
    CoreManager *coreManager;
    RenderManager *renderManager;
    map<uint32_t, Texture> textures;
    uint32_t _texture_seq_id = 0;

public:
    AssetManager(CoreManager *_coreManager, RenderManager *_renderManager):
        coreManager(_coreManager),
        renderManager(_renderManager)
    {}

    uint32_t loadImage(string path)
    {
        string filepath = "assets/image/" + path;
        cout << "loading texture " << filepath << endl;

        SDL_Surface *surface = IMG_Load(filepath.c_str());
        Err::predicate(surface != nullptr);

        SDL_Texture *sdl_texture = SDL_CreateTextureFromSurface(coreManager->getRenderer(), surface);
        Err::predicate(sdl_texture != nullptr);

        textures[++_texture_seq_id] = Texture(sdl_texture, renderManager);

        textures[_texture_seq_id].setDimension(vec2i(surface->w, surface->h));

        SDL_FreeSurface(surface);
        return _texture_seq_id;
    }
};


#endif //ENGINE_ASSETMANAGER_H
