#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <fstream>

#include "Block.h"
#include "Player.h"

const sf::Vector2u MAP_SIZE{ 30, 14 };
const sf::Vector2u WINDOW_SIZE{ 1000, 700 };

std::vector<Block> LoadMap(sf::Texture &texture)
{
	std::vector<Block> blocks;
	std::ifstream map("map.txt");
	uint8_t input = 0;
	for (int i = 0, j = 0; map >> input; i++)
	{
		if (i == MAP_SIZE.x) {
			i = 0;
			j++;
		}
		if (input == '1') {
			blocks.push_back(Block(texture, sf::Vector2f(i * 50, j * 50)));
		}
	}
	map.close();
	return blocks;
}

float GetDistance(sf::Vector2f a, sf::Vector2f b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}


float Module(float a, float b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

bool IsBlockUnder(Player &player, Block &block)
{
	if ((Module(player.getPosition().x, block.getPosition().x) < 50)
		&& (Module(player.getPosition().y + 50, block.getPosition().y) < 5)) {
		return true;
	}
	else {
		return false;
	}
}

bool CollisionTest(Player &player, Block &block)
{
	//TODO
	return true;
}

int main()
{
	sf::Texture texture;
	if (!texture.loadFromFile("block_dirt.png"))
	{
		std::cerr << "Loading texture block_dirt.png falied";
	}
	sf::Texture texturePlayer;
	if (!texturePlayer.loadFromFile("texturePlayer.png"))
	{
		std::cerr << "Loading texture texturePlayer.png falied";
	}

	std::vector<Block> blocks = LoadMap(texture);
	Player player(texturePlayer, sf::Vector2f(100, 100));

	sf::RenderWindow window{ sf::VideoMode{WINDOW_SIZE.x,WINDOW_SIZE.y},"My Mario", sf::Style::None };
	window.setPosition(sf::Vector2i(0, 0));
	window.setFramerateLimit(60);
	sf::Event event;

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		window.pollEvent(event);

		player.Update();

		player.SetStanding(false);
		for (auto &b : blocks) {
			//CollisionTest(player, block);
			if (IsBlockUnder(player, b) == true) {
				player.SetStanding(true);
				player.setPosition(sf::Vector2f(player.getPosition().x, b.getPosition().y - 50));
				break;
			}
		}
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			window.close();
		}

		for (Block& b : blocks) {
			window.draw(b);
		}
		window.draw(player);

		window.display();
	}
	return 0;
}