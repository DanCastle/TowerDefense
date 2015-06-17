#include "Game.h"

Game::Game()
{
	window.create(sf::VideoMode(1024, 768), "Tower Defense");

	shopBG.setFillColor(sf::Color(50,50,50,255));
	shopBG.setSize(sf::Vector2f(180,768));

	placing = false;

	UI newInterface(&window, &assets);
	userInterface = newInterface;

	Player newPlayer(&assets);
	player = newPlayer;

	EnemyController newController(&assets, &player);
	enemyController = newController;

	lives = 20;
	money = 100;

	armourPercent = 0.8;

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
	updateDamageText();

	drawTowers();
	window.draw(shopBG);

	window.draw(userInterface);
	window.draw(enemyController);
	window.draw(player);

	for (int i = 0; i < damageTexts.size(); i++)
	{
		window.draw(damageTexts.at(i));
	}

	window.display();
}

void Game::updateTowers()
{
	for (int i = 0; i < activeTowers.size(); i++)
	{
		//Tower* temp = activeTowers.at(i);
		activeTowers.at(i)->updateCanShoot();

		activeTowers.at(i)->update();

		checkCollisions(i);

	}

	if (placing == true)
	{
		
		Tower* placingTower = activeTowers.at(activeTowers.size()-1);

		placingTower->setPlaceable(true);
		selectTower(placingTower);

		for (int i = 0; i < activeTowers.size()-1; i++)
		{
			sf::Vector2f delta = activeTowers.at(i)->getPosition() - placingTower->getPosition();

			float distance = sqrtf(pow(delta.x,2) + pow(delta.y,2));

			if (distance <= placingTower->getPlacementRadius())
			{
				placingTower->setPlaceable(false);
			}

		}

		placingTower->setPosition((sf::Vector2f)mouse.getPosition(window));
	}

}

void Game::updateDamageText()
{
	for (int i = 0; i < damageTexts.size(); i++)
	{
		sf::Color c = damageTexts.at(i).getColor();
		sf::Vector2f p = damageTexts.at(i).getPosition();

		damageTexts.at(i).setColor(sf::Color(c.r,c.g,c.b,c.a -5));
		damageTexts.at(i).setPosition(p.x, p.y -1);

		if (damageTexts.at(i).getColor().a <= 0)
		{
			damageTexts.erase(damageTexts.begin() + i);
			i--;
		}
	}
}

void Game::handleClicks()
{
	std::vector<Button>* buttons = userInterface.getButtons();

	if (userInterface.clicked())
	{

		for (int i = 0; i < activeTowers.size(); i++)
		{
			activeTowers.at(i)->deselect();
		}

		for (int i = 0; i < buttons->size(); i++)
		{
			if (placing == false && userInterface.clicked(&buttons->at(i)))
			{
				
				switch(i) 
				{
				case 0: newBasicTower(); break;
				case 1: newRavagerTower(); break;
				case 2: newSynTower(); break;
				case 3: newSabTower(); break;
				case 4: newSenTower(); break;
				case 5: newSuperTower(); break;
				case 6: enemyController.startWave(); break;
				}

				return;
			}
		}

		for (int i = 0; i < activeTowers.size(); i++)
		{

			if (placing == false && userInterface.clicked(activeTowers.at(i)))
			{
				selectTower(activeTowers.at(i));
				return;
			}
		}

	}

	if (placing == true && userInterface.rightClicked())
		{
			placeTower();
			return;
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

void Game::checkCollisions(int i)
{
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

					float damage = tempBullet.getDamage();

					if (tempEnemy.isArmoured() && !tempBullet.isMagic()) damage*=(1-armourPercent);

					newDamageText(tempEnemy.getPosition(), damage);

					if (enemies->at(j).isDead(damage)) //deal damage and check if fatal
					{
						player.gainMoney(enemies->at(j).getLoot());
						enemies->erase(enemies->begin()+j);
					}
					j = enemies->size();
					
				}
			}

		}
}

void Game::newBasicTower()
{
	BasicTower newTower(&assets);

	if (player.getMoney() - newTower.getCost() >= 0)
	{
		player.spendMoney(newTower.getCost());
		placing = true;
	}

	else return;
	

	activeTowers.push_back(new BasicTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
	selectTower(placingTower);

	//the use of individual vectors may be avoided by using 'new' to pass pointer (not &)
	//cleaning would have to be handled seperately however
}

void Game::newRavagerTower()
{
	RavagerTower newTower(&assets);

	if (player.getMoney() - newTower.getCost() >= 0)
	{
		player.spendMoney(newTower.getCost());
		placing = true;
	}

	else return;

	activeTowers.push_back(new RavagerTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::newSynTower()
{
	SynTower newTower(&assets);

	if (player.getMoney() - newTower.getCost() >= 0)
	{
		player.spendMoney(newTower.getCost());
		placing = true;
	}

	else return;

	activeTowers.push_back(new SynTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::newSabTower()
{
	SabTower newTower(&assets);

	if (player.getMoney() - newTower.getCost() >= 0)
	{
		player.spendMoney(newTower.getCost());
		placing = true;
	}

	else return;

	activeTowers.push_back(new SabTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::newSenTower()
{
	SenTower newTower(&assets);

	if (player.getMoney() - newTower.getCost() >= 0)
	{
		player.spendMoney(newTower.getCost());
		placing = true;
	}

	else return;

	activeTowers.push_back(new SenTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::newSuperTower()
{
	SuperTower newTower(&assets);

	if (player.getMoney() - newTower.getCost() >= 0)
	{
		player.spendMoney(newTower.getCost());
		placing = true;
	}

	else return;

	activeTowers.push_back(new SuperTower(&assets));
	placingTower = activeTowers.at(activeTowers.size() -1);
}

void Game::placeTower()
{

	if (activeTowers.at(activeTowers.size()-1)->isPlaceable())
	{
		placing = false;
		activeTowers.at(activeTowers.size()-1)->place();
	}

}

void Game::newDamageText(sf::Vector2f pos, int dmg)
{
	sf::Text newText;
	newText.setCharacterSize(15);
	newText.setFont(assets.aller);
	newText.setString(std::to_string(dmg));
	newText.setOrigin(newText.getLocalBounds().width/2, newText.getLocalBounds().height/2);
	newText.setPosition(pos);

	damageTexts.push_back(newText);
}

void Game::selectTower(Tower* tower)
{
	for (int i = 0; i < activeTowers.size(); i++)
	{
		activeTowers.at(i)->deselect();
	}

	tower->select();
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
	for (int i = 0; i < activeTowers.size(); i++)
	{
		window.draw(*activeTowers.at(i));
	}
}