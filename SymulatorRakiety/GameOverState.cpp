#include "GameOverState.h"



GameOverState::GameOverState(GameDataRef data) : data(data)
{

}

void GameOverState::init()
{
	this->data->assets.loadTexture("Game Over Background",GAME_OVER_BACKGROUND_FILEPATH);
	this->data->assets.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
	background.setTexture(this->data->assets.getTexture("Game Over Background"));
	title.setTexture(this->data->assets.getTexture("Game Over Title"));
	title.setPosition((SCREEN_WIDTH / 2 - title.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2 - title.getGlobalBounds().height));
}

void GameOverState::handleInput()
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

void GameOverState::update(float dt)
{

}

void GameOverState::draw(float dt)
{
	this->data->window.clear(sf::Color::Red);

	this->data->window.draw(this->background);
	this->data->window.draw(this->title);
	this->data->window.display();
}