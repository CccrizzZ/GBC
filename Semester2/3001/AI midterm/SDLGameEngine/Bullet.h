#pragma once
#include "Behaviour.h"
#include "EventListener.h"
#include "Collider.h"
class Bullet :
	public Behaviour
{
public:
	Bullet();
	~Bullet();

	float speed = 1000;
	float destroyTime = 1;
	void Awake();
	void Update();
	void Cleanup();
	std::shared_ptr<EventListener<Collider*>> triggerEventListener = NULL;
	void OnTriggerEnter(Collider* col);
private:
	float timer = 0;
};

