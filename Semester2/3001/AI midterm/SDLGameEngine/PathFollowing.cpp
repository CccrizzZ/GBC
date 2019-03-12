#include "PathFollowing.h"
#include "Game.h"
#include <ctime>


PathFollowing::PathFollowing()
{
}

PathFollowing::PathFollowing(GameObject* go) : Arrive(go)
{

}


PathFollowing::~PathFollowing()
{
}

void PathFollowing::Start()
{
	srand(time(NULL));

	currentWaypoint = waypoints.begin();

	float distance = (gameObject->transform->GetAbsolutePosition() - *currentWaypoint).Length();
	float currentDistance = 0;
	for (std::list<Vector2>::iterator it = waypoints.begin(); it != waypoints.end(); ++it)
	{
		currentDistance = (gameObject->transform->GetAbsolutePosition() - *it).Length();
		if (currentDistance < distance)
		{
			distance = currentDistance;
			currentWaypoint = it;
		}
	}

	target->SetAbsolutePosition(*currentWaypoint);


	Vector2 closestWaypoint = *currentWaypoint;
	++currentWaypoint;
	if (currentWaypoint != waypoints.end())
	{
		Vector2 nextPoint = *currentWaypoint;
		Vector2 lineVector = nextPoint - closestWaypoint;
		Vector2 toVector = gameObject->transform->GetAbsolutePosition() - closestWaypoint;
		Vector2 projection = toVector.Dot(lineVector) * (lineVector / (lineVector.Length() * lineVector.Length()));
		target->SetAbsolutePosition(projection + closestWaypoint);
		--currentWaypoint;
	}

	Arrive::Start();
}

void PathFollowing::Update(){

	if (currentWaypoint == waypoints.end()) {
		Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition() + 50 * gameObject->transform->Right(), gameObject->transform->GetAbsoluteAngle() - 90);
	}


	if ((target->GetAbsolutePosition() - gameObject->transform->GetAbsolutePosition()).Length() < distanceThreshold)
	{
		if (currentWaypoint != waypoints.end())
		{
			++currentWaypoint;
			if (currentWaypoint != waypoints.end())
			{
				target->SetAbsolutePosition(*currentWaypoint);
			}
		}
	}

	// Debug Graphics
	Vector2 start = *waypoints.begin();
	SDL_SetRenderDrawColor(Game::gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	for (std::list<Vector2>::iterator it = waypoints.begin(); it != waypoints.end(); ++it)
	{
		SDL_RenderDrawLine(Game::gRenderer, start.x, start.y, (*it).x, (*it).y);
		start = *it;
	}

	Arrive::Update();
}
