#ifndef SENTOWER_H
#define SENTOWER_H

#include "Tower.h"

class SenTower : public Tower
{
private:
	
public:
	SenTower(FileLoader* assets);
	void shoot(Enemy* target);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif SENTOWER_H