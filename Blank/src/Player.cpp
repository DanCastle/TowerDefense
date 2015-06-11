#include "Player.h"

Player::Player()
{
	money = 100;
	lives = 20;
}

Player::Player(FileLoader* assets)
{
	money = 100;
	lives = 20;

	livesText.setFont(assets->aller);
	livesText.setPosition(30, 640);
	livesText.setCharacterSize(20); //Magic Number?
	livesText.setString("Lives: " + std::to_string(lives));

	moneyText.setFont(assets->aller);
	moneyText.setPosition(30, 580);
	moneyText.setCharacterSize(20); //Magic Number?
	moneyText.setString("Money: " + std::to_string(money));
}

void Player::spendMoney(int spent)
{
	money -= spent;
	moneyText.setString("Money: " + std::to_string(money));
}

void Player::gainMoney(int loot)
{
	money += loot;
	moneyText.setString("Money: " + std::to_string(money));
}

void Player::takeDamage(int dmg)
{
	lives -= dmg;
	livesText.setString("Lives: " + std::to_string(lives));
}

int Player::getLives()
{
	return  lives;
}

int Player::getMoney()
{
	return money;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(livesText);
	target.draw(moneyText);
}