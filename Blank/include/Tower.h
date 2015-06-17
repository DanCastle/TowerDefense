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
	void setPlaceable(bool placeable);
	void updateCanShoot();
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	sf::Time getTimer();
	int getRange();
	int getCost();
	int getPlacementRadius();
	float getRoF();
	bool getCanShoot();
	bool outOfRange(Bullet* bullet);
	bool isPlaceable();
	void place();
	void select();
	void deselect();
	
protected:
	int cost;
	int damage;
	float rateOfFire;
	int range;
	int level;
	int xp;
	int placementRadius;
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Clock timeSinceShot;
	sf::CircleShape rangeCircle, placementCircle;
	bool canShoot;
	bool placing, placeable, selected;
	std::vector<Bullet> bullets;
	int bulletSpeed;
};

#endif TOWER_H