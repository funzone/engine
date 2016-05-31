//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_ERR_H
#define ENGINE_ERR_H

#include <string>
#include <SDL2/SDL_error.h>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// errors
class Err
{
public:
    string msg = "";

    Err(string _msg)
    {
        msg = _msg;
    }

    virtual string message()
    {
        return msg;
    }

    static void predicate(bool p, string msg = "")
    {
        if (!p)
        {
            if (msg != "") cout << "Error: " << msg << endl;
            cout << "SDL_GetError: " << SDL_GetError() << endl;
            throw Err(msg);
        }
    }
};



#endif //ENGINE_ERR_H
