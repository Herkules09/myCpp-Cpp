#ifndef SPLASHSTATE_H
#include "Header.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include "State.h"
#include "Game.h"

class SplashState : public State
{
private:
	GameDataRef data;

	sf::Clock clock;

	sf::Sprite background;

public:
	SplashState(GameDataRef data);

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);


};
#endif