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
}

void SenTower::shoot(Enemy* target)
{

}

void SenTower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(range,30);
	circle.setFillColor(sf::Color(255,255,255,100));
	circle.setOrigin(range,range);
	circle.setPosition(sprite.getPosition());
	target.draw(circle);
	target.draw(sprite);
}