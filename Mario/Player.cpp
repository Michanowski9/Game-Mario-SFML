#include "Player.h"

Player::Player(sf::Texture &texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}
void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		Physics::velocity = { -speed, velocity.y };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		Physics::velocity = { speed, velocity.y };
	}
	else {
		Physics::velocity = { 0.0f, velocity.y };
	}
	Physics::Update();
}