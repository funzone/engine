#include "Engine/Engine.h"
#include "states/LevelGameState/WorldGameState.h"
#include <vector>
#include <iostream>

int main()
{
    Engine e;
    WorldGameState l = WorldGameState();
    e.init();


    e.pushGameState(&l);
    e.advanceGameState();

    e.begin();
    e.destroy();
    return 0;
}