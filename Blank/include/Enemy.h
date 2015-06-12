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
	int loot;
	bool escaped;
	bool armoured;
	sf::Sprite sprite;
	sf::Vector2f velocity;
	sf::Vector2f position;
	sf::RectangleShape healthBar;
	std::vector<sf::Vector2f>* path;
public:
	Enemy();
	Enemy(std::vector<sf::Vector2f>* path, FileLoader* assets, bool armour);
	void update();
	sf::Vector2f getPosition();
	int getRadius();
	int getLoot();
	void moveTo(sf::Vector2f target);
	bool isDead(int dmg);
	bool hasEscaped();
	bool isArmoured();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif ENEMY_H