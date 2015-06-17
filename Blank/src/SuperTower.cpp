/**
@file SuperTower.cpp
*/

#include "SuperTower.h"

SuperTower::SuperTower(FileLoader* assets)
{
	cost = 1000;
	damage = 100;
	rateOfFire = 2;
	range = 250;
	bulletSpeed = 20;
	sprite.setTexture(assets->buttonTextures.at(5));
	sprite.setOrigin(assets->buttonTextures.at(5).getSize().x/2,assets->buttonTextures.at(5).getSize().y/2);
	sprite.setPosition(300,300);

	rangeCircle.setRadius(range);
	rangeCircle.setOrigin(range,range);
	rangeCircle.setPosition(sprite.getPosition());
}

void SuperTower::shoot(Enemy* target)
{
	float deltaX = target->getPosition().x - position.x;
	float deltaY = target->getPosition().y - position.y;

	float radians = atan2f(deltaY, deltaX);

	int x = bulletSpeed*cosf(radians);
	int y = bulletSpeed*sinf(radians);

	Bullet newBullet(position, sf::Vector2f(x,y), damage, false); //better to have a bool stored
																 //can upgrade to magic
	bullets.push_back(newBullet);

	canShoot = false;
	timeSinceShot.restart();
}

void SuperTower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	if(selected) target.draw(rangeCircle);
	target.draw(sprite);
	
	for(int i = 0; i < bullets.size(); i++)
	{
		target.draw(bullets.at(i));
	}
}