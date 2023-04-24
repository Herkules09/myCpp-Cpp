#include "ScoresState.h"

void ScoresState::initAssets()
{
	this->data->assets.loadTexture("Background texture", GAME_BACKGROUND_FILEPATH);
	this->data->assets.loadTexture("goBackButton", BUTTON_FILEPATH);
	this->data->assets.loadTexture("goBack", GO_BACK_BUTTON_FILEPATH);
	this->data->assets.loadTexture("goBackRed", GO_BACK_RED_BUTTON_FILEPATH);

	this->data->assets.loadSoundBuffer("Menu Soundtrack1", SOUNDTRACK_MENU_PATH);
	this->data->assets.loadSoundBuffer("Click Button", CLICK_BUTTON_EFFECT_PATH);
}

ScoresState::ScoresState(GameDataRef data):data(data)
{

}

ScoresState::~ScoresState()
{
	this->soundtrack.stop();
}

void ScoresState::init()
{
	this->initAssets();
	this->soundtrack.setBuffer(this->data->assets.getSoundBuffer("Menu Soundtrack1"));
	this->clickButton.setBuffer(this->data->assets.getSoundBuffer("Click Button"));
	this->background.setTexture(data->assets.getTexture("Background texture"));
	this->data->assets.loadFont("Game Font", FONT_FILEPATH);
	this->title.setFillColor(sf::Color::White);
	this->title.setFont(data->assets.getFont("Game Font"));
	this->title.setCharacterSize(40);
	this->title.setString("RESULTS HISTORY");
	this->title.setPosition((SCREEN_WIDTH / 2) - (title.getGlobalBounds().width / 2), title.getGlobalBounds().height / 2);
	this->score_text.setFillColor(sf::Color::White);
	this->score_text.setFont(data->assets.getFont("Game Font"));
	this->score_text.setCharacterSize(30);
	this->score_text.setPosition((SCREEN_WIDTH / 2) - (score_text.getGlobalBounds().width / 2 +20.f), title.getGlobalBounds().top +120.f);
	this->hightscore_text.setFillColor(sf::Color::Red);
	this->hightscore_text.setFont(data->assets.getFont("Game Font"));
	this->hightscore_text.setCharacterSize(30);
	this->hightscore_text.setPosition((SCREEN_WIDTH / 3) - (hightscore_text.getGlobalBounds().width+55.f), title.getGlobalBounds().top + 60.f);
	score = new Score(data);
	this->results = score->getScoresFromFile(HISTORY_SCORES_PATH, HIGHTSCORE_PATH);

	std::stringstream ss;
	for (std::string s : results) {
		ss << s << "\n";
		

	}
	
	this->score_text.setString(ss.str());
	this->hightscore_text.setString("HIGHTSCORE: " + std::to_string(score->getHightScore()));

	this->goBackButton.setTexture(data->assets.getTexture("goBackButton"));
	this->goBackButton.setScale(0.2f, 0.4f);
	this->goBackButton.setPosition(50.f, 670.f);
	this->goBack.setTexture(data->assets.getTexture("goBack"));
	//this->goBack.setScale(0.2f, 0.4f);
	this->goBack.setPosition(84.f, 743.f);
	//this->soundtrack.play();

}

void ScoresState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}

		if (this->data->input.isSpriteTracked(this->goBackButton, sf::Mouse::Left, this->data->window)) {
			this->goBack.setTexture(data->assets.getTexture("goBackRed"));
		}
		else {
			this->goBack.setTexture(data->assets.getTexture("goBack"));
		}

		if (this->data->input.isSpriteClicked(this->goBackButton, sf::Mouse::Left, this->data->window))
		{
			//TODO: Sountrack error 
			this->data->machine.addState(StateRef(new MainMenuState(data)), false);
		}

	}
}

void ScoresState::update(float dt)
{
}

void ScoresState::draw(float dt)
{
	this->data->window.clear(sf::Color::Red);

	this->data->window.draw(this->background);
	this->data->window.draw(this->title);
	this->data->window.draw(this->hightscore_text);
	this->data->window.draw(this->score_text);
	this->data->window.draw(this->goBackButton);
	this->data->window.draw(this->goBack);
	this->data->window.display();
}
