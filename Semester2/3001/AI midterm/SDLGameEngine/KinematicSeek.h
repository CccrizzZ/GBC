#pragma once
#include "KinematicSteeringBehaviour.h"
class KinematicSeek :
	public KinematicSteeringBehaviour
{
public:
	KinematicSeek();
	KinematicSeek(GameObject* go);
	~KinematicSeek();

	void Update();
	//GameObject* targetObject;
	Vector2 target;
	float maxSpeed = 50;
	float slowDistance = 50;
};

