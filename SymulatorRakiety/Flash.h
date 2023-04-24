#ifndef FLASH_H
#define FLASH_H
#include"Header.h"
#include"Game.h"

class Flash
{
private:

	float flashSpeed;
	GameDataRef data;
	sf::RectangleShape shape;
	bool flashOn;


public:
	Flash(GameDataRef data);
	void show(float dt);
	void draw();
};
#endif

