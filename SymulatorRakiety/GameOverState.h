#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "Header.h"
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

class GameOverState: public State
{
public:
	GameOverState(GameDataRef data);

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);

private:
	GameDataRef data;
	sf::Sprite background;
	sf::Sprite title;
};

#endif
