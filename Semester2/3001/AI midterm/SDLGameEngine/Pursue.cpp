#include "Pursue.h"
#include "SteeringAgent.h"
#include "Time.h"


Pursue::Pursue()
{
}

Pursue::Pursue(GameObject* go) : SteeringBehaviour(go)
{
}

Pursue::~Pursue()
{
}

void Pursue::Start()
{
	lastTragetPosition = target->GetAbsolutePosition();
}

void Pursue::Update()
{

	Vector2 direction = target->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition();
	float distance = direction.Length();

	float speed = agent->velocity.Length();

	float prediction;
	if (speed < distance / maxPrediction)
	{
		prediction = maxPrediction;
	}
	else
	{
		prediction = distance / speed;
	}

	Vector2 targetVel = (target->GetAbsolutePosition() - lastTragetPosition) * Time::DeltaTime();
	// Get direction to target
	steering.linear = target->GetAbsolutePosition() + targetVel * prediction - gameObject->transform->GetAbsolutePosition();

	// Give full accelaration in this direction
	steering.linear.Normalize();
	steering.linear *= maxAccelaraction;

	// Output steering
	steering.angular = 0;
	lastTragetPosition = target->GetAbsolutePosition();
	SteeringBehaviour::Update();

}