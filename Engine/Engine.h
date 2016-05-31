//
// Created by Miles on 2/17/16.
//

#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include <deque>
#include "Managers.h"
#include "Initializable.h"
#include "Destroyable.h"
#include "Updatable.h"
#include "Renderable.h"
#include "GameState.h"
#include "GameObject.h"
#include "World.h"

class Engine: public Initializable,
              public Destroyable
{
    unsigned int e_quit;
    std::deque<GameState*> game_states;
    GameState *_current_game_state = nullptr;

public:

    Managers managers;




    // set event handlers, init managers,
    // set framerate
    //
    void init()
    {
        managers.init();
        e_quit = managers.eventManager.on(SDL_QUIT, [this](SDL_Event)
        {
            managers.loopManager.cancel();
        });

    }




    // start update/render loop
    //
    void begin()
    {
        GameState *game_state = currentGameState();

        // input loop
        //
        closure input = [&]()
        {
            managers.eventManager.poll();
        };

        // update loop
        //
        closure update = [&]()
        {
            game_state->update(&managers);
        };

        // render loop
        //
        closure render = [&]()
        {
            managers.renderManager.clear();
            game_state->render(&managers);
            managers.renderManager.present();
        };

        // start
        managers.loopManager.begin(input, update, render);
    }




    // unset event handlers and destroy managers
    //
    void destroy()
    {
        managers.eventManager.off(e_quit);
        managers.destroy();
    }



    // todo - get below into GameStateManager


    // push a state
    //
    void pushGameState(GameState *game_state)
    {
        game_states.push_back(game_state);
    }




    // get current state
    //
    GameState *currentGameState()
    {
        return _current_game_state;
    }




    // advance state forward,
    // call init and destroy
    //
    void advanceGameState()
    {
        if (_current_game_state)
        {
            _current_game_state->destroy();
        }
        if (game_states.size())
        {
            _current_game_state = game_states[0];
            _current_game_state->init();
            game_states.pop_front();
        }
    }
};


#endif //ENGINE_ENGINE_H
