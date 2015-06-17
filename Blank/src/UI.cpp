#include "UI.h"

UI::UI()
{
	
}

UI::UI(sf::RenderWindow* window, FileLoader* assets)
{
	windowPointer = window;

	//Do a for loop to create buttons, hold textures in an array within assets
	newButton(0, assets, 30, 100);
	newButton(1, assets, 75, 100);
	newButton(2, assets, 120, 100);
	newButton(3, assets, 30, 145);
	newButton(4, assets, 75, 145);
	newButton(5, assets, 120, 145);
	newButton(6, assets, 30, 675);

	towersTitle.setFont(assets->aller);
	towersTitle.setPosition(30,50);
	towersTitle.setString("Towers");

	nextWave.setFont(assets->aller);
	nextWave.setString("Send Wave");
	textOnButton(&nextWave, buttons.at(6));
}

void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < buttons.size(); i++)
	{
		target.draw(buttons.at(i));
	}
	target.draw(towersTitle);
	target.draw(nextWave);
}
void UI::newButton(int buttonNo, FileLoader* assets, int x, int y)
{
	Button newButton(assets, buttonNo, x, y);
	buttons.push_back(newButton);
}

void UI::update()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (mouseOver(buttons.at(i).getSprite()))
		{
			buttons.at(i).hover();
		}

		if (!mouseOver(buttons.at(i).getSprite()))
		{
			buttons.at(i).deHover();
		}
	}
}

bool UI::mouseOver(sf::Sprite sprite)
{

	int mouseX = mouse.getPosition(*windowPointer).x;
	int mouseY = mouse.getPosition(*windowPointer).y;

	sf::FloatRect rect = sprite.getGlobalBounds();

	if (mouseX < rect.left || mouseX > rect.left + rect.width) return false;
	if (mouseY < rect.top || mouseY > rect.top + rect.height ) return false;

	return true;
}

bool UI::clicked()
{
	if (mouse.isButtonPressed(sf::Mouse::Left)) return true;
	else return false;
}

bool UI::clicked(Button* button)
{
	if (mouseOver(button->getSprite()) && mouse.isButtonPressed(sf::Mouse::Left)) return true;
	else return false;
}

bool UI::clicked(Tower* tower)
{
	if (mouseOver(tower->getSprite()) && mouse.isButtonPressed(sf::Mouse::Left)) return true;
	else return false;
}

bool UI::rightClicked()
{
	if (mouse.isButtonPressed(sf::Mouse::Right)) return true;
	else return false;
}

std::vector<Button>* UI::getButtons()
{
	return &buttons;
}

void UI::textOnButton(sf::Text* text, Button button)
{
	text->setCharacterSize((float)(button.getMaxY() - button.getMinY()) * 0.5);

	sf::Vector2f origin(text->getLocalBounds().width/2,text->getLocalBounds().height/2);
	text->setOrigin(origin);

	sf::Vector2f buttonCenter((button.getMaxX() - button.getMinX())/2 + button.getMinX(), (button.getMaxY() - button.getMinY())/2 + button.getMinY());
	text->setPosition(buttonCenter);
}