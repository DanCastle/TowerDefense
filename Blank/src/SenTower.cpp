/**
@file SenTower.cpp
*/

#include "SenTower.h"

SenTower::SenTower(FileLoader* assets)
{
	cost = 200;
	damage = 0;
	rateOfFire = 1;
	range = 60;
	bulletSpeed = 14;
	sprite.setTexture(assets->buttonTextures.at(4));
	sprite.setOrigin(assets->buttonTextures.at(4).getSize().x/2,assets->buttonTextures.at(4).getSize().y/2);
	sprite.setPosition(300,300);

	rangeCircle.setRadius(range);
	rangeCircle.setOrigin(range,range);
	rangeCircle.setPosition(sprite.getPosition());
}

void SenTower::shoot(Enemy* target)
{

}

void SenTower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{	
	if(selected) target.draw(rangeCircle);
	target.draw(sprite);
}