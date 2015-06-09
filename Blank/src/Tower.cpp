/**
@file Tower.cpp
*/

#include "Tower.h"

Tower::Tower()
{
	level = 1;
	xp = 0;
	placing = true;
	canShoot = false;
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
	position = pos;
}

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

sf::Time Tower::getTimer()
{
	return timeSinceShot.getElapsedTime();
}

int Tower::getRange()
{
	return range;
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

void Tower::place()
{
	placing = false;
	timeSinceShot.restart();
	canShoot = true;
}

std::vector<Bullet>* Tower::getBullets()
{
	return &bullets;
}
void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(range,30);
	circle.setFillColor(sf::Color(255,255,255,100));
	circle.setOrigin(range,range);
	circle.setPosition(sprite.getPosition());
	target.draw(circle);
	target.draw(sprite);
}