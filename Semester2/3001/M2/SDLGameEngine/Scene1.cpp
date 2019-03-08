#include <iostream>
#include "Scene1.h"
#include "Camera.h"
#include "CameraFollow.h"
#include "Transform.h"
#include "GameObject.h"
#include "Renderer.h"
#include "SpriteRenderer.h"
#include "PlayerControls.h"
#include "Physics.h"
#include "Sprite.h"
#include "SpriteRenderer.h"
#include "SteeringAgent.h"
#include "Pursue.h"
#include "BoxCollider.h"
#include "Rigidbody.h"
#include "Game.h"
#include "Shoot.h"
using namespace std;

Scene1::Scene1(){

}


Scene1::~Scene1(){

}


void Scene1::Setup() {
  Scene::Setup();
  // Background
  GameObject* bg = Instantiate("bg", 1920/2, 1080/2, 0);
	Sprite* bgSprite = new Sprite("Assets/bg2.png");
	SpriteRenderer* bgRenderer = new SpriteRenderer(bgSprite);
	bg->AddComponent(bgRenderer);

  GameObject* bg2 = Instantiate("bg2", 1920/2, 1080/2 + 512, 0);
  Sprite* bgSprite2 = new Sprite("Assets/bg2.png");
  SpriteRenderer* bgRenderer2 = new SpriteRenderer(bgSprite2);
  bg2->AddComponent(bgRenderer2);

  GameObject* bg3 = Instantiate("bg3", 1920/2 + 512, 1080/2, 0);
  Sprite* bgSprite3 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer3 = new SpriteRenderer(bgSprite3);
  bg3->AddComponent(bgRenderer3);

  GameObject* bg4 = Instantiate("bg4", 1920/2, 1080/2 - 512, 0);
  Sprite* bgSprite4 = new Sprite("Assets/bg2.png");
  SpriteRenderer* bgRenderer4 = new SpriteRenderer(bgSprite4);
  bg4->AddComponent(bgRenderer4);

  GameObject* bg5 = Instantiate("bg5", 1920/2 - 512, 1080/2, 0);
  Sprite* bgSprite5 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer5 = new SpriteRenderer(bgSprite5);
  bg5->AddComponent(bgRenderer5);





  // Create player game obj
  GameObject* player = Instantiate("Player", Camera::width / 2, Camera::height / 2);

  // Rigidbody
  Rigidbody* rigid = new Rigidbody();
  rigid -> SetBodyType(Rigidbody::dynamicBody);
  // Add Rigidbody to player
  player -> AddComponent(rigid);


  // BoxCollider
  BoxCollider* col = new BoxCollider();
  // Add Collider
  player -> AddComponent(col);
  // SetDimension
  col -> SetDimension(Vector2(80,80));
  col -> SetCategory(game -> physics -> Layer_2);




  // Create player graphic game obj
  GameObject* playerGraphic = Instantiate("PlayerGraphic", 0, 0, 90);
  // Set player graphic to player obj
  playerGraphic -> transform -> SetParentRelative(player -> transform);
  // Set player scale to 1/10 of PNG file (change the default PNG scale in window0);
  playerGraphic -> transform -> SetAbsoluteScale(Vector2(0.1f, 0.1f));
  // Load png for player graphic
  playerGraphic -> AddComponent(new SpriteRenderer("Assets/Tank.png"));



  // Create PlayerControls obj
  PlayerControls* control = new PlayerControls();
  // Set speed to 300
  control -> speed = 300;
  // Add control listener to player
  player -> AddComponent(control);
  player -> AddComponent(new Shoot());
  player -> AddComponent(new CameraFollow());


  // Prefab 10 freezing enemy at random position on the screen
  for (int i = 0; i < 10; i++) {
    Instantiate(game -> Prefab("Enemy"), rand() % Camera::width, rand() % Camera::height);
  }









  // A single AI with pursue behavior
  GameObject* go = Instantiate("AI", 500, 900);
  GameObject* aiGraphic = Instantiate("AIGraphic", 0, 0, 90);

  Rigidbody* enemyRb = new Rigidbody();
  enemyRb -> SetBodyType(Rigidbody::dynamicBody);
  go -> AddComponent(enemyRb);
  BoxCollider* enemyCol = new BoxCollider();
  go -> AddComponent(enemyCol);

  // Collider size and layer
  enemyCol->SetDimension(Vector2(70, 70));
	enemyCol->SetCategory(game -> physics -> Layer_3);

  // Set AI graphics
  aiGraphic -> transform -> SetParentRelative(go -> transform);
  aiGraphic -> transform -> SetAbsoluteScale(Vector2(0.3f, 0.3f));
  aiGraphic -> AddComponent(new SpriteRenderer("Assets/Enemy.png"));


  // Initialize AI behavior
  Pursue* pursue = new Pursue(go);
	pursue -> target = player->transform;
	pursue -> maxAcceleration = 10;
	go -> AddComponent(pursue);
}
