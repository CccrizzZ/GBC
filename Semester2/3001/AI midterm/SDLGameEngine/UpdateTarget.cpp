#include "UpdateTarget.h"
#include <stdlib.h>
#include <time.h>
#include "Vector2.h"
#include "GameObject.h"
#include "Transform.h"


UpdateTarget::UpdateTarget()
{
}

UpdateTarget::UpdateTarget(GameObject* go) : Behaviour(go)
{
}

UpdateTarget::~UpdateTarget()
{
}

void UpdateTarget::Update()
{
	if ((gameObject->transform->GetAbsolutePosition() - steer->target).Length() <= 10)
	{
		steer->target.x = rand() % 1280;
		steer->target.y = rand() % 720;
		targetObject->transform->SetAbsolutePosition(steer->target);
	}
}