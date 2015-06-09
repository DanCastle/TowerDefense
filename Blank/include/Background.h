/**
@file Background.h
*/

#ifndef BACKGROUND_H
#define BACKGROUND_H

/*! \class Background
    \brief The background layer of the game, which doesn't move, or interact with any game objects
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Background : public sf::Drawable
{
private:
	sf::Sprite backgroundSprite; //!<  Sprite of background
	sf::Texture backgroundTexture; //!< Texture of background
	
	
	
public:
	Background(); //!< Default Constructor
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw function
		
};


#endif
