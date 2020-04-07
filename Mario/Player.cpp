#include "Player.h"

Player::Player(sf::Texture &texture, sf::Vector2f position)
{
	this->setTexture(texture);
	this->setPosition(position);
}

void Player::Update()
{
	bool leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	bool rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
	bool spaceKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

	//gravity
	if (isStanding == false) {
		velocity.y += speed / 15;
	}
	else {
		velocity.y = 0.0f;
	}


	if (leftKeyPressed == true) {
		velocity.x = -speed;
	}
	if (rightKeyPressed == true) {
		velocity.x = speed;
	}
	if (leftKeyPressed == false && rightKeyPressed == false) {
		velocity.x = 0.0f;
	}

	if (spaceKeyPressed == true && isStanding == true) {
		velocity.y = -6;
	}

	this->move(velocity);
}

/// direction = 0 -> clear velocity.x
/// direction = 1 -> clear velocity.y
void Player::ClearVelocity(int direction)
{
	if(direction == 0){
		velocity.x = 0.0f;
	}
	else if(direction == 1) {
		velocity.y = 0.0f;
	}
}

void Player::SetStanding(bool value)
{
	isStanding = value;
}

void Player::SetIsMoveLeftFree(bool value)
{
	isMoveLeftFree = value;
}

void Player::SetIsMoveRightFree(bool value)
{
	isMoveRightFree = value;
}
void Player::SetIsAfterCollisionTop(bool value)
{
	isAfterCollisionTop = value;
}

bool Player::GetIsAfterCollisionTop()
{
	return isAfterCollisionTop;
}