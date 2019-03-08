#pragma once
#include "Behaviour.h"
#include "Bullet.h"
#include <vector>
using namespace std;

class PlayerControls :	public Behaviour {
public:
	PlayerControls();
	~PlayerControls();

	// Player speed
	float speed;

	// Bullet vector
	vector<Bullet*> vBullets;

	// Flag for firing
	bool canFire = true;

	// Update function
	void Update();
};
