#include "Align.h"
#include "SteeringAgent.h"


Align::Align()
{
}

Align::Align(GameObject* go) : SteeringBehaviour(go)
{
}

Align::~Align()
{
}

float MapToRange(float angle)
{
	float direction = angle > 0 ? 1 : -1;
	return direction * (abs(angle) - floorf(abs(angle) / M_PI));
}

void Align::Update()
{
	// Get the naive direction to the target
	float rotation = orientation - gameObject->transform->GetAbsoluteAngle() * M_PI / 180.0f;

	// Map the result to (-pi, pi)
	rotation = MapToRange(rotation);
	float rotationSize = abs(rotation);

	// Check if we are there, return no steering 
	if (rotationSize < targetRadius)
	{
		//steering.angular = 0;
		//agent->angularSpeed = 0;
		return;
	}

	float targetRotation;
	// If we are outside slowRadius, then use maximum rotation
	if (rotationSize > slowRadius)
	{
		targetRotation = agent->maxRotation;
	}

	// Otherwise calculate scaled rotation
	else
	{
		targetRotation = agent->maxRotation * rotationSize / targetRadius;
	}

	// The final target rotation combines speed(already in the variable) and direction 
	targetRotation *= rotation / rotationSize;
	// Acceleration tries to get to the target rotation
	steering.angular = targetRotation - gameObject->transform->GetAbsoluteAngle() * M_PI / 180.0f; 
	steering.angular /= timeToTarget;
    // Check if the acceleration is too great 5
	float angularAcceleration = abs(steering.angular);
		if (angularAcceleration > maxAngularAccelaration)
		{
			steering.angular /= angularAcceleration;
			steering.angular *= maxAngularAccelaration;
		}
	// Output the steering 
	steering.linear = 0;

}
