#include "Button.h"

Button::Button(FileLoader* assets, int tower, int x, int y)
{
	sprite.setTexture(assets->towerTextures.at(tower));
	sprite.setPosition(x,y);

	minX = sprite.getGlobalBounds().left;
	maxX = sprite.getGlobalBounds().left + sprite.getGlobalBounds().width;

	minY = sprite.getGlobalBounds().top;
	maxY = sprite.getGlobalBounds().top + sprite.getGlobalBounds().height;


	isHover = false;

	text = assets->shopButtonHoverText.at(tower);

	hoverText.setColor(sf::Color::White);
	hoverText.setFont(assets->aller);
	hoverText.setString(text);
	hoverText.setCharacterSize(16);
	hoverText.setPosition(30,200);
}

void Button::setTexture(sf::Texture tex)
{
	sprite.setTexture(tex);
}

sf::Texture Button::getTexture()
{
	return *sprite.getTexture();
}

void Button::hover()
{
	isHover = true;
}

void Button::deHover()
{
	isHover = false;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite);
	if (isHover == true)
	{
		target.draw(hoverText);
	}
}

int Button::getMinX()
{
	return minX;
}

int Button::getMaxX()
{
	return maxX;
}

int Button::getMinY()
{
	return minY;
}

int Button::getMaxY()
{
	return maxY;
}