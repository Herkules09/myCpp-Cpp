#ifndef MAINMANUSTATE_H
#define MAINMANUSTATE_H
#include "Header.h"
#include "DEFINITIONS.h"
#include "GameState.h"
#include "ScoresState.h"
#include "State.h"
#include "Game.h"

class MainMenuState : public State
{
private:
	GameDataRef data;
	sf::Sound soundtrack;
	sf::Sound clickButton;
	sf::Sprite background;
	sf::Sprite title;
	sf::Sprite scores;
	sf::Sprite exitButton;
	sf::Sprite playButton;
	sf::Sprite scoresButton;
	std::map<std::string, sf::Text*> text;
	
	void initText();
	void loadAssets();

public:
	MainMenuState(GameDataRef data);
	~MainMenuState();

	void init();

	void handleInput();
	void update(float dt);
	void draw(float dt);


};

#endif