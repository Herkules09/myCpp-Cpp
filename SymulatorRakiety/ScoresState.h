#ifndef SCORESSTATE_H
#define SCORESSTATE_H
#include "Header.h"
#include "DEFINITIONS.h"
#include "State.h"
#include "Game.h"
#include "MainMenuState.h"
#include "Score.h"
class ScoresState:public State
{
private:
	GameDataRef data;

	sf::Sprite background;
	sf::Text title;
	sf::Text hightscore_text;
	sf::Text score_text;
	sf::Text resetText;
	sf::Sprite goBackButton;
	sf::Sprite goBack;
	sf::Sprite resetButton;
	Score* score;
	sf::Sound soundtrack;
	sf::Sound clickButton;
	std::vector<std::string>results;

	void initAssets();
public:
	ScoresState(GameDataRef data);
	~ScoresState();

	void init();

	void handleInput();
	void update(float dt);
	void draw(float dt);

};

#endif
