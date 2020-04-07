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
	void ClearVelocity(int direction);

	void SetStanding(bool value);
	void SetIsMoveLeftFree(bool value);
	void SetIsMoveRightFree(bool value);
	void SetIsAfterCollisionTop(bool value);

	bool GetIsAfterCollisionTop();
private:
	float speed = 2;
	bool isStanding = true;
	bool isMoveLeftFree = true;
	bool isMoveRightFree = true;
	bool isAfterCollisionTop = false;
	sf::Vector2f velocity{ 0.0f, 0.0f };
};

