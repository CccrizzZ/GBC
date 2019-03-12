#include "KinematicSeek.h"
#include "GameObject.h"
#include "Transform.h"
#include "Vector2.h"


KinematicSeek::KinematicSeek()
{
}

KinematicSeek::KinematicSeek(GameObject* go) : KinematicSteeringBehaviour(go)
{
}

KinematicSeek::~KinematicSeek()
{
}

void KinematicSeek::Update()
{
	Vector2 toVector = target - gameObject->transform->GetAbsolutePosition();
	float distance = toVector.Length();
	velocity = (toVector / distance) * (distance < slowDistance ? distance : maxSpeed);
}
