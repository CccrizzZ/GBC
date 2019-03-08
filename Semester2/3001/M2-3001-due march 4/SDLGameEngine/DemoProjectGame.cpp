#include "DemoProjectGame.h"
#include "Scene1.h"
#include "SpriteRenderer.h"
using namespace std;

DemoProjectGame::DemoProjectGame(){

}


DemoProjectGame::~DemoProjectGame(){

}


void DemoProjectGame::Awake(){
	// Bind EnemyPrefab to this instance
	AddPrefab("Enemy", bind(&DemoProjectGame::EnemyPrefab, this, placeholders::_1));

}


void DemoProjectGame::Setup(){
	SetScene(new Scene1());
}


void DemoProjectGame::EnemyPrefab(GameObject* enemy){

	// Create enemy graphic game obj
	GameObject* enemyGraphic = Instantiate("EnemyGraphic", 0, 0, 90);

	// Set enemy graphic to enemy obj
	enemyGraphic -> transform -> SetParentRelative(enemy -> transform);

	// Set enemy scale to 1/10 of PNG file (change the default PNG scale in window0);
	enemyGraphic -> transform -> SetAbsoluteScale(Vector2(0.3f, 0.3f));

	// Load png for enemy graphic
	enemyGraphic -> AddComponent(new SpriteRenderer("Assets/Enemy.png"));


}
