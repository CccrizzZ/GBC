#include "DemoProjectGame.h"
#include "Scene1.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "SpriteRenderer.h"
#include "Collider.h"
#include "BoxCollider.h"
#include "Rigidbody.h"
#include "Enemy.h"
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
	// Bind E-bullet to this instance
	AddPrefab("EnemyBullet", bind(&DemoProjectGame::EnemyBulletPrefab, this, placeholders::_1));
}


void DemoProjectGame::Setup(){
	SetScene(new Scene1());
}


void DemoProjectGame::EnemyPrefab(GameObject* enemy){

	enemy -> name = "Enemy";
	GameObject* enemyGraphic = Instantiate("EnemyGraphic", 0, 0, 90);
	enemyGraphic -> AddComponent(new SpriteRenderer("Assets/Enemy.png"));
	enemyGraphic -> transform -> SetParentRelative(enemy -> transform);
	// Set enemy scale to 1/10 of PNG file (change the default PNG scale in window0);
	enemyGraphic -> transform -> SetAbsoluteScale(Vector2(0.4f, 0.4f));


	Rigidbody* enemyRb = new Rigidbody();
	enemyRb -> SetBodyType(Rigidbody::dynamicBody);
	enemy -> AddComponent(enemyRb);

	BoxCollider* enemyCol = new BoxCollider();
	enemy -> AddComponent(enemyCol);

	enemyCol->SetDimension(Vector2(70, 70));



	enemy -> AddComponent(new Enemy());
}


void DemoProjectGame::BulletPrefab(GameObject* bullet) {
	// Setup bullet
	bullet -> name = "Bullet";
	bullet -> AddComponent(new SpriteRenderer("Assets/Bullet.png"));
	bullet -> AddComponent(new Bullet());
	bullet -> transform -> SetAbsoluteScale(Vector2(0.5f, 0.5f));

	// Rigidbody
	Rigidbody* rb = new Rigidbody();
	rb -> SetBodyType(Rigidbody::dynamicBody);
	bullet -> AddComponent(rb);
	rb -> SetBullet(true);

	// Collider
	BoxCollider* col = new BoxCollider();
	bullet -> AddComponent(col);
	col -> SetDimension(Vector2(20, 20));
	col -> SetTrigger(true);

}


void DemoProjectGame::EnemyBulletPrefab(GameObject* enemyBullet) {
	// Setup enemy bullet
	enemyBullet -> name = "EnemyBullet";
	enemyBullet -> AddComponent(new SpriteRenderer("Assets/Bullet.png"));
	enemyBullet -> AddComponent(new EnemyBullet());
	enemyBullet -> transform -> SetAbsoluteScale(Vector2(0.5f, 0.5f));

	// Rigidbody
	Rigidbody* rb = new Rigidbody();
	rb -> SetBodyType(Rigidbody::dynamicBody);
	enemyBullet -> AddComponent(rb);
	rb -> SetBullet(true);

	// Collider
	BoxCollider* col = new BoxCollider();
	enemyBullet -> AddComponent(col);
	col -> SetDimension(Vector2(20, 20));
	col -> SetTrigger(true);


}
