#include "Block.h"

Block::Block(sf::Texture &texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}