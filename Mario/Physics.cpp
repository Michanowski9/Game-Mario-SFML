#include "Physics.h"
#include <SFML/Graphics.hpp>

void Physics::AddForce(sf::Vector2f vector)
{

}
void Physics::Update()
{
	if (isStanding == true) {
		velocity.y += gravityAcceleration * GRAVITY;
	}


	if (velocity.x < 1 && velocity.x > -1) {
		velocity.x = 0;
	}
	else if (velocity.x > 0){
		velocity.x -= floorResistance;
	}
	else if (velocity.x < 0){
		velocity.x += floorResistance;
	}
	

	parent.move(velocity);
}

