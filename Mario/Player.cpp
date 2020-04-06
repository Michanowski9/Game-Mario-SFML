#include "Player.h"

Player::Player(sf::Texture &texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}
void Player::Update()
{
	if (this->GetStanding() == false)
	{
		velocity = { velocity.x, velocity.y + speed/10 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		velocity = { -speed, velocity.y };
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		velocity = { speed, velocity.y };
	}
	else {
		velocity = { 0.0f, velocity.y };
	}
	this->setPosition(this->getPosition() + velocity);
}
void Player::SetStanding()
{

}
bool Player::GetStanding()
{
	return isStanding;
}