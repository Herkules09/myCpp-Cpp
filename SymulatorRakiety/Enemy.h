#ifndef ENEMY_H
#define ENEMY_H
#include"Header.h"
#include "Game.h"
#include"DEFINITIONS.h"
#include"TEX_NAMES.h"
;


class Enemy
{
private:
	GameDataRef data;
	sf::Sprite enemyShape;

	int hp;
	int hpMax;
	int type;
	int damage;
	int healing;
	unsigned points;

	void initVariables();
	void initShape();
	void setType(const int type);
	void setParameters();
public:
	Enemy(GameDataRef data, float dir_x, float dir_y);
	~Enemy();
	const int  randType() const;
	const int& getType() const;
	const int& getPoints() const;
	const int& getDamage() const;
	const int& getHp() const;
	const int& getHpMax() const;
	void setHp(int damage);
	const int& getHealing() const;
	const sf::FloatRect getBounds() const;
	void update();
	void draw();

};

#endif
