#include "Player.h"

Player::Player(sf::Texture &texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}
void Player::Update()
{
	if (isStanding == false) {
		velocity.y += speed/10;
	}
	else {
		velocity.y = 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		velocity.x = -speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		velocity.x = speed;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) == false) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) == false)) {
		velocity.x = 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && isStanding == true) {
		velocity.y = -6;
	}

	this->move(velocity);
}

void Player::SetStanding(bool value)
{
	isStanding = value;
}