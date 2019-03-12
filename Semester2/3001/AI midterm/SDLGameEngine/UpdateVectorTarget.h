#pragma once
#include "Behaviour.h"
#include "Vector2.h"
class UpdateVectorTarget :
	public Behaviour
{
public:
	UpdateVectorTarget();
	UpdateVectorTarget(GameObject* go);
	~UpdateVectorTarget();

	void Update();

	float maxTime = 1000;
	Vector2 target;
	GameObject* targetObject;

private:
	float timer = 0;
};

