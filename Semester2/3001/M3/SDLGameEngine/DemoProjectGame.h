#pragma once
#include "Game.h"

class DemoProjectGame : public Game{
public:
	// Global instance
	static DemoProjectGame* Instance() {
		static DemoProjectGame* instance = new DemoProjectGame();
		return instance;
	}

	DemoProjectGame();
	~DemoProjectGame();

	void Awake();
	void Setup();

	// Prefab
	void EnemyPrefab(GameObject* enemy);
	void BulletPrefab(GameObject* bullet);
	void EnemyBulletPrefab(GameObject* enemyBullet);


	bool gameover;


	// Sounds
	AudioManager* aManager;

	AudioManager* GetAM(){
		return aManager;
	}

	void Playfire() {
		aManager -> PlaySound(0);
	}

};
