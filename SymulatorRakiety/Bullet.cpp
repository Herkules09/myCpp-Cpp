#include "Bullet.h"

void Bullet::initVariables()
{
	this->bulletShape.setScale(0.06f, 0.04f);
}

Bullet::Bullet()
{
}

Bullet::Bullet(GameDataRef data, float posX, float posY, float dirX, float dirY, float movementSpeed):data(data)
{
	
	this->bulletShape.setTexture(data->assets.getTexture(toString(BulletType::BASIC)));
	this->initVariables();
	this->bulletShape.setPosition(posX, posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = movementSpeed;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBounds() const
{
	return this->bulletShape.getGlobalBounds();
}

void Bullet::update()
{
	this->bulletShape.move(this->movementSpeed * this->direction);
}

void Bullet::draw()
{
	this->data->window.draw(this->bulletShape);
}
