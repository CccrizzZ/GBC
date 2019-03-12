#include "Flee.h"



Flee::Flee()
{
}

Flee::Flee(GameObject* go) : SteeringBehaviour(go)
{
}


Flee::~Flee()
{
}

void Flee::Update()
{

	// Get direction from target
	steering.linear = gameObject->transform->GetAbsolutePosition() - target->GetAbsolutePosition();

	// Give full accelaration in this direction
	steering.linear.Normalize();
	steering.linear *= maxAccelaraction;

	// Output steering
	steering.angular = 0;
	SteeringBehaviour::Update();

}
