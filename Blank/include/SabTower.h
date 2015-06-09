#ifndef SABTOWER_H
#define SABTOWER_H

#include "Tower.h"

class SabTower : public Tower
{
private:
public:
	SabTower(FileLoader* asssets);
	void shoot(Enemy* target);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif SABTOWER_H