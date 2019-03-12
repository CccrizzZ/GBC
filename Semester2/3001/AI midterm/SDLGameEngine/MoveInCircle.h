#pragma once
#include "Behaviour.h"
class MoveInCircle :
	public Behaviour
{
public:
	MoveInCircle();
	MoveInCircle(GameObject* go);
	~MoveInCircle();

	void Update();

	float radius = 500;
	float angularSpeed = 1.0f;

private:
	float angle = 0;
};

