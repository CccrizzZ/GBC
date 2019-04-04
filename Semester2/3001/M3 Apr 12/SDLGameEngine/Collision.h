#pragma once
#include <list>
#include "Vector2.h"

class Rigidbody;
class Collider;
class Collision
{
public:
	Collision();
	~Collision();
	Rigidbody* rigidbody;
	Collider* collider;
	std::list<Vector2> contacts;
	Vector2 normal;
};

