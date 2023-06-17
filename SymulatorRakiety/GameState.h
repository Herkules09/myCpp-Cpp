#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "Header.h"
#include "State.h"
#include"Enemy.h"
#include"Player.h"
#include"Bullet.h"
#include"GameOverState.h"
#include"MainMenuState.h"
#include "DEFINITIONS.h"
#include"Flash.h"
#include"Score.h"
class GameState : public State
{

private:
	GameDataRef data;
	sf::Sprite background;
	sf::Clock clock;
	Flash* flash;

	Player* player;
	Score* score;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*>bullets;
	bool isGameOver;
	float spawnTimer;
	float spawnTimerMax;
	int maxEnemies;
	unsigned points;

	sf::Text  pointText;
	sf::Text healthText;
	sf::RectangleShape hpBar;
	sf::RectangleShape hpBarMax;
	sf::RectangleShape gameOverFlash;
	bool flashOn;

	sf::Sound shootSound;

	void initVariables();
	void initTextures();
	void initSoundEffects();
	void initEnemies();
	void initGUI();
	void updateGUI();
	void updateInput();
	void updateEnemies();
	void updateBullets();
	void updateCombat();
	void renderGUI();


public:
	GameState(GameDataRef data);
	~GameState();
	void init();

	void handleInput();
	void update(float dt);
	void draw(float dt);

};

#endif // !GAMESTATE_H