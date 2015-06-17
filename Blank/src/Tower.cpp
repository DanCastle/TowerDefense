/**
@file Tower.cpp
*/

#include "Tower.h"

Tower::Tower()
{
	level = 1;
	xp = 0;
	placing = true;
	selected = false;
	placeable = false;
	canShoot = false;

	placementRadius = 45;

	//rangeCircle.setRadius(range);
	rangeCircle.setPointCount(30);
	rangeCircle.setFillColor(sf::Color(255,255,255,100));
	//rangeCircle.setPosition(sprite.getPosition());
}

void Tower::shoot(Enemy* target)
{

}

void Tower::update()
{

		for (int i = 0; i < bullets.size(); i++)
	{
		bullets.at(i).update();

		if (outOfRange(&bullets.at(i)))
		{
			bullets.erase(bullets.begin()+i);
			i--;
		}
	}
}

void Tower::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos.x,pos.y);
	rangeCircle.setPosition(pos);
	position = pos;
}

void Tower::setPlaceable(bool placeable)
{
	this->placeable = placeable;

	if (placeable == false) rangeCircle.setFillColor(sf::Color(255,0,0,100));
	else rangeCircle.setFillColor(sf::Color(255,255,255,100));
};

void Tower::updateCanShoot()
{
	if (getTimer().asMilliseconds() > (1000/rateOfFire) && placing == false)
	{
		canShoot = true;
	}
}

sf::Vector2f Tower::getPosition()
{
	return position;
}

sf::Sprite Tower::getSprite()
{
	return sprite;
}

sf::Time Tower::getTimer()
{
	return timeSinceShot.getElapsedTime();
}

int Tower::getRange()
{
	return range;
}

int Tower::getCost()
{
	return cost;
}

int Tower::getPlacementRadius()
{
	return placementRadius;
}

float Tower::getRoF()
{
	return rateOfFire;
}

bool Tower::getCanShoot()
{
	return canShoot;
}

bool Tower::outOfRange(Bullet* bullet)
{
	sf::Vector2f delta = position - bullet->getPosition();
	float distance = sqrtf(powf(delta.x,2) + pow(delta.y,2));

	if (distance > range) return true;
	else return false;
}

bool Tower::isPlaceable()
{
	return placeable;
}

void Tower::place()
{
	placing = false;
	timeSinceShot.restart();
	canShoot = true;
}

void Tower::select()
{
	selected = true;
}

void Tower::deselect()
{
	selected = false;
}

std::vector<Bullet>* Tower::getBullets()
{
	return &bullets;
}
void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	if(selected) target.draw(rangeCircle);
	target.draw(sprite);
}