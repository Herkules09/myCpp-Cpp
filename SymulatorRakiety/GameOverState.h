#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "Header.h"
#include "State.h"
#include "Game.h"
#include "GameState.h"
#include "DEFINITIONS.h"

class GameOverState: public State
{
private:
	GameDataRef data;
	sf::Sprite background;
	sf::Sprite goToMainManuButton;
	sf::Sprite playAgainButton;
	sf::Text title;
	std::map<std::string, sf::Text*> text;


public:
	GameOverState(GameDataRef data);

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);
};

#endif
