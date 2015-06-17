#include "Enemy.h"

Enemy::Enemy()
{
	speed = 0;
	position = sf::Vector2f(0,0);
	velocity = sf::Vector2f(0,0);
	radius = 10;
	escaped = false;

	healthBar.setFillColor(sf::Color::Red);
	healthBar.setOutlineThickness(1);
	healthBar.setOutlineColor(sf::Color::Black);
	healthBar.setPosition(position.x, position.y - radius - 20);
	healthBar.setSize(sf::Vector2f(radius, radius*2));
}

Enemy::Enemy(std::vector<sf::Vector2f>* path, FileLoader* assets, bool armoured, bool flying, bool speedy)
{
	this->path = path;

	startHealth = 100;
	health = 100;
	loot = 10;
	radius = 12;

	speed = 3; //magicnumber!
	position = path->at(0);
	moveTo(path->at(1));

	escaped = false;
	this->armoured = armoured;
	this->flying = flying;
	this->speedy = speedy;

	if(speedy) speed*=2;
	
	//sprite.setTexture(assets->enemySprites.at(0));
	//radius = sprite.getLocalBounds().width/2;
	sprite.setRadius(radius);
	sprite.setOrigin(radius,radius);
	sprite.setFillColor(sf::Color::White);

	targetNode = 1;

	healthBar.setFillColor(sf::Color::Red);
	healthBar.setOutlineThickness(1);
	healthBar.setOutlineColor(sf::Color::Black);
	healthBar.setPosition(position.x, position.y - radius - 20);
	healthBar.setSize(sf::Vector2f(radius*2, radius/2));

	//Armour section
	if (armoured == true)
	{
		//sprite.setColor(sf::Color::Red);
		sprite.setOutlineThickness(2);
		sprite.setOutlineColor(sf::Color::Black);
	}

}

void Enemy::update()
{

	if (abs(path->at(targetNode).x - position.x) < speed &&
		abs(path->at(targetNode).y - position.y) < speed)
	{
		if (targetNode < path->size() -1) 
		{
			targetNode++;
			moveTo(path->at(targetNode));
		}

		else
		{
			escaped = true;
			velocity = sf::Vector2f(0,0);
		}
	}

	position += velocity;
	sprite.setPosition(position);
	healthBar.setSize(sf::Vector2f(radius * 2 * (health/startHealth), radius/2));
	healthBar.setPosition(position.x - radius, position.y - radius - 10);
}

sf::Vector2f Enemy::getPosition()
{
	return position;
}

int Enemy::getRadius()
{
	return radius;
}

int Enemy::getLoot()
{
	return loot;
}

void Enemy::moveTo(sf::Vector2f target)
{
	float deltaX = target.x - position.x;
	float deltaY = target.y - position.y;

	float radians = atan2f(deltaY, deltaX);

	int x = speed*cosf(radians);
	int y = speed*sinf(radians);

	velocity = sf::Vector2f(x,y);
}

bool Enemy::isDead(int dmg)
{
	health -= dmg;
	if (health <= 0) return true;
	else return false;
}

bool Enemy::hasEscaped()
{
	return escaped;
}

bool Enemy::isArmoured()
{
	return armoured;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
	target.draw(healthBar);
}