#ifndef SUPERTOWER_H
#define SUPERTOWER_H

#include "Tower.h"

class SuperTower : public Tower
{
private:
public:
	SuperTower(FileLoader* assets);
	void shoot(Enemy* target);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif SUPERTOWER_H