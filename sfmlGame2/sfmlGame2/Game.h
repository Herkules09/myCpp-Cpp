#pragma once
#include<iostream>
#include<ctime>
#include<sstream>

#include"Player.h"
#include"SwagBall.h"
#include<vector>

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;
	std::vector<SwagBall> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;
	int points;

	sf::Font font;
	sf::Text guiText;
	sf::Text endGameText;


	void initVariables();
	void initWindow();
	void initFonts();
	void initText();


public:
	 Game();
	~Game();

	//Accessors - get variables for this class
	const bool& getEndGame() const;
	//Modifiers - modified variables in this class

	//Functions
	const bool running() const;
	void pollEvents();

	void spawnSwagBalls();
	const int randBallType() const;
	void updatePlayer();
	void updateCollision();
	void updateGui();
	void update();
	void renderGui(sf::RenderTarget* target);
	void render();

};
