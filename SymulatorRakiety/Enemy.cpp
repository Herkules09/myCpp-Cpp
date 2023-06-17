#include "Enemy.h"

void Enemy::initVariables()
{
	this->setType(this->randType());

	this->setParameters();
}

void Enemy::initShape()
{
	switch (this->type) {
	case MARS:
		this->enemyShape.setTexture(data->assets.getTexture(toString(EnemyType::MARS)));
		this->enemyShape.scale(0.06f, 0.06f);
		break;
	case MOON:
		this->enemyShape.setTexture(data->assets.getTexture(toString(EnemyType::MOON)));
		this->enemyShape.scale(0.02f, 0.02f);
		break;

	case ASTEROID:
		this->enemyShape.setTexture(data->assets.getTexture(toString(EnemyType::ASTEROID)));
		this->enemyShape.scale(0.1f, 0.1f);
		break;
	case HEALBALL:
		this->enemyShape.setTexture(data->assets.getTexture(toString(EnemyType::HEALBALL)));
		this->enemyShape.scale(0.1f, 0.1f);
		break;
	case ROCKET:
		this->enemyShape.setTexture(data->assets.getTexture(toString(EnemyType::ROCKET)));
		this->enemyShape.scale(0.1f, 0.1f);
		break;
	case BOSS:
		this->enemyShape.setTexture(data->assets.getTexture(toString(EnemyType::BOSS)));
		this->enemyShape.scale(0.1f, 0.1f);
		break;
	}
}

void Enemy::setType(const int type)
{
	this->type = type;
}

void Enemy::setParameters()
{
	switch (this->type) {
	case MARS:
		this->points = 1;
		this->hpMax = 1;
		this->hp = hpMax;
		this->damage = 1;
		this->healing = 0;
		break;
	case MOON:
		this->points = 1;
		this->hpMax = 1;
		this->hp = hpMax;
		this->damage = 1;
		this->healing = 0;
		break;
	case ASTEROID:
		this->points = 3;
		this->hpMax = 4;
		this->hp = hpMax;
		this->damage = 3;
		this->healing = 0;
		break;
	case HEALBALL:
		this->points = 0;
		this->hpMax = 10;
		this->hp = hpMax;
		this->damage = 0;
		this->healing = 1;
		break;
	case ROCKET:
		this->points = 5;
		this->hpMax = 2;
		this->hp = hpMax;
		this->damage = 3;
		this->healing = 0;
		break;
	case BOSS:
		this->points = 10;
		this->hpMax = 4;
		this->hp = hpMax;
		this->damage = 10;
		this->healing = 0;
		break;
	}
}

const int Enemy::randType() const
{
	int type;
	int randValue(rand() % 330 + 1);
	if (randValue <= 100) {
		type = EnemyType::MOON;
	}
	else if (randValue > 100 && randValue <= 200) {
		type = EnemyType::MARS;
	}
	else if (randValue > 200 && randValue <= 250) {
		type = EnemyType::ROCKET;
	}
	else if (randValue > 250 && randValue <= 270) {
		type = EnemyType::HEALBALL;
	}
	else if (randValue > 270 && randValue <= 290) {
		type = EnemyType::ASTEROID;
	}
	else {
		type = EnemyType::BOSS;
	}
	return type;
}

const int& Enemy::getType() const
{
	return this->type;
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const int& Enemy::getHp() const
{
	return this->hp;
}

const int& Enemy::getHpMax() const
{
	return this->hpMax;
}

void Enemy::setHp(int damage)
{
	this->hp -= damage;
}

const int& Enemy::getHealing() const
{
	return this->healing;
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->enemyShape.getGlobalBounds();
}

void Enemy::moveShapes(float dt)
{
	switch (this->type) {
	case MOON:
		this->enemyShape.move(0.f, 55.f*dt);
		break;
	case MARS:
		this->enemyShape.move(0.f, 50.f* dt);
		break;
	case ASTEROID:
		this->enemyShape.move(0.6f* dt, 7.f* dt);
		break;
	case HEALBALL:
		this->enemyShape.move(0.f, 70.f* dt);
		break;
	case ROCKET:
		this->enemyShape.move(0.f, 70.f* dt);
		break;
	case BOSS:
		this->enemyShape.move(0.f, 30.f* dt);
		break;
	}
}



Enemy::Enemy(GameDataRef data, float dir_x,float dir_y):data(data)
{
	this->initVariables();
	this->initShape();
	this->enemyShape.setPosition(dir_x, dir_y);
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
	
}

void Enemy::draw()
{
	data->window.draw(this->enemyShape);
}
