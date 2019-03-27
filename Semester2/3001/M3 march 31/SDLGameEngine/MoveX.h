#pragma once
#include "SteeringBehaviour.h"

class MoveX :	public SteeringBehaviour{
public:
	MoveX();
	~MoveX();
	MoveX(GameObject* go);

	void Update();
  Vector2 direction;
	float distance = 200.0f;
	float speed = 50.0f;

private:
	float angle = 0;
	int counter;
	bool turn;
};
