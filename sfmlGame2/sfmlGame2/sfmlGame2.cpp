﻿#include"Game.h"

int main()
{
    //Initialize random seed
    srand(static_cast<unsigned>(time(NULL)));

    //Initialize game object
    Game game;

    //Game loop 
    while (game.running()) {
        game.update();
        game.render();
    }

    //End of appication
    return 0;
}