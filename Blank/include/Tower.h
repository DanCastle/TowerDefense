#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>
#include "FileLoader.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Bullet.h"
#include "Enemy.h"

class Tower : public sf::Drawable
{

public:
	Tower();
	virtual void shoot(Enemy* target) = 0;
	virtual void update();
	virtual std::vector<Bullet>* getBullets();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setPosition(sf::Vector2f pos);
	void updateCanShoot();
	sf::Vector2f getPosition();
	sf::Time getTimer();
	int getRange();
	int getCost();
	float getRoF();
	bool getCanShoot();
	bool outOfRange(Bullet* bullet);
	void place();
	
protected:
	int cost;
	int damage;
	float rateOfFire;
	int range;
	int level;
	int xp;
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Clock timeSinceShot;
	bool canShoot;
	bool placing;
	std::vector<Bullet> bullets;
	int bulletSpeed;
};

#endif TOWER_H