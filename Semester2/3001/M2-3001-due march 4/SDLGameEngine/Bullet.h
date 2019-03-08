#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Component.h"

class Bullet : Component{

public:
	// Static instance
	static Bullet* Instance() {
		static Bullet* instance = new Bullet();
		return instance;
	}

	Bullet();
	Bullet(Vector2 direct);
	~Bullet();


	GameObject* bullet;
  GameObject* bGraphic;

	float bSpeed;
	Vector2 bDirection;

	// Flag for deleting Bullet
	bool DeleteNow;


	// Getter
	void Update();
	bool canDel(){
		return DeleteNow;
	}
};
