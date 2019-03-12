#include "Bullet.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "Game.h"

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
void Bullet::Awake()
{
	Behaviour::Awake();
	triggerEventListener = std::make_shared<EventListener<Collider*>>(std::bind(&Bullet::OnTriggerEnter, this, std::placeholders::_1));
	gameObject->OnTriggerEnter.AddListener(triggerEventListener);
}

void Bullet::Cleanup()
{
	Behaviour::Cleanup();
	gameObject->OnTriggerEnter.RemoveListener(triggerEventListener);
}

void Bullet::Update()
{
	Behaviour::Update();
	Vector2 up = gameObject->transform->Up();
	gameObject->transform->SetAbsolutePositionDelta(speed * up * Time::DeltaTime());
	timer += Time::DeltaTime();
	if (timer > destroyTime)
	{
		game->Destroy(gameObject);
	}
}

void Bullet::OnTriggerEnter(Collider* col)
{
	if (col->gameObject->name == "Enemy")
	{
		game->Destroy(col->gameObject);
	}
}
