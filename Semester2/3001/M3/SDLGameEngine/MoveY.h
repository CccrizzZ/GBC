#pragma once
#include "SteeringBehaviour.h"

class MoveY :	public SteeringBehaviour{
public:
	MoveY();
	~MoveY();
	MoveY(GameObject* go);

	void Update();
  Vector2 direction;
	float distance = 200.0f;
	float speed = 50.0f;

private:
	float angle = 0;
	int counter;
	bool turn;
};
