#include "Collisions.h"

AABB::AABB(float x, float y)
{
	setPos(x,y);
	setAccel(0,250);
	AABB_texture.loadFromFile(".\\assets\\graphics\\testPlayer.bmp");
	AABB_sprite.setTexture(AABB_texture);
	AABB_sprite.setPosition(x,y);
	jumping = true;
}

void AABB::draw(sf::RenderTarget& target, sf::RenderStates states) const //!< draws the background to the screen
{
	target.draw(AABB_sprite);
}

bool AABB::intersects(AABB & other)
	{ 
		if ((max.getX() < other.max.getX()) || (min.getX() > other.min.getX())) return false;
		if ((max.getY() < other.max.getY()) || (min.getY() > other.min.getY())) return false;
		return true;
	}

void AABB::setPos(float x,float y)
{
	position.setX(x);
	position.setY(y);

	return;
}

void AABB::setVel(float x,float y)
{
	velocity.setX(x);
	velocity.setY(y);

	return;
}

void AABB::setAccel(float x,float y)
{
	acceleration.setX(x);
	acceleration.setY(y);

	return;
}

Vector2D AABB::getPosition()
{
	Vector2D x = position;
	return x;
}

Vector2D AABB::getVelocity()
{
	Vector2D x = velocity;
	return x;
}

Vector2D AABB::getAcceleration()
{
	Vector2D x = acceleration;
	return x;
}

void AABB::euler()
{
	Vector2D r = getPosition();
	Vector2D v = getVelocity();
	Vector2D a = getAcceleration();

	float newVX = v.getX() + (a.getX()*REFRESH_RATE);
	float newRX = r.getX() + ((v.getX() + newVX)*(REFRESH_RATE/2));

	float newVY = v.getY() + (a.getY()*REFRESH_RATE);
	float newRY = r.getY() + ((v.getY() + newVY)*(REFRESH_RATE/2));

	if (newRY > 550) 
		{ 
			newRY = 550;
			newVX = 0;
			newVY = 0;
			jumping = false;
	}

	setVel(newVX,newVY);
	setPos(newRX,newRY);

	AABB_sprite.setPosition(newRX,newRY);

	return;

}