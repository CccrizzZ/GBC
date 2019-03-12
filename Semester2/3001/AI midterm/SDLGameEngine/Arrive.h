#pragma once
#include "SteeringBehaviour.h"
class Arrive :
	public SteeringBehaviour
{
public:
	Arrive();
	Arrive(GameObject* go);
	~Arrive();

	virtual void Update();

	Transform* target;
	float maxAccelaraction = 100;
	float slowRadius = 300;
	float targetRadius = 5;
	float timeToTarget = 1.0f;
};

