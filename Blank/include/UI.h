#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include "FileLoader.h"
#include "Button.h"

class UI : public sf::Drawable
{
private:
	std::vector<Button> shopButtons;
	sf::Mouse mouse;
	sf::RenderWindow* windowPointer;
	sf::Text towersTitle;
public:
	UI();
	UI(sf::RenderWindow* window, FileLoader* assets);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void newShopButton(int buttonNo, FileLoader* assets, int x, int y);
	void update();
	bool mouseOver(Button* button);
	bool clicked(Button* button);
	bool rightClicked();
	std::vector<Button>* getShopButtons();
};

#endif UI_H