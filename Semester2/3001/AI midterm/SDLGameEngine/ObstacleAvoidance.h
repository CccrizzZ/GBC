#pragma once
#include "Seek.h"
class ObstacleAvoidance :
	public Seek
{
public:
	ObstacleAvoidance();
	~ObstacleAvoidance();

	void Start();
	void Update();

	float lookAhead = 500;
	float avoidDistance = 500;
	uint16_t avoidLayer = 0xFFFF;
};

