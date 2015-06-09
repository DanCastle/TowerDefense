#include <SFML/Graphics.hpp>
#include "Background.h"
#include "vector2D.h"
#include "Collisions.h"
#include "FileLoader.h"
#include "Tower.h"
#include "BasicTower.h"
#include "Game.h"
#include <iostream>

void main() /*! Entry point for the application */
{
	sf::Clock Clock;
	Game game;

	while (game.windowOpen())
    {

		if(Clock.getElapsedTime().asSeconds()>REFRESH_RATE)
		{
			Clock.restart();
			game.updateGame();	
		}

	
    }



}