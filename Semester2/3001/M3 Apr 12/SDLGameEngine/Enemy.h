#pragma once
#include "Behaviour.h"

class Enemy : public Behaviour{
public:
	Enemy();
	~Enemy();

	void Update();
};
