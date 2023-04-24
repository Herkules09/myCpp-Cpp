#include "Player.h"

Player::Player(GameDataRef data) : data(data)
{
	this->initVariables();
	playerShape.setTexture(data->assets.getTexture("Player 1"));
	playerShape.setScale(0.2f, 0.2f);
	playerShape.setPosition(SCREEN_WIDTH / 2 - playerShape.getGlobalBounds().width / 2, SCREEN_HEIGHT / 2 + playerShape.getGlobalBounds().height);

}

Player::~Player()
{
}



void Player::move(const float dirX, const float dirY)
{
	this->playerShape.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canShoot()
{
	if (this->shootingColdown >= this->shootingColdownMax) {
		this->shootingColdown = 0.f;

		return true;
	}
	return false;
}

void Player::initVariables()
{
	this->hpMax = 5;
	this->hp = hpMax;
	this->movementSpeed = 4.f;
	this->shootingColdownMax = 30.f;
	this->damage = 1;
	this->shootingColdown = this->shootingColdownMax;
}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->move(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->move(0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(1.f, 0.f);
	}
}

void Player::updateShooting()
{
	if (this->shootingColdown < this->shootingColdownMax) {
		this->shootingColdown += 1.f;
	}
}

void Player::updateWindowsBoundsCollision()
{
	if (this->playerShape.getGlobalBounds().left <= 0.f) {
		this->playerShape.setPosition(0.f, this->playerShape.getGlobalBounds().top);
	}
	else if (this->playerShape.getGlobalBounds().left + this->playerShape.getGlobalBounds().width >= data->window.getSize().x) {
		this->playerShape.setPosition(data->window.getSize().x - this->playerShape.getGlobalBounds().width, this->playerShape.getGlobalBounds().top);
	}
	if (this->playerShape.getGlobalBounds().top <= 0.f) {
		this->playerShape.setPosition(this->playerShape.getGlobalBounds().left, 0.f);
	}
	else if (this->playerShape.getGlobalBounds().top + this->playerShape.getGlobalBounds().height >= data->window.getSize().y) {
		this->playerShape.setPosition(this->playerShape.getGlobalBounds().left, data->window.getSize().y - this->playerShape.getGlobalBounds().height);
	}
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

const int& Player::getDamage() const
{
	return this->damage;
}

void Player::setPosition(const sf::Vector2f position)
{
	this->playerShape.setPosition(position);
}

void Player::setPosition(const float x, const float y)
{
	this->playerShape.setPosition(x, y);
}

void Player::setHp(int damage, int health)
{
	this->hp = this->hp + health - damage;
	if (this->hp > this->hpMax) {
		this->hp = this->hpMax;
	}
	else if (this->hp < 0) {
		this->hp = 0;
	}
}



const sf::Vector2f& Player::getPosition()
{
	return this->playerShape.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->playerShape.getGlobalBounds();
}

void Player::update()
{
	this->updateInput();
	this->updateWindowsBoundsCollision();
	this->updateShooting();
}

void Player::draw()
{
	data->window.draw(playerShape);
}
