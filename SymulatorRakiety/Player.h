#ifndef PLAYER_H
#define PLAYER_H
#include"Header.h"
#include"Game.h"
#include"DEFINITIONS.h"
class Player
{
private:
	GameDataRef data;
	sf::Sprite playerShape;

	sf::Clock clock;
	sf::Clock movementClock;
	int hp;
	int hpMax;
	int damage;
	float movementSpeed;
	float shootingColdown;
	float shootingColdownMax;
	

	void initVariables();
	void updateInput();
	void updateShooting();

public:
	Player(GameDataRef data);
	virtual ~Player();

	const sf::Vector2f& getPosition();
	const sf::FloatRect getBounds() const;
	void updateWindowsBoundsCollision();
	const int& getHp() const;
	const int& getHpMax() const;
	const int& getDamage() const;
	void setPosition(const sf::Vector2f position);
	void setPosition(const float x, const float y);
	void setHp(int damage, int health);
	void move(const float dirX, const float dirY);
	const bool canShoot();
	void update();
	void draw();
};

#endif

