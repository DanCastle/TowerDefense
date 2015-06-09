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
	sprite.setTexture(assets->towerTextures.at(2));
	sprite.setOrigin(assets->towerTextures.at(2).getSize().x/2,assets->towerTextures.at(2).getSize().y/2);
	sprite.setPosition(300,300);
}

void SynTower::shoot(Enemy* target)
{

}

void SynTower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(range,30);
	circle.setFillColor(sf::Color(255,255,255,100));
	circle.setOrigin(range,range);
	circle.setPosition(sprite.getPosition());
	target.draw(circle);
	target.draw(sprite);
}