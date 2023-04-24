#ifndef BULLET_H
#define BULLET_H

#include "Header.h"
#include"DEFINITIONS.h"
#include"Game.h"
#include "TEX_NAMES.h"

class Bullet
{
private:

	GameDataRef data;
	sf::Sprite bulletShape;
	sf::Vector2f direction;
	float movementSpeed;

	void initVariables();

public:
	Bullet();
	Bullet(GameDataRef data, float posX, float posY, float dirX, float dirY, float movementSpeed);
	~Bullet();

	const sf::FloatRect getBounds() const;

	void update();
	void draw();

};

#endif

