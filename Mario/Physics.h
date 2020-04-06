#pragma once
#include <SFML/Graphics.hpp>

class Physics
{
public:
	Physics() = delete;
	~Physics() = default;
	void Update();
	void AddForce(sf::Vector2f vector);
protected:
	const float GRAVITY = 9.8f;
	float gravityAcceleration = 0.1f;
	float floorResistance = 0.1f;
	sf::Vector2f velocity{ 0.0f, 0.0f };
	bool isStanding = true;
	sf::Sprite parent;
};

