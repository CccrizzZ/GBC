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
#include "MoveX.h"
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

  GameObject* bg6 = Instantiate("bg6", 1920/2 + 512, 1080/2 + 512, 0);
  Sprite* bgSprite6 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer6 = new SpriteRenderer(bgSprite6);
  bg6->AddComponent(bgRenderer6);

  GameObject* bg7 = Instantiate("bg7", 1920/2 + 512, 1080/2 - 512, 0);
  Sprite* bgSprite7 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer7 = new SpriteRenderer(bgSprite7);
  bg7->AddComponent(bgRenderer7);

  GameObject* bg8 = Instantiate("bg8", 1920/2 - 512, 1080/2 - 512, 0);
  Sprite* bgSprite8 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer8 = new SpriteRenderer(bgSprite8);
  bg8->AddComponent(bgRenderer8);

  GameObject* bg9 = Instantiate("bg9", 1920/2 - 512, 1080/2 + 512, 0);
  Sprite* bgSprite9 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer9 = new SpriteRenderer(bgSprite9);
  bg9->AddComponent(bgRenderer9);

  GameObject* bg10 = Instantiate("bg10", 1920/2, 1080/2 + 1024, 0);
  Sprite* bgSprite10 = new Sprite("Assets/bg2.png");
  SpriteRenderer* bgRenderer10 = new SpriteRenderer(bgSprite10);
  bg10->AddComponent(bgRenderer10);

  GameObject* bg11 = Instantiate("bg11", 1920/2, 1080/2 + 1536, 0);
  Sprite* bgSprite11 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer11 = new SpriteRenderer(bgSprite11);
  bg11->AddComponent(bgRenderer11);

  GameObject* bg12 = Instantiate("bg12", 1920/2 - 512, 1080/2 + 1536, 0);
  Sprite* bgSprite12 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer12 = new SpriteRenderer(bgSprite12);
  bg12->AddComponent(bgRenderer12);

  GameObject* bg13 = Instantiate("bg13", 1920/2 + 512, 1080/2 + 1536, 0);
  Sprite* bgSprite13 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer13 = new SpriteRenderer(bgSprite13);
  bg13->AddComponent(bgRenderer13);

  GameObject* bg14 = Instantiate("bg14", 1920/2 - 512, 1080/2 + 1024, 0);
  Sprite* bgSprite14 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer14 = new SpriteRenderer(bgSprite14);
  bg14->AddComponent(bgRenderer14);

  GameObject* bg15 = Instantiate("bg15", 1920/2 + 512, 1080/2 + 1024, 0);
  Sprite* bgSprite15 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer15 = new SpriteRenderer(bgSprite15);
  bg15->AddComponent(bgRenderer15);

  GameObject* bg16 = Instantiate("bg16", 1920/2, 1080/2 - 1024, 0);
  Sprite* bgSprite16 = new Sprite("Assets/bg2.png");
  SpriteRenderer* bgRenderer16 = new SpriteRenderer(bgSprite16);
  bg16->AddComponent(bgRenderer16);

  GameObject* bg17 = Instantiate("bg17", 1920/2, 1080/2 - 1536, 0);
  Sprite* bgSprite17 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer17 = new SpriteRenderer(bgSprite17);
  bg17->AddComponent(bgRenderer17);

  GameObject* bg18 = Instantiate("bg18", 1920/2 - 512, 1080/2 - 1536, 0);
  Sprite* bgSprite18 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer18 = new SpriteRenderer(bgSprite18);
  bg18->AddComponent(bgRenderer18);

  GameObject* bg19 = Instantiate("bg19", 1920/2 + 512, 1080/2 - 1024, 0);
  Sprite* bgSprite19 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer19 = new SpriteRenderer(bgSprite19);
  bg19->AddComponent(bgRenderer19);

  GameObject* bg20 = Instantiate("bg20", 1920/2 + 512, 1080/2 - 1536, 0);
  Sprite* bgSprite20 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer20 = new SpriteRenderer(bgSprite20);
  bg20->AddComponent(bgRenderer20);

  GameObject* bg21 = Instantiate("bg21", 1920/2 - 512, 1080/2 - 1024, 0);
  Sprite* bgSprite21 = new Sprite("Assets/bg.png");
  SpriteRenderer* bgRenderer21 = new SpriteRenderer(bgSprite21);
  bg21->AddComponent(bgRenderer21);


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

  // Pursue enemy
  for (int i = 0; i < 5; i++) {
    GameObject* enemy = Instantiate(game -> Prefab("Enemy"), rand() % Camera::width, rand() % Camera::height);

    // Initialize pursue AI behavior
    Pursue* pursue = new Pursue(enemy);
    pursue -> target = player->transform;
    pursue -> maxAcceleration = 10;
    enemy -> AddComponent(pursue);
  }

  // Roaming enemy
  for (int i = 0; i < 135; i++) {
    GameObject* enemy = Instantiate(game -> Prefab("Enemy"), rand() % 1024 + 512, rand() % 3584 + (-1280));

    // Initialize pursue AI behavior
    MoveX* move = new MoveX(enemy);
    enemy -> AddComponent(move);
  }








}
