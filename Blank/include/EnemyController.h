#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "FileLoader.h"

class EnemyController : public sf::Drawable
{
private:
	std::vector<Enemy> enemies;
	std::vector<sf::Vector2f>path;
	int waveSize;
	sf::Clock enemyTimer;
	int enemyDelay; //ms
	FileLoader* assets;
public:
	EnemyController();
	EnemyController(FileLoader* assets);
	void updateEnemies();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<Enemy>* getEnemies();
};

#endif ENEMYCONTROLLER_H