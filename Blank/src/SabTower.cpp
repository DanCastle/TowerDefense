/**
@file SabTower.cpp
*/

#include "SabTower.h"

SabTower::SabTower(FileLoader* assets)
{
	cost = 200;
	damage = 0;
	rateOfFire = 0.5;
	range = 100;
	bulletSpeed = 25;
	sprite.setTexture(assets->towerTextures.at(3));
	sprite.setOrigin(assets->towerTextures.at(3).getSize().x/2,assets->towerTextures.at(3).getSize().y/2);
	sprite.setPosition(300,300);
}

void SabTower::shoot(Enemy* target)
{
	float deltaX = target->getPosition().x - position.x;
	float deltaY = target->getPosition().y - position.y;

	float radians = atan2f(deltaY, deltaX);

	int x = bulletSpeed*cosf(radians);
	int y = bulletSpeed*sinf(radians);

	Bullet newBullet(position, sf::Vector2f(x,y), damage);

	bullets.push_back(newBullet);

	canShoot = false;
	timeSinceShot.restart();
}


void SabTower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(range,30);
	circle.setFillColor(sf::Color(255,255,255,100));
	circle.setOrigin(range,range);
	circle.setPosition(sprite.getPosition());
	target.draw(circle);
	target.draw(sprite);

	for(int i = 0; i < bullets.size(); i++)
	{
		target.draw(bullets.at(i));
	}
}