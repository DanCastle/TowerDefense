#include "EnemyController.h"

EnemyController::EnemyController()
{

}

EnemyController::EnemyController(FileLoader* assets, Player* player)
{
	this->assets = assets;

	this->player = player;

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
		waves.push_back(Wave(5*(i+1) , 5));
	}

	basic = waves.at(wave).getBasic();
	armoured = waves.at(wave).getBasic();
	waveSize = waves.at(wave).getWaveSize();


	wavesText.setFont(assets->aller);
	wavesText.setPosition(30, 610);
	wavesText.setCharacterSize(20);
	wavesText.setString("Waves: " + std::to_string(wave) + "/" + std::to_string(waves.size()));
}

void EnemyController::spawnEnemies()
{

	if (enemyTimer.getElapsedTime().asMilliseconds() > enemyDelay && waveSize > 0  && waveStarted == true )
	{
		if (basic > 0){
			Enemy newEnemy(&path, assets, false, false, false);
			enemies.push_back(newEnemy);
			basic--;
		}

		else if (armoured > 0){
			Enemy newEnemy(&path, assets, true, false, false);
			enemies.push_back(newEnemy);
			armoured--;
		}

		enemyTimer.restart();
		waveSize--;
	}

}

void EnemyController::updateEnemies()
{
	spawnEnemies();

	if (waveSize == 0 && wave < waves.size() - 1 ) { 
		wave++; 
		basic = waves.at(wave).getBasic();
		armoured = waves.at(wave).getArmoured();
		waveSize = waves.at(wave).getWaveSize(); 
		waveStarted = false; 
	}
	//click button to send wave

	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies.at(i).hasEscaped())
		{
			player->takeDamage(1);
			enemies.erase(enemies.begin() + i);

		}
	}

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

	target.draw(wavesText);
}

void EnemyController::startWave()
{
	waveStarted = true;
	enemyTimer.restart();
	wavesText.setString("Waves: " + std::to_string(wave+1) + "/" + std::to_string(waves.size()));
}

std::vector<Enemy>* EnemyController::getEnemies()
{
	return &enemies;
}