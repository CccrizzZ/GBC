#pragma once
#include "Behaviour.h"
class EnemyBehaviour :
	public Behaviour
{
public:
	EnemyBehaviour();
	EnemyBehaviour(GameObject* _gameObject);
	EnemyBehaviour(GameObject* _gameObject, float _speed, float _destinationX, float _destinationY);
	~EnemyBehaviour();
	void Start();
	void Update();
	float speed;
	float destinationX;
	float destinationY;
private:
	float velocityX;
	float velocityY;
};

