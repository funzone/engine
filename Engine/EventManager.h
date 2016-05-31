//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_EVENTMANAGER_H
#define ENGINE_EVENTMANAGER_H

#include <functional>
#include <map>
#include "Manager.h"
#include "util.h"

using std::map;

class EventManager: public Manager
{
    unsigned int handler_id = 0;
    map<Uint32, map<unsigned int, event_handler>> handlers;
    map<unsigned int, Uint32> handler_types;
public:
    void poll()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            for (auto kv: handlers[e.type])
            {
                handlers[e.type][kv.first](e);
            }
        }
    }

    unsigned int on(Uint32 type, event_handler handler)
    {
        handlers[type][++handler_id] = handler;
        handler_types[handler_id] = type;
        return handler_id;
    }

    void off(unsigned int id)
    {
        cout << "unhooking event with id " << id << endl;
        handlers[handler_types[id]].erase(id);
        handler_types.erase(id);
    }
};


#endif //ENGINE_EVENTMANAGER_H
