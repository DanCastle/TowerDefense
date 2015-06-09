#ifndef SYNTOWER_H
#define SYNTOWER_H

#include "Tower.h"

class SynTower : public Tower
{
private:

public:
	SynTower(FileLoader* assets);
	void shoot(Enemy* target);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif SYN_TOWER