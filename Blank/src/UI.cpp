#include "UI.h"

UI::UI()
{
	
}

UI::UI(sf::RenderWindow* window, FileLoader* assets)
{
	windowPointer = window;

	//Do a for loop to create buttons, hold textures in an array within assets
	newShopButton(0, assets, 30, 100);
	newShopButton(1, assets, 75, 100);
	newShopButton(2, assets, 120, 100);
	newShopButton(3, assets, 30, 145);
	newShopButton(4, assets, 75, 145);
	newShopButton(5, assets, 120, 145);

	towersTitle.setFont(assets->aller);
	towersTitle.setPosition(30,50);
	towersTitle.setString("Towers");
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < shopButtons.size(); i++)
	{
		target.draw(shopButtons.at(i));
	}
	target.draw(towersTitle);
}
void UI::newShopButton(int buttonNo, FileLoader* assets, int x, int y)
{
	Button newButton(assets, buttonNo, x, y);
	shopButtons.push_back(newButton);
}

void UI::update()
{
	for (int i = 0; i < shopButtons.size(); i++)
	{
		if (mouseOver(&shopButtons.at(i)))
		{
			shopButtons.at(i).hover();
		}

		if (!mouseOver(&shopButtons.at(i)))
		{
			shopButtons.at(i).deHover();
		}
	}
}

bool UI::mouseOver(Button* button)
{

	int mouseX = mouse.getPosition(*windowPointer).x;
	int mouseY = mouse.getPosition(*windowPointer).y;

	if (mouseX < button->getMinX() || mouseX > button->getMaxX() ) return false;
	if (mouseY < button->getMinY() || mouseY > button->getMaxY() ) return false;

	return true;
}

bool UI::clicked(Button* button)
{
	if (mouseOver(button) && mouse.isButtonPressed(sf::Mouse::Left)) return true;
	else return false;
}

bool UI::rightClicked()
{
	if (mouse.isButtonPressed(sf::Mouse::Right)) return true;
	else return false;
}

std::vector<Button>* UI::getShopButtons()
{
	return &shopButtons;
}