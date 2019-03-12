#include "Arrive.h"
#include "SteeringAgent.h"
#include "Game.h"


Arrive::Arrive()
{
}

Arrive::Arrive(GameObject* go): SteeringBehaviour(go)
{
}

Arrive::~Arrive()
{
}

void Arrive::Update()
{
	SDL_SetRenderDrawColor(game->gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawLine(game->gRenderer, target->GetAbsolutePosition().x - Camera::x, target->GetAbsolutePosition().y - Camera::y, gameObject->transform->GetAbsolutePosition().x - Camera::x, gameObject->transform->GetAbsolutePosition().y - Camera::y);
	// Get direction to target
	Vector2 direction = target->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition();
	float distance = direction.Length();

	// Check if we are there
	if (distance < targetRadius)
	{
		return;
	}

	float targetSpeed = 0;
	// If we are outside the slowRadius, go to maxSpeed
	if (distance > slowRadius)
	{
		targetSpeed = agent->maxSpeed;
	}
    // Otherwise calculate scaled speed
	else
	{
		targetSpeed = agent->maxSpeed * distance / slowRadius;
	}

	// The target velocity combines speed and direction
	Vector2 targetVelocity = direction;
	targetVelocity.Normalize();
	targetVelocity *= targetSpeed;

	// Accelaration tries to get to this target velocity
	steering.linear = targetVelocity - agent->rb->GetVelocity();
	steering.linear /= timeToTarget;

	// Check if accelaration is too fast
	if (steering.linear.Length() > maxAccelaraction)
	{
		steering.linear.Normalize();
		steering.linear *= maxAccelaraction;
	}

	// Output steering
	steering.angular = 0;
	SteeringBehaviour::Update();

}
