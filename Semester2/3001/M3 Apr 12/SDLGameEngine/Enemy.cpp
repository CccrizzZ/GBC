#include "Enemy.h"
#include "Input.h"
#include "Rigidbody.h"
#include "GameObject.h"
#include "Physics.h"
#include "RaycastHit.h"
#include "Game.h"

Enemy::Enemy(){
}


Enemy::~Enemy(){
}


void Enemy::Update(){
	Behaviour::Update();
}
