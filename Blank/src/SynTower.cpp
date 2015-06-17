/**
@file SynTower.cpp
*/

#include "SynTower.h"

SynTower::SynTower(FileLoader* assets)
{
	cost = 200;
	damage = 0;
	rateOfFire = 1;
	range = 60;
	bulletSpeed = 1;
	sprite.setTexture(assets->buttonTextures.at(2));
	sprite.setOrigin(assets->buttonTextures.at(2).getSize().x/2,assets->buttonTextures.at(2).getSize().y/2);
	sprite.setPosition(300,300);

	rangeCircle.setRadius(range);
	rangeCircle.setOrigin(range,range);
	rangeCircle.setPosition(sprite.getPosition());
}

void SynTower::shoot(Enemy* target)
{

}

void SynTower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(selected) target.draw(rangeCircle);
	target.draw(sprite);
}