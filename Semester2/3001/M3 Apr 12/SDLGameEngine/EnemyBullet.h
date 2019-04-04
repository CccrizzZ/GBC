#pragma once
#include "EventListener.h"
#include "Collider.h"
#include "Behaviour.h"

class EnemyBullet : public Behaviour {
public:
	EnemyBullet();
	~EnemyBullet();

	float ebSpeed = 1000;
	float destroyTime = 1.0f;
	Vector2 bDirection;


	void Update();
	void Awake();
	void Cleanup();
	void OnTriggerEnter(Collider* col);
	std::shared_ptr<EventListener<Collider*>> triggerEventListener = NULL;
private:
	float timer = 0;
};
