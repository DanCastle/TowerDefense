/**
@file FileLoader.cpp
*/

#include "FileLoader.h"

FileLoader::FileLoader()
{
	sf::Texture tex;

	tex.loadFromFile(".\\assets\\graphics\\comTower.png");
	buttonTextures.push_back(tex);
	
	tex.loadFromFile(".\\assets\\graphics\\ravTower.png");
	buttonTextures.push_back(tex);

	tex.loadFromFile(".\\assets\\graphics\\synTower.png");
	buttonTextures.push_back(tex);

	tex.loadFromFile(".\\assets\\graphics\\sabTower.png");
	buttonTextures.push_back(tex);

	tex.loadFromFile(".\\assets\\graphics\\senTower.png");
	buttonTextures.push_back(tex);

	tex.loadFromFile(".\\assets\\graphics\\superTower.png");
	buttonTextures.push_back(tex);

	tex.loadFromFile(".\\assets\\graphics\\buttonBG.png");  //buttonBack
	buttonTextures.push_back(tex);

	std::string hoverText;

	hoverText = "Commando Tower\nPhysical Damage\n50 Credits";
	shopButtonHoverText.push_back(hoverText);

	hoverText = "Ravager Tower\nMagic Damage\n100 Credits";
	shopButtonHoverText.push_back(hoverText);

	hoverText = "Synergist Tower\nBuffs Towers\n200 Credits";
	shopButtonHoverText.push_back(hoverText);

	hoverText = "Saboteur Tower\nDebuffs enemies\n200 Credits";
	shopButtonHoverText.push_back(hoverText);

	hoverText = "Sentinel Tower\nTaunts Enemies\n200 Credits";
	shopButtonHoverText.push_back(hoverText);

	hoverText = "Super Tower\n???\n1000 Credits";
	shopButtonHoverText.push_back(hoverText);

	hoverText = "";
	shopButtonHoverText.push_back(hoverText);

	sf::Texture enemySprite;

	enemySprite.loadFromFile(".\\assets\\graphics\\KCC_Gordo_sprite.png");
	enemySprites.push_back(enemySprite);

	aller.loadFromFile(".\\assets\\graphics\\Aller_Rg.ttf");

}