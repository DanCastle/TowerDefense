#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "FileLoader.h"
#include <string.h>

class Button : public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Text hoverText;
	std::string text;
	int minX, maxX, minY, maxY;
	bool isHover;
public:
	Button(FileLoader* assets, int buttonNo, int x, int y);
	void setTexture(sf::Texture tex);
	sf::Texture getTexture();
	void hover();
	void deHover();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	int getMinX();
	int getMaxX();
	int getMinY();
	int getMaxY();
};

#endif BUTTON_H