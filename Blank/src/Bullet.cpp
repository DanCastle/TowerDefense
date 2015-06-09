#include "Bullet.h"

Bullet::Bullet()
{
	position = sf::Vector2f(0,0);
	velocity = sf::Vector2f(0,0);
	radius = 8;
	sprite.setRadius(radius);
	sprite.setOrigin(radius,radius);
	sprite.setFillColor(sf::Color::Black);
}

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f vel, int dmg)
{
	position = pos;
	velocity = vel;
	radius = 6;
	damage = dmg;
	sprite.setRadius(radius);
	sprite.setOrigin(radius,radius);
	sprite.setFillColor(sf::Color::Black);
}

sf::Vector2f Bullet::getPosition()
{
	return position;
}

int Bullet::getRadius()
{
	return radius;
}

int Bullet::getDamage()
{
	return damage;
}

void Bullet::setPosition(sf::Vector2f pos)
{
	position = pos;
}

void Bullet::update()
{
	position += velocity;
	sprite.setPosition(position);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
}