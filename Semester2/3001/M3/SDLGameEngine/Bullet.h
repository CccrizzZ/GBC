#pragma once
#include "EventListener.h"
#include "Collider.h"
#include "Behaviour.h"

class Bullet : public Behaviour{

public:

	Bullet();
	~Bullet();


	float bSpeed = 1200;
	float destroyTime = 1.0f;
	Vector2 bDirection;



	void Update();
	void Awake();
	void Cleanup();
	std::shared_ptr<EventListener<Collider*>> triggerEventListener = NULL;
	void OnTriggerEnter(Collider* col);
private:
	float timer = 0;
};
