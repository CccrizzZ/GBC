#pragma once
#include "SteeringBehaviour.h"
#include "Transform.h"
class Flee :
	public SteeringBehaviour
{
public:
	Flee();
	Flee(GameObject* go);
	~Flee();

	virtual void Update();

	Transform* target;
	float maxAccelaraction = 100;
};

