#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <fstream>

#include "Block.h"

const sf::Vector2u MAP_SIZE{ 30, 14 };
const sf::Vector2u WINDOW_SIZE{ 1000, 700 };

std::vector<Block> LoadMap(sf::Texture &texture)
{
	std::vector<Block> blocks;
	std::ifstream map("map.txt");
	uint8_t input = 0;
	for (int i = 0, j = 0; map >> input; i++)
	{
		if (i == MAP_SIZE.x)		{
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

int main()
{

	sf::Texture texture;
	if (!texture.loadFromFile("block_dirt.png"))
	{
		std::cerr << "Loading texture block_dirt.png falied";
	}

	std::vector<Block> blocks = LoadMap(texture);

	sf::RenderWindow window{ sf::VideoMode{WINDOW_SIZE.x,WINDOW_SIZE.y},"My Mario" };
	window.setFramerateLimit(60);
	sf::Event event;

	while (true)
	{
		window.clear(sf::Color::White);
		window.pollEvent(event);

		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}

		for(Block b : blocks)
			window.draw(b);
		
		window.display();
	}
	return 0;
}