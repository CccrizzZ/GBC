#pragma once
#include "Behaviour.h"
#include "Vector2.h"
class KinematicSteeringBehaviour :
	public Behaviour
{
public:
	KinematicSteeringBehaviour();
	KinematicSteeringBehaviour(GameObject* go);
	~KinematicSteeringBehaviour();

	virtual void Start();
	virtual void Update();

	Vector2 velocity;
	float maxSpeed;
};

