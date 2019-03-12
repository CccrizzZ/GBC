#include "DynamicSteeringDemo.h"
#include "SteeringAgent.h"
#include "Seek.h"
#include "Flee.h"
#include "Arrive.h"
#include "Align.h"
#include "Pursue.h"
#include "UpdateVectorTarget.h"
#include "MoveInCircle.h"
#include "Time.h"
#include "PathFollowing.h"
#include "SpriteRenderer.h"


DynamicSteeringDemo::DynamicSteeringDemo()
{
}


DynamicSteeringDemo::~DynamicSteeringDemo()
{
}

void DynamicSteeringDemo::Awake()
{
	Game::screenWidth = 1920;
	Game::screenHeight = 1080;
}

void DynamicSteeringDemo::Setup()
{
	GameObject* go = CreateGameObject("Tank", 300, 200, 0);
	go->AddComponent(new SpriteRenderer("Assets/Tank.png"));
	go->transform->SetRelativeScale(Vector2(0.1f, 0.1f));


	// PathFollowing
	PathFollowing* pathFollowing = new PathFollowing(go);
	pathFollowing->target = tgt->transform;;
	pathFollowing->maxAccelaraction = 1;
	go->AddComponent(pathFollowing);
	pathFollowing->waypoints.push_back(Vector2(50, 50));
	pathFollowing->waypoints.push_back(Vector2(100, 700));
	pathFollowing->waypoints.push_back(Vector2(200, 100));
	pathFollowing->waypoints.push_back(Vector2(350, 500));
	pathFollowing->waypoints.push_back(Vector2(450, 150));
	pathFollowing->waypoints.push_back(Vector2(600, 600));
	pathFollowing->waypoints.push_back(Vector2(750, 50));
	pathFollowing->waypoints.push_back(Vector2(900, 550));
	pathFollowing->waypoints.push_back(Vector2(1000, 100));
	pathFollowing->waypoints.push_back(Vector2(1150, 500));




	// SteeringAgent
	SteeringAgent* agent = new SteeringAgent(go);
	agent->steerings.push_back(pathFollowing);
	agent->maxSpeed = 200;
	agent->velocity.y = -100;
	go->AddComponent(agent);

	pathFollowing->agent = agent;


	UpdateVectorTarget* updateTarget = new UpdateVectorTarget(go);
	updateTarget->target = &tgt->transform->GetAbsolutePosition();
	updateTarget->maxTime = 20;
	go->AddComponent(updateTarget);

	updateTarget->targetObject = tgt;

	//Time::timeScale = 0.3F;
}
