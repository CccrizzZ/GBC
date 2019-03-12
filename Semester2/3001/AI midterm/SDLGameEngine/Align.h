#pragma once
#include "SteeringBehaviour.h"

class Align :
	public SteeringBehaviour
{
public:
	Align();
	Align(GameObject* go);
	~Align();

	void Update();


	float orientation;

	float maxAngularAccelaration = 0.1f;
	float targetRadius = 0.5f;
	float slowRadius = 1.0f;
	float timeToTarget = 0.1f;
};

