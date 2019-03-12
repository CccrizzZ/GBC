#pragma once
#include "SteeringBehaviour.h"
class Pursue :
	public SteeringBehaviour
{
public:
	Pursue();
	Pursue(GameObject* go);
	~Pursue();

	virtual void Start();
	virtual void Update();

	Transform* target;
	float maxAccelaraction = 100;
	float maxPrediction = 10;

private:
	Vector2 lastTragetPosition;
};

