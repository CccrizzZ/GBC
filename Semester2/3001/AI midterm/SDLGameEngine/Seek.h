#pragma once
#include "SteeringBehaviour.h"
#include "Transform.h"

class Seek :
	public SteeringBehaviour
{
public:
	Seek();
	Seek(GameObject* go);
	~Seek();

	virtual void Update();

	Transform* target;
	float maxAccelaraction = 100;
};

