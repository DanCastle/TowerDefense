#ifndef GAME_H
#define GAME_H

#include "Tower.h"
#include "BasicTower.h"
#include "RavagerTower.h"
#include "SynTower.h"
#include "SabTower.h"
#include "SenTower.h"
#include "SuperTower.h"
#include "FileLoader.h"
#include "Button.h"
#include "EnemyController.h"
#include "UI.h"
#include "Enemy.h"
#include "Bullet.h"
#include <iostream>
#include <cmath>

using namespace std;

class Game
{
private:
	vector<Tower*> activeTowers;
	FileLoader assets;
	EnemyController enemyController;
	UI userInterface;
	sf::RenderWindow window;
	sf::RectangleShape shopBG;
	sf::Mouse mouse;
	sf::Sprite basicTowerShop;
	bool placing;
	Tower* placingTower;
public:
	Game();
	void updateGame();
	void updateTowers();
	void handleClicks();
	void shootTowers();
	void newBasicTower();
	void newRavagerTower();
	void newSynTower();
	void newSabTower();
	void newSenTower();
	void newSuperTower();
	void drawTowers();
	vector<Tower*> getActiveTowers();
	bool collides(Bullet bullet, Enemy enemy);
	bool mouseOver(Button* button);
	bool windowOpen();
};

#endif GAME_H