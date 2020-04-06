#pragma once
#include <SFML/Graphics.hpp>

class Block : public sf::Sprite
{
public:
	Block(sf::Texture &texture, sf::Vector2f position);
	Block() = delete;
	~Block() = default;
};

