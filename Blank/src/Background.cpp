/**
@file Background.cpp
*/

#include "Background.h"

Background::Background()//!< Default constructor, loads background texture from file and applies texture to the sprite
{
	backgroundTexture.loadFromFile(".\\assets\\graphics\\testBg.bmp");
	backgroundSprite.setTexture(backgroundTexture);
}


void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const //!< draws the background to the screen
{
	target.draw(backgroundSprite);
}