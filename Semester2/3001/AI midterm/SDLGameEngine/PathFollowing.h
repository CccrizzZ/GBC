#pragma once
#include "Arrive.h"
#include <list>
class PathFollowing :
	public Arrive
{
public:
	PathFollowing();
	PathFollowing(GameObject* go);
	~PathFollowing();

	virtual void Start();
	virtual void Update();

	std::list<Vector2> waypoints;
	float distanceThreshold = 30;

private:
	std::list<Vector2>::iterator currentWaypoint;
};
