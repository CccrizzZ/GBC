#pragma once
#include "Behaviour.h"
#include "Vector2.h"
#include "KinematicSteeringBehaviour.h"
class KinematicAgent :
	public Behaviour
{
public:
	KinematicAgent();
	KinematicAgent(GameObject* go);
	~KinematicAgent();

	void Update();

	KinematicSteeringBehaviour* steering;
};

