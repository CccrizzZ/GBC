#pragma once
#include <list>
#include "Behaviour.h"
#include "Vector2.h"
#include "SteeringBehaviour.h"
#include "Rigidbody.h"


class SteeringAgent :
	public Behaviour
{
public:
	SteeringAgent();
	SteeringAgent(GameObject* go);
	~SteeringAgent();

	void Start();
	void Update();

	float maxSpeed = 100;
	float maxRotation = 0.1f;
	std::list<SteeringBehaviour*> steerings;

	Vector2 velocity;
	float angularSpeed;

	Rigidbody* rb;
};

