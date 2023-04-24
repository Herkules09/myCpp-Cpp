#include"time.h"
#include<stdlib.h>
#include"Game.h"
#include"DEFINITIONS.h"

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	Game(SCREEN_WIDTH, SCREEN_HEIGHT, "game");

	return EXIT_SUCCESS;
}