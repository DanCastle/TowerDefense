#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>
#include "FileLoader.h"
#include "Button.h"

class UI : public sf::Drawable
{
private:
	std::vector<Button> buttons;
	sf::Mouse mouse;
	sf::RenderWindow* windowPointer;
	sf::Text towersTitle;
	sf::Text nextWave;
public:
	UI();
	UI(sf::RenderWindow* window, FileLoader* assets);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void newButton(int buttonNo, FileLoader* assets, int x, int y);
	void update();
	bool mouseOver(Button* button);
	bool clicked(Button* button);
	bool rightClicked();
	void textOnButton(sf::Text* text, Button button);
	std::vector<Button>* getButtons();
};

#endif UI_H