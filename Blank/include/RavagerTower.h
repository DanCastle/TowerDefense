#ifndef RAVAGERTOWER_H
#define RAVAGERTOWER_H

#include "Tower.h"

class RavagerTower : public Tower
{
private:
public:
	RavagerTower(FileLoader* assets);
	void shoot(Enemy* target);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif RAVAGERTOWER_H