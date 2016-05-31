//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_UTIL_H
#define ENGINE_UTIL_H

#include <functional>
#include <SDL2/SDL.h>

typedef std::function<void(SDL_Event)> event_handler;
typedef std::function<void()> closure;

#endif //ENGINE_UTIL_H
