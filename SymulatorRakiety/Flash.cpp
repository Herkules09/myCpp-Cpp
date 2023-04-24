#include "Flash.h"

Flash::Flash(GameDataRef data): data(data)
{
	shape = sf::RectangleShape(sf::Vector2f(data->window.getSize()));
	shape.setFillColor(sf::Color(255,255,255,0));
	flashSpeed = 1500.0f;
	flashOn = true;
}

void Flash::show(float dt)
{
	if (flashOn) {
		int alpha = (int)shape.getFillColor().a + (flashSpeed * dt);

		if (alpha >= 255.0f) {
			alpha = 255.0f;
			flashOn = false;
		}
		shape.setFillColor(sf::Color(255, 255, 255, alpha));
	}
	else {
		int alpha = (int)shape.getFillColor().a - (flashSpeed * dt);

		if (alpha <= 255.0f) {
			alpha = 0.0f;
			flashOn = false;
		}
		shape.setFillColor(sf::Color(255, 255, 255, alpha));
	}

}

void Flash::draw()
{
	data->window.draw(shape);
}
