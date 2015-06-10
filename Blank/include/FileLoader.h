#ifndef FILELOADER_H
#define FILELOADER_H

#include <SFML/Graphics.hpp>

class FileLoader
{
public:
	FileLoader();
	std::vector<sf::Texture> buttonTextures;
	std::vector<std::string> shopButtonHoverText;
	std::vector<sf::Texture> enemySprites;
	sf::Font aller;
};

#endif FILELOADER_H
