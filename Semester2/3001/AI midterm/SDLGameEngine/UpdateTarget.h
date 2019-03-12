#pragma once
#include "Behaviour.h"
#include "KinematicSeek.h"
class UpdateTarget :
	public Behaviour
{
public:
	UpdateTarget();
	UpdateTarget(GameObject* go);
	~UpdateTarget();

	void Update();

	KinematicSeek* steer;
	GameObject* targetObject;
};

