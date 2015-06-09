#include "Game.h"

Game::Game()
{
	window.create(sf::VideoMode(1024, 768), "Tower Defense");

	shopBG.setFillColor(sf::Color(50,50,50,255));
	shopBG.setSize(sf::Vector2f(180,768));

	placing = false;

	UI newInterface(&window, &assets);
	userInterface = newInterface;

	EnemyController newController(&assets);
	enemyController = newController;

}

void Game::updateGame()
{
	window.clear(sf::Color(200,20,50));

	sf::Event Event;
    while (window.pollEvent(Event))
    {

        if (Event.type == sf::Event::Closed)
            window.close();

    }

	userInterface.update();
	
	handleClicks();

	enemyController.updateEnemies();

	updateTowers();
	shootTowers();

	drawTowers();
	window.draw(shopBG);

	window.draw(userInterface);
	window.draw(enemyController);
	window.display();
}

void Game::updateTowers()
{
	for (int i = 0; i < activeTowers.size(); i++)
	{
		//Tower* temp = activeTowers.at(i);
		activeTowers.at(i)->updateCanShoot();

		activeTowers.at(i)->update();

		std::vector<Bullet>* bullets = activeTowers.at(i)->getBullets();
		std::vector<Enemy>* enemies = enemyController.getEnemies();

		for (int i = 0; i < bullets->size(); i++)
		{
			Bullet tempBullet = bullets->at(i);

			for (int j = 0; j < enemies->size(); j++)
			{
				Enemy tempEnemy = enemies->at(j);
				if (collides(tempBullet, tempEnemy))
				{
					bullets->erase(bullets->begin()+i);
					i--;
					if (enemies->at(j).isDead(tempBullet.getDamage()))
					{
						enemies->erase(enemies->begin()+j);
					}
					j = enemies->size();
					
				}
			}

		}

	}

	if (placing == true)
	{
		//basicTowers.at(basicTowers.size()-1).setPosition((sf::Vector2f)mouse.getPosition(window));
		//placingTower->setPosition((sf::Vector2f)mouse.getPosition(window));
		activeTowers.at(activeTowers.size()-1)->setPosition((sf::Vector2f)mouse.getPosition(window));
	}

}

void Game::handleClicks()
{
	std::vector<Button>* buttons = userInterface.getShopButtons();

	for (int i = 0; i < buttons->size(); i++)
	{
		if (placing == false && userInterface.clicked(&buttons->at(i)))
		{
			placing = true;
			switch(i) 
			{
			case 0: newBasicTower(); break;
			case 1: newRavagerTower(); break;
			case 2: newSynTower(); break;
			case 3: newSabTower(); break;
			case 4: newSenTower(); break;
			case 5: newSuperTower(); break;
			}
		}

		if (placing == true && userInterface.rightClicked())
		{
			placing = false;
			activeTowers.at(activeTowers.size()-1)->place();
		}
	}
}

void Game::shootTowers()
{
	//cycle through all towers checking collisions with all enemies
	for (int i = 0; i < activeTowers.size(); i++)
	{
		Tower* tempTower = activeTowers.at(i);
		for (int j = 0; j < enemyController.getEnemies()->size(); j++)
		{
			Enemy tempEnemy = enemyController.getEnemies()->at(j);

			if (tempTower->getCanShoot())
			{
				if ( sqrt(pow(tempTower->getPosition().x - tempEnemy.getPosition().x , 2) +
					      pow(tempTower->getPosition().y - tempEnemy.getPosition().y , 2) )
						  - tempTower->getRange() - tempEnemy.getRadius()
						  < 0 )
				{
					/*BasicTower* basicCasted = dynamic_cast<BasicTower*>(tempTower);
					RavagerTower* ravagerCasted = dynamic_cast<RavagerTower*>(tempTower);
					if (basicCasted){ basicCasted->shoot(&tempEnemy); }
					else if (ravagerCasted) { ravagerCasted->shoot(&tempEnemy); }*/
					tempTower->shoot(&tempEnemy);
				}
			}
		}
	}
	//if enemy is found in range, shoot() at it, set readyToFire to false
	//start timer for rate of fire.
}

void Game::newBasicTower()
{
	BasicTower newTower(&assets);
	//basicTowers.push_back(new BasicTower(&assets));
	//activeTowers.push_back(&basicTowers.at(basicTowers.size() -1));
	activeTowers.push_back(new BasicTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);

	//the use of individual vectors may be avoided by using 'new' to pass pointer (not &)
	//cleaning would have to be handled seperately however
}

void Game::newRavagerTower()
{
	RavagerTower newTower(&assets);
	//ravagerTowers.push_back(newTower);
	//activeTowers.push_back(&ravagerTowers.at(ravagerTowers.size() -1));
	activeTowers.push_back(new RavagerTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::newSynTower()
{
	SynTower newTower(&assets);
	//synTowers.push_back(newTower);
	//activeTowers.push_back(&synTowers.at(synTowers.size() -1));
	activeTowers.push_back(new SynTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::newSabTower()
{
	SabTower newTower(&assets);
	//sabTowers.push_back(newTower);
	//activeTowers.push_back(&sabTowers.at(sabTowers.size() -1));
	activeTowers.push_back(new SabTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::newSenTower()
{
	SenTower newTower(&assets);
	//senTowers.push_back(newTower);
	//activeTowers.push_back(&senTowers.at(senTowers.size() -1));
	activeTowers.push_back(new SenTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::newSuperTower()
{
	SuperTower newTower(&assets);
	//superTowers.push_back(newTower);
	//activeTowers.push_back(&superTowers.at(superTowers.size() -1));
	activeTowers.push_back(new SuperTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

vector<Tower*> Game::getActiveTowers()
{
	return activeTowers;
}

bool Game::collides(Bullet bullet, Enemy enemy)
{
	sf::Vector2f delta = bullet.getPosition() - enemy.getPosition();

	float dist = sqrtf(pow(delta.x,2) + pow(delta.y,2));

	if (dist - enemy.getRadius() - bullet.getRadius() < 0) return true;
	else return false;
}

bool Game::mouseOver(Button* button)
{

	int mouseX = mouse.getPosition(window).x;
	int mouseY = mouse.getPosition(window).y;

	//cout << minX << " " << maxX << " " << minY << " " << maxY << endl;
	//cout << mouse.getPosition().x << " " << mouse.getPosition().y << endl;

	if (mouseX < button->getMinX() || mouseX > button->getMaxX() ) return false;
	if (mouseY < button->getMinY() || mouseY > button->getMaxY() ) return false;

	return true;
}

bool Game::windowOpen()
{
	return window.isOpen();
}

void Game::drawTowers()
{
	/*for (int i = 0; i < basicTowers.size(); i++)
	{
		window.draw(basicTowers.at(i));
	}

	for (int i = 0; i < ravagerTowers.size(); i++)
	{
		window.draw(ravagerTowers.at(i));
	}

	for (int i = 0; i < synTowers.size(); i++)
	{
		window.draw(synTowers.at(i));
	}

	for (int i = 0; i < sabTowers.size(); i++)
	{
		window.draw(sabTowers.at(i));
	}

	for (int i = 0; i < senTowers.size(); i++)
	{
		window.draw(senTowers.at(i));
	}

	for (int i = 0; i < superTowers.size(); i++)
	{
		window.draw(superTowers.at(i));
	}*/

	//!Why does it not like drawing the arary for all towers?

	for (int i = 0; i < activeTowers.size(); i++)
	{
		window.draw(*activeTowers.at(i));
	}
}