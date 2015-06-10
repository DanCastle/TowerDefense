#include "EnemyController.h"

EnemyController::EnemyController()
{

}

EnemyController::EnemyController(FileLoader* assets)
{
	this->assets = assets;

	//waveSize = 20;
	wave = 0;
	enemyDelay = 1000;

	waveStarted = false;

	path.push_back(sf::Vector2f(950,10));
	path.push_back(sf::Vector2f(950,140));
	path.push_back(sf::Vector2f(250,140));
	path.push_back(sf::Vector2f(250,250));
	path.push_back(sf::Vector2f(950,250));
	path.push_back(sf::Vector2f(950,450));
	path.push_back(sf::Vector2f(800,450));
	path.push_back(sf::Vector2f(800,650));
	path.push_back(sf::Vector2f(650,650));
	path.push_back(sf::Vector2f(650,450));
	path.push_back(sf::Vector2f(250,450));
	path.push_back(sf::Vector2f(250,758));

	for (int i = 0; i < 10; i++)
	{
		waves.push_back(Wave(5*(i+1)));
	}

	waveSize = waves.at(wave).getWaveSize();
}

void EnemyController::updateEnemies()
{
	if (enemyTimer.getElapsedTime().asMilliseconds() > enemyDelay && waveSize > 0  && waveStarted == true )
	{
		Enemy newEnemy(&path, assets);
		enemies.push_back(newEnemy);
		enemyTimer.restart();
		waveSize--;
	}

	if (waveSize == 0) { wave++; waveSize = waves.at(wave).getWaveSize(); waveStarted = false; }
	//click button to send wave

	for (int i = 0; i < enemies.size(); i++)
	{
		enemies.at(i).update();
	}
}

void EnemyController::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 1; i < path.size(); i++)
	{
		sf::Vertex line[] =
		{
		    path.at(i-1),
		    path.at(i)
		};
		
		target.draw(line, 2, sf::Lines);
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		target.draw(enemies.at(i));
	}
}

void EnemyController::startWave()
{
	waveStarted = true;
	enemyTimer.restart();
}

std::vector<Enemy>* EnemyController::getEnemies()
{
	return &enemies;
}