#include "MainMenuState.h"




void MainMenuState::initText()
{
	this->text["PLAY"] = new sf::Text();
	this->text["PLAY"]->setFont(this->data->assets.getFont("Game Font"));
	this->text["PLAY"]->setString("PLAY");
	this->text["PLAY"]->setFillColor(sf::Color::White);
	this->text["SCORES"] = new sf::Text();
	this->text["SCORES"]->setFont(this->data->assets.getFont("Game Font"));
	this->text["SCORES"]->setString("SCORES");
	this->text["EXIT"] = new sf::Text();
	this->text["EXIT"]->setFont(this->data->assets.getFont("Game Font"));
	this->text["EXIT"]->setString("EXIT");
	this->text["SCORES"]->setFillColor(sf::Color::White);
	this->text["PLAY"]->setPosition((SCREEN_WIDTH / 2) - (text["PLAY"]->getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (text["PLAY"]->getGlobalBounds().height / 2)-200.f);
	this->text["SCORES"]->setPosition((SCREEN_WIDTH / 2) - (text["SCORES"]->getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (text["PLAY"]->getGlobalBounds().height / 2));
	this->text["EXIT"]->setPosition((SCREEN_WIDTH / 2) - (text["EXIT"]->getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (text["PLAY"]->getGlobalBounds().height / 2) + 200.f);
}

void MainMenuState::loadAssets()
{
	this->data->assets.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
	this->data->assets.loadTexture("Game Title", GAME_TITLE_FILEPATH);
	this->data->assets.loadTexture(" Button", BUTTON_FILEPATH);
	
	this->data->assets.loadFont("Game Font", FONT_FILEPATH);
	
	this->data->assets.loadSoundBuffer("Click Button Sound", CLICK_BUTTON_EFFECT_PATH);
	this->data->assets.loadSoundBuffer("Menu Soundtrack", SOUNDTRACK_MENU_PATH);
}

MainMenuState::MainMenuState(GameDataRef data) : data(data)
{
	
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::init()
{
	
	this->loadAssets();
	this->initText();
	background.setTexture(this->data->assets.getTexture("Main Menu Background"));
	background.setScale(0.4f, 0.5f);
	title.setTexture(this->data->assets.getTexture("Game Title"));
	playButton.setTexture(this->data->assets.getTexture(" Button"));
	playButton.setScale(0.5f, 0.5f);
	scoresButton.setTexture(this->data->assets.getTexture(" Button"));
	scoresButton.setScale(0.5f, 0.5f);
	exitButton.setTexture(this->data->assets.getTexture(" Button"));
	exitButton.setScale(0.5f, 0.5f);

	title.setPosition((SCREEN_WIDTH / 2) - (title.getGlobalBounds().width / 2), title.getGlobalBounds().height / 2);
	playButton.setPosition((SCREEN_WIDTH / 2) - (playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (playButton.getGlobalBounds().height / 2)-200.f);
	scoresButton.setPosition((SCREEN_WIDTH / 2) - (playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (playButton.getGlobalBounds().height / 2));
	exitButton.setPosition((SCREEN_WIDTH / 2) - (playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (playButton.getGlobalBounds().height / 2)+200.f);
	
	this->clickButton.setBuffer(this->data->assets.getSoundBuffer("Click Button Sound"));
	this->soundtrack.setBuffer(this->data->assets.getSoundBuffer("Menu Soundtrack"));
	
	this->soundtrack.play();

}

void MainMenuState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}
		
			if (this->data->input.isSpriteTracked(this->playButton, sf::Mouse::Left, this->data->window)) {
				this->text["PLAY"]->setFillColor(sf::Color::Red);
			}
			else {
				this->text["PLAY"]->setFillColor(sf::Color::White);
			}
			if (this->data->input.isSpriteTracked(this->scoresButton, sf::Mouse::Left, this->data->window)) {
				this->text["SCORES"]->setFillColor(sf::Color::Red);
			}
			else {
				this->text["SCORES"]->setFillColor(sf::Color::White);
			}

			if (this->data->input.isSpriteTracked(this->exitButton, sf::Mouse::Left, this->data->window)) {
				this->text["EXIT"]->setFillColor(sf::Color::Red);
			}
			else {
				this->text["EXIT"]->setFillColor(sf::Color::White);
			}
			
		
		

		if (this->data->input.isSpriteClicked(this->playButton, sf::Mouse::Left, this->data->window))
		{
			this->clickButton.play();
			this->soundtrack.stop();
			this->data->machine.addState(StateRef(new GameState(data)), false);
			
		}
		if (this->data->input.isSpriteClicked(this->scoresButton, sf::Mouse::Left, this->data->window))
		{
			this->clickButton.play();
			this->data->machine.addState(StateRef(new ScoresState(data)), false);
			
		}
		if (this->data->input.isSpriteClicked(this->exitButton, sf::Mouse::Left, this->data->window))
		{
			
			this->clickButton.play();
			exit(0);
		}
	}
}

void MainMenuState::update(float dt)
{
	
}

void MainMenuState::draw(float dt)
{
	this->data->window.clear(sf::Color::Red);

	this->data->window.draw(this->background);
	this->data->window.draw(this->title);
	this->data->window.draw(this->playButton);
	this->data->window.draw(this->scoresButton);
	this->data->window.draw(this->exitButton);
	this->data->window.draw(*this->text["PLAY"]);
	this->data->window.draw(*this->text["SCORES"]);
	this->data->window.draw(*this->text["EXIT"]);
	this->data->window.display();
} 