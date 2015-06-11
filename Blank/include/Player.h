#ifndef PLAYER_H
#define PLAYER_H

#include "FileLoader.h"
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
private:
	int lives, money;
	sf::Text livesText, moneyText;
public:
	Player();
	Player(FileLoader* assets);
	void takeDamage(int dmg);
	void spendMoney(int spent);
	void gainMoney(int loot);
	int getLives();
	int getMoney();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif PLAYER_H