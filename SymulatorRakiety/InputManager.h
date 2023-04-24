#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "Header.h"

class InputManager
{
public:
	InputManager() {}
	~InputManager() {}

	bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
	bool isSpriteTracked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
	sf::Vector2i getMousePosition(sf::RenderWindow& window);
};

#endif