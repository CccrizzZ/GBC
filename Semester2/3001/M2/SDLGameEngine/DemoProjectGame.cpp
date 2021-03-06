#include "DemoProjectGame.h"
#include "Scene1.h"
#include "Bullet.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "Rigidbody.h"
using namespace std;

DemoProjectGame::DemoProjectGame(){

}


DemoProjectGame::~DemoProjectGame(){

}


void DemoProjectGame::Awake(){
	// Bind EnemyPrefab to this instance
	AddPrefab("Enemy", bind(&DemoProjectGame::EnemyPrefab, this, placeholders::_1));
	// Bind BulletPrefab to this instance
	AddPrefab("Bullet", bind(&DemoProjectGame::BulletPrefab, this, placeholders::_1));
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

	Rigidbody* enemyRb = new Rigidbody();
	enemyRb -> SetBodyType(Rigidbody::dynamicBody);
	enemyGraphic -> AddComponent(enemyRb);
	BoxCollider* enemyCol = new BoxCollider();
	enemyGraphic -> AddComponent(enemyCol);

	// Collider size and layer
	enemyCol->SetDimension(Vector2(70, 70));
	enemyCol->SetCategory(physics -> Layer_3);
	enemyCol->SetCollisionMask(~physics -> Layer_3);
}


void DemoProjectGame::BulletPrefab(GameObject* bullet) {
	// Setup bullet
	bullet -> name = "Bullet";
	bullet -> AddComponent(new SpriteRenderer("Assets/Cannon_Ball.png"));
	bullet -> AddComponent(new Bullet());
	bullet -> transform -> SetAbsoluteScale(Vector2(0.1f, 0.1f));

	// // Set rigidbody
	// Rigidbody* rb = new Rigidbody();
	// rb -> SetBodyType(Rigidbody::dynamicBody);
	// bullet -> AddComponent(rb);
	// rb -> SetBullet(true);
	//
	// // Set Collider
	// BoxCollider* col = new BoxCollider();
	// bullet -> AddComponent(col);
	//
	// col -> SetDimension(Vector2(10,10));
	// col -> SetTrigger(true);

}
