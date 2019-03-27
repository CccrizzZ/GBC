#pragma once
#include "Game.h"

class DemoProjectGame : public Game{
public:
	DemoProjectGame();
	~DemoProjectGame();

	void Awake();
	void Setup();

	void EnemyPrefab(GameObject* enemy);
	void BulletPrefab(GameObject* bullet);
	void EnemyBulletPrefab(GameObject* enemyBullet);


};
