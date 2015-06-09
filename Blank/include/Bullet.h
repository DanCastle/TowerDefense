#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable
{
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::CircleShape sprite;
	int radius;
	int damage;
public:
	Bullet();
	Bullet(sf::Vector2f pos, sf::Vector2f vel, int dmg);
	sf::Vector2f getPosition();
	int getRadius();
	int getDamage();
	void setPosition(sf::Vector2f);
	void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif BULLET_H