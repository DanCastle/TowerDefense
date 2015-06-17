/**
@file RavagerTower.cpp
*/

#include "RavagerTower.h"

RavagerTower::RavagerTower(FileLoader* assets)
{
	cost = 100;
	damage = 75;
	rateOfFire = 1.5;
	range = 100;
	bulletSpeed = 14;
	sprite.setTexture(assets->buttonTextures.at(1));
	sprite.setOrigin(assets->buttonTextures.at(1).getSize().x/2,assets->buttonTextures.at(1).getSize().y/2);
	sprite.setPosition(300,300);

	rangeCircle.setRadius(range);
	rangeCircle.setOrigin(range,range);
	rangeCircle.setPosition(sprite.getPosition());
}

void RavagerTower::shoot(Enemy* target)
{
	float deltaX = target->getPosition().x - position.x;
	float deltaY = target->getPosition().y - position.y;

	float radians = atan2f(deltaY, deltaX);

	int x = bulletSpeed*cosf(radians);
	int y = bulletSpeed*sinf(radians);

	Bullet newBullet(position, sf::Vector2f(x,y), damage, true);

	bullets.push_back(newBullet);

	canShoot = false;
	timeSinceShot.restart();
}

void RavagerTower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	if(selected) target.draw(rangeCircle);
	target.draw(sprite);
	
	for(int i = 0; i < bullets.size(); i++)
	{
		target.draw(bullets.at(i));
	}
}