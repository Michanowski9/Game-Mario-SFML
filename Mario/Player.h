#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Sprite
{
public:
	Player(sf::Texture &texture, sf::Vector2f position);
	Player() = delete;
	~Player() = default;
	void Update();
	bool GetStanding();
	void SetStanding();
private:
	bool isStanding = false;
	sf::Vector2f velocity{ 0.0f, 0.0f };
	float speed = 1;
};

