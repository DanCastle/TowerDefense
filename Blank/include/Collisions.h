#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "vector2D.h"
#include <SFML/Graphics.hpp>

const float REFRESH_RATE = 0.01666666666f;

class AABB : public sf::Drawable
{
private:
	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;

public:
	bool jumping;
	Vector2D min;
	Vector2D max;
	sf::Sprite AABB_sprite;
	sf::Texture AABB_texture;
	AABB(float x, float y);
	void setPos(float x, float y);
	void setVel(float x, float y);
	void setAccel(float x, float y);
	Vector2D getPosition();
	Vector2D getVelocity();
	Vector2D getAcceleration();
	bool intersects(AABB & other);	
	void euler();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;//!< Draw function

};

#endif COLLISIONS_H
