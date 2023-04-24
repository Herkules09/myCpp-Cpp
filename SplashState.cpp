#include "SplashState.h"



SplashState::SplashState(GameDataRef data) : data(data)
{

}

void SplashState::init()
{
	this->data->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

	background.setTexture(this->data->assets.getTexture("Splash State Background"));
}

void SplashState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}
	}
}

void SplashState::update(float dt)
{
	if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		// Switch To Main Menu
		this->data->machine.addState(StateRef(new MainMenuState(data)), true);
	}
}

void SplashState::draw(float dt)
{
	this->data->window.clear(sf::Color::Red);

	this->data->window.draw(this->background);

	this->data->window.display();
}