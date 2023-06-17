#include "GameOverState.h"



GameOverState::GameOverState(GameDataRef data) : data(data)
{

}

void GameOverState::init()
{
	this->data->assets.loadTexture("Game Over Background",GAME_OVER_BACKGROUND_FILEPATH);
	this->data->assets.loadTexture("Button", BUTTON_FILEPATH);
	this->data->assets.loadFont("Game Font", FONT_FILEPATH);
	background.setTexture(this->data->assets.getTexture("Game Over Background"));

	this->text["PLAY AGAIN"] = new sf::Text();
	this->text["PLAY AGAIN"]->setFont(this->data->assets.getFont("Game Font"));
	this->text["PLAY AGAIN"]->setString("PLAY AGAIN");
	this->text["PLAY AGAIN"]->setFillColor(sf::Color::White);
	this->text["BACK TO MENU"] = new sf::Text();
	this->text["BACK TO MENU"]->setFont(this->data->assets.getFont("Game Font"));
	this->text["BACK TO MENU"]->setString("MAIN MENU");
	this->text["BACK TO MENU"]->setFillColor(sf::Color::White);
	this->text["PLAY AGAIN"]->setPosition((SCREEN_WIDTH / 2) - (text["PLAY AGAIN"]->getGlobalBounds().width / 2), 
		(SCREEN_HEIGHT / 2) - (text["PLAY AGAIN"]->getGlobalBounds().height / 2));
	this->text["BACK TO MENU"]->setPosition((SCREEN_WIDTH / 2) - (text["BACK TO MENU"]->getGlobalBounds().width / 2), 
		(SCREEN_HEIGHT / 2) - (text["PLAY AGAIN"]->getGlobalBounds().height / 2) + 150.f);
	this->text["GAME OVER"] = new sf::Text();
	this->text["GAME OVER"]->setFont(this->data->assets.getFont("Game Font"));
	this->text["GAME OVER"]->setString("GAME OVER");
	this->text["GAME OVER"]->setFillColor(sf::Color::White);
	this->text["GAME OVER"]->setCharacterSize(60);
	this->text["GAME OVER"]->setPosition((SCREEN_WIDTH / 2) - (text["GAME OVER"]->getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 3 - text["GAME OVER"]->getGlobalBounds().height)-80.f);

	this->playAgainButton.setTexture(this->data->assets.getTexture("Button"));
	this->playAgainButton.setScale(0.5f, 0.5f);
	this->goToMainManuButton.setTexture(this->data->assets.getTexture("Button"));
	this->goToMainManuButton.setScale(0.5f, 0.5f);
	this->playAgainButton.setPosition((SCREEN_WIDTH / 2) - (playAgainButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (playAgainButton.getGlobalBounds().height / 2));
	this->goToMainManuButton.setPosition((SCREEN_WIDTH / 2) - (playAgainButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (playAgainButton.getGlobalBounds().height / 2) + 150.f);
	

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

		if (this->data->input.isSpriteTracked(this->playAgainButton, sf::Mouse::Left, this->data->window)) {
			this->text["PLAY AGAIN"]->setFillColor(sf::Color::Red);
		}
		else {
			this->text["PLAY AGAIN"]->setFillColor(sf::Color::White);
		}
		if (this->data->input.isSpriteTracked(this->goToMainManuButton, sf::Mouse::Left, this->data->window)) {
			this->text["BACK TO MENU"]->setFillColor(sf::Color::Red);
		}
		else {
			this->text["BACK TO MENU"]->setFillColor(sf::Color::White);
		}




		if (this->data->input.isSpriteClicked(this->playAgainButton, sf::Mouse::Left, this->data->window))
		{
			//this->clickButton.play();
			//this->soundtrack.pause();
			this->data->machine.addState(StateRef(new GameState(data)),false);

		}
		if (this->data->input.isSpriteClicked(this->goToMainManuButton, sf::Mouse::Left, this->data->window))
		{
			//this->clickButton.play();
			this->data->machine.addState(StateRef(new MainMenuState(data)), true);

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
	this->data->window.draw(this->playAgainButton);
	this->data->window.draw(this->goToMainManuButton);
	this->data->window.draw(*this->text["GAME OVER"]);
	this->data->window.draw(*this->text["PLAY AGAIN"]);
	this->data->window.draw(*this->text["BACK TO MENU"]);
	
	this->data->window.display();
}