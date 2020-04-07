#pragma once
#include <SFML/Graphics.hpp>
#include "Physics.h"

class Player : public sf::Sprite
{
public:
	Player(sf::Texture &texture, sf::Vector2f position);
	Player() = delete;
	~Player() = default;
	void Update();
	void SetStanding(bool value);
private:
	float speed = 1;
	bool isStanding = true;
	sf::Vector2f velocity{ 0.0f, 0.0f };
};

