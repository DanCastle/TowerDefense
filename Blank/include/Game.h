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
#include "Player.h"
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
	Player player;
	sf::RenderWindow window;
	sf::RectangleShape shopBG;
	sf::Mouse mouse;
	sf::Sprite basicTowerShop;
	std::vector<sf::Text> damageTexts;
	bool placing;
	Tower* placingTower;
	int lives, money;
	float armourPercent; //Perecent of damage resisted from regular bullets

public:
	Game();
	void updateGame();
	void updateTowers();
	void updateDamageText();
	void handleClicks();
	void shootTowers();
	void checkCollisions(int i); //i being the position in tower vector
	void newBasicTower();
	void newRavagerTower();
	void newSynTower();
	void newSabTower();
	void newSenTower();
	void newSuperTower();
	void drawTowers();
	void newDamageText(sf::Vector2f pos, int dmg);
	vector<Tower*> getActiveTowers();
	bool collides(Bullet bullet, Enemy enemy);
	bool mouseOver(Button* button);
	bool windowOpen();
};

#endif GAME_H