#pragma once
#include <SFML/Graphics.hpp>
#include "Physics.h"

class Player : public sf::Sprite, public Physics
{
public:
	Player(sf::Texture &texture, sf::Vector2f position);
	Player() = delete;
	~Player() = default;
	void Update();
private:
	float speed = 1;
};

