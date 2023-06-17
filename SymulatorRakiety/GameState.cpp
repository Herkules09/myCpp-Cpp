#include "GameState.h"

void GameState::init()
{
	this->initTextures();
	this->initVariables();
	this->initSoundEffects();
	this->data->assets.loadFont("Font", FONT_FILEPATH);
	background.setTexture(this->data->assets.getTexture("Game Background"));
	
	
	player = new Player(data);
	flash = new Flash(data);
	score = new Score(data);
	this->initEnemies();
	this->initGUI();
	

}


void GameState::initVariables()
{
	this->isGameOver = false;
	this->points = 0;
}

void GameState::initTextures()
{
	this->data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

	this->data->assets.loadTexture("Player 1", PLAYER_ROCKET1_PATH);

	this->data->assets.loadTexture(toString(EnemyType::ASTEROID), ENEMY_ASTEROID_PATH);
	this->data->assets.loadTexture(toString(EnemyType::ROCKET), ENEMY_ROCKET_PATH);
	this->data->assets.loadTexture(toString(EnemyType::BADBALL), ENEMY_BADBALL_PATH);
	this->data->assets.loadTexture(toString(EnemyType::HEALBALL), ENEMY_HEALTH_PATH);
	this->data->assets.loadTexture(toString(EnemyType::MARS), ENEMY_MARS_PATH);
	this->data->assets.loadTexture(toString(EnemyType::MOON), ENEMY_MOON_PATH);
	this->data->assets.loadTexture(toString(EnemyType::BOSS), ENEMY_BOSS_PATH);

	this->data->assets.loadTexture(toString(BulletType::BASIC), BULLET_1_PATH);
}

void GameState::initSoundEffects()
{
	this->data->assets.loadSoundBuffer("Shoot Sound", SHOT_EFFECT_PATH);
	this->shootSound.setBuffer(this->data->assets.getSoundBuffer("Shoot Sound"));
}

void GameState::initEnemies()
{
	this->spawnTimerMax = 70.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxEnemies = 9;
}

void GameState::initGUI()
{
	this->pointText.setFont(this->data->assets.getFont("Font"));
	this->pointText.setCharacterSize(18);
	this->pointText.setFillColor(sf::Color::White);
	this->healthText.setFont(this->data->assets.getFont("Font"));
	this->healthText.setCharacterSize(18);
	this->healthText.setFillColor(sf::Color::White);

	this->hpBarMax.setFillColor(sf::Color::White);
	this->hpBar.setFillColor(sf::Color::Red);
	this->hpBarMax.setPosition(110.f, 4.f);
	this->hpBar.setPosition(110.f, 4.f);
	this->hpBarMax.setSize(sf::Vector2f(40.f * (float)this->player->getHpMax(), 20.f));
	this->hpBar.setSize(sf::Vector2f(40.f * (float)this->player->getHpMax(), 20.f));
	
}

void GameState::updateGUI()
{
	std::stringstream ss;
	ss  << "HEALTH:" << "\n"
		<<"POINTS:" << this->points << "\n"
		;

	this->pointText.setString(ss.str());
	this->hpBar.setSize(sf::Vector2f((float)this->player->getHp() * 40.f, 20.f));
}


void GameState::updateInput()
{
	if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && this->player->canShoot()) {
		this->bullets.push_back(new Bullet(data,
			this->player->getPosition().x+15.f,
			this->player->getPosition().y, 0.f, -1.f, 10.f));
		shootSound.play();
	}
}

void GameState::updateEnemies()
{
	if (this->enemies.size() < this->maxEnemies) {
		if (this->spawnTimer >= this->spawnTimerMax) {
			this->enemies.push_back(new Enemy(data,rand() % (this->data->window.getSize().x -55)+10.f, -50.f));
			this->spawnTimer = 0.f;
		}
		else {
			this->spawnTimer += 0.5f +clock.getElapsedTime().asSeconds()/80;
		}
	}

	unsigned counter = 0;
	for (auto* enemy : this->enemies) {
		enemy->update();

		if (enemy->getBounds().top > this->data->window.getSize().y) {
			if (enemy->getType() == EnemyType::MARS || enemy->getType() == EnemyType::MOON) {
				this->isGameOver = true;
			}
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
			
		}
		else if (enemy->getBounds().intersects(this->player->getBounds())) {
			
			this->player->setHp(enemy->getDamage(), enemy->getHealing());
			if (this->player->getHp() == 0) {
				this->score->setActualScore(this->points);
				this->score->saveScores();
				this->clock.restart();
				this->isGameOver = true;
			}
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;
		}
		++counter;
	}

}

void GameState::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i) {
		bool enemyRemoved = false;
		for (size_t b = 0; b < bullets.size() && enemyRemoved == false; b++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[b]->getBounds())) {

				delete this->bullets[b];
				this->bullets.erase(this->bullets.begin() + b);
				this->enemies[i]->setHp(this->player->getDamage());
				if (this->enemies[i]->getHp() <= 0) {

					this->points += this->enemies[i]->getPoints();
					delete this->enemies[i];
					this->enemies.erase(this->enemies.begin() + i);

					enemyRemoved = true;
				}


			}
		}
	}
}
void GameState::renderGUI()
{
	data->window.draw(this->pointText);
	data->window.draw(this->hpBarMax);
	data->window.draw(this->hpBar);
}
void GameState::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets) {
		bullet->update();

		if (bullet->getBounds().top + bullet->getBounds().height < 0.f) {
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
		}
		++counter;
	}
}



GameState::GameState(GameDataRef data) : data(data)
{
	
}

GameState::~GameState()
{
	delete this->player;

	for (auto* bullet : this->bullets) {
		delete bullet;
	}

	for (auto* enemy : this->enemies) {
		delete enemy;
	}
}






void GameState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->data->window.close();
		}

		if (this->isGameOver) {
			
			this->data->machine.addState(StateRef(new GameOverState(data)), false);
		}
	}
}

void GameState::update(float dt)
{
	player->update();
	if (isGameOver) {
		this->flash->show(dt);
	}
	this->updateInput();
	this->updateCombat();
	this->updateEnemies();
	for (unsigned short int i = 0; i < enemies.size(); i++)
	{
		enemies.at(i)->moveShapes(dt);
	}
	this->updateBullets();
	this->updateGUI();
	
}

void GameState::draw(float dt)
{
	this->data->window.clear(sf::Color::Red);

	this->data->window.draw(this->background);
	player->draw();

	for (auto* bullet : this->bullets) {
		bullet->draw();
	}

	for (auto* enemy : this->enemies) {
		enemy->draw();
	}
	this->flash->draw();
	this->renderGUI();

	this->data->window.display();
}