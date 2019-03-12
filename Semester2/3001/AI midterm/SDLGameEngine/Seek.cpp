#include "Seek.h"



Seek::Seek()
{
}

Seek::Seek(GameObject* go): SteeringBehaviour(go)
{
}

Seek::~Seek()
{
}

void Seek::Update()
{
	// Get direction to target
	steering.linear = target->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition();

	// Give full accelaration in this direction
	steering.linear.Normalize();
	steering.linear *= maxAccelaraction;

	// Output steering
	steering.angular = 0;
	SteeringBehaviour::Update();

}
