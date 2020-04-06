#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Block.h"

int main()
{
	sf::Texture texture;
	if (!texture.loadFromFile("block_dirt.png"))
	{
		std::cerr << "Loading texture block_dirt.png falied";
	}

	Block block{ texture, sf::Vector2f(200,200) };

	sf::RenderWindow window{ sf::VideoMode{800,600},"My Mario" };
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
		window.draw(block);
		window.display();
	}
	return 0;
}