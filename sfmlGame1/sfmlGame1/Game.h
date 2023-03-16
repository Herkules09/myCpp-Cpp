#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

//Class that acts as the game engine. Wrapped class

class Game
{
private:

	sf::RenderWindow * window;
	sf::VideoMode videoMode;
	sf::Event ev;
	
	//Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;


	//Game logic
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//Game objects
	std::vector<sf::RectangleShape>enemies;
	sf::RectangleShape enemy;


	void initVariables();  //init - initialize
	void initWindow();
	void initFont();
	void initText();
	void initEnemies();
public:
	Game();
	virtual ~Game();
	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	void spawnEnemy();
	void poolEvents();
	void updateText();
	void updateMousePosition();
	void updateEnemies();
	void update();

	void renderText(sf::RenderTarget& target);
	void renderEnemies(sf::RenderTarget& target);
	void render();
};

