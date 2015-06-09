#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "FileLoader.h"

class Enemy : public sf::Drawable
{
private:
	float startHealth;
	float health;
	float speed;
	float radius;
	int targetNode;
	sf::Sprite sprite;
	sf::Vector2f velocity;
	sf::Vector2f position;
	//sf::CircleShape sprite;
	sf::RectangleShape healthBar;
	std::vector<sf::Vector2f>* path;
public:
	Enemy();
	Enemy(std::vector<sf::Vector2f>* path, FileLoader* assets);
	void update();
	sf::Vector2f getPosition();
	int getRadius();
	void moveTo(sf::Vector2f target);
	bool isDead(int dmg);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif ENEMY_H