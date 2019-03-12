#include "EnemyBehaviour.h"
#include "GameObject.h"
#include "Transform.h"


EnemyBehaviour::EnemyBehaviour()
{
}

EnemyBehaviour::EnemyBehaviour(GameObject* _gameObject) : Behaviour(_gameObject)
{

}

EnemyBehaviour::EnemyBehaviour(GameObject* _gameObject, float _speed, float _destinationX, float _destinationY) : Behaviour(_gameObject)
{
	speed = _speed;
	destinationX = _destinationX;
	destinationY = _destinationY;

	velocityX = destinationX - gameObject->transform->position->x;
	velocityY = destinationY - gameObject->transform->position->y;

	float magnitude = sqrt(velocityX * velocityX + velocityY * velocityY);
	velocityX /= magnitude;
	velocityY /= magnitude;
}

void EnemyBehaviour::Start()
{

}

void EnemyBehaviour::Update()
{
	if (abs(gameObject->transform->position->x - destinationX) > 10 &&
		abs(gameObject->transform->position->y - destinationY) > 10)
	{
		gameObject->transform->position->x += (int)(velocityX * speed);
		gameObject->transform->position->y += (int)(velocityY * speed);
	}
	//gameObject->transform->position->x += (int)(velocityX * speed);
	//gameObject->transform->position->y += (int)(velocityY * speed);
}

EnemyBehaviour::~EnemyBehaviour()
{
}
