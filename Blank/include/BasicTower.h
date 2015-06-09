#ifndef BASICTOWER_H
#define BASICTOWER_H

#include "Tower.h"

class BasicTower : public Tower
{
private:

public:
	BasicTower(FileLoader* assets);
	void shoot(Enemy* target);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif BASICTOWER_H