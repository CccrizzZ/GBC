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
#include "MoveY.h"
#include "ScoreBoard.h"
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




  // Walls

  BoxCollider* wallCol = new BoxCollider();
  Rigidbody* wrb = new Rigidbody();
  wrb -> SetBodyType(Rigidbody::staticBody);
  GameObject* w1 = Instantiate("w1", 1920/2 - 1024, 1080/2, 0);
  Sprite* w1Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w1Renderer = new SpriteRenderer(w1Sprite);
  w1->AddComponent(w1Renderer);
  w1->AddComponent(wallCol);
  wallCol -> SetDimension(Vector2(512,512));
  w1->AddComponent(wrb);

  BoxCollider* wallCol2 = new BoxCollider();
  GameObject* w2 = Instantiate("w2", 1920/2 - 1024, 1080/2 - 512, 0);
  Sprite* w2Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w2Renderer = new SpriteRenderer(w2Sprite);
  w2->AddComponent(w2Renderer);
  w2->AddComponent(wallCol2);
  wallCol2 -> SetDimension(Vector2(512,512));
  w2->AddComponent(wrb);

  BoxCollider* wallCol3 = new BoxCollider();
  GameObject* w3 = Instantiate("w3", 1920/2 - 1024, 1080/2 - 1024, 0);
  Sprite* w3Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w3Renderer = new SpriteRenderer(w3Sprite);
  w3->AddComponent(w3Renderer);
  w3->AddComponent(wallCol3);
  wallCol3 -> SetDimension(Vector2(512,512));
  w3->AddComponent(wrb);

  BoxCollider* wallCol4 = new BoxCollider();
  GameObject* w4 = Instantiate("w4", 1920/2 - 1024, 1080/2 - 1536, 0);
  Sprite* w4Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w4Renderer = new SpriteRenderer(w4Sprite);
  w4->AddComponent(w4Renderer);
  w4->AddComponent(wallCol4);
  wallCol4 -> SetDimension(Vector2(512,512));
  w4->AddComponent(wrb);

  BoxCollider* wallCol5 = new BoxCollider();
  GameObject* w5 = Instantiate("w5", 1920/2 - 1024, 1080/2 - 2048, 0);
  Sprite* w5Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w5Renderer = new SpriteRenderer(w5Sprite);
  w5->AddComponent(w5Renderer);
  w5->AddComponent(wallCol5);
  wallCol5 -> SetDimension(Vector2(512,512));
  w5->AddComponent(wrb);

  BoxCollider* wallCol6 = new BoxCollider();
  GameObject* w6 = Instantiate("w6", 1920/2 - 1024, 1080/2 + 512, 0);
  Sprite* w6Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w6Renderer = new SpriteRenderer(w6Sprite);
  w6->AddComponent(w6Renderer);
  w6->AddComponent(wallCol6);
  wallCol6 -> SetDimension(Vector2(512,512));
  w6->AddComponent(wrb);

  BoxCollider* wallCol7 = new BoxCollider();
  GameObject* w7 = Instantiate("w7", 1920/2 - 1024, 1080/2 + 1024, 0);
  Sprite* w7Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w7Renderer = new SpriteRenderer(w7Sprite);
  w7->AddComponent(w7Renderer);
  w7->AddComponent(wallCol7);
  wallCol7 -> SetDimension(Vector2(512,512));
  w7->AddComponent(wrb);

  BoxCollider* wallCol8 = new BoxCollider();
  GameObject* w8 = Instantiate("w8", 1920/2 - 1024, 1080/2 + 1536, 0);
  Sprite* w8Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w8Renderer = new SpriteRenderer(w8Sprite);
  w8->AddComponent(w8Renderer);
  w8->AddComponent(wallCol8);
  wallCol8 -> SetDimension(Vector2(512,512));
  w8->AddComponent(wrb);

  BoxCollider* wallCol9 = new BoxCollider();
  GameObject* w9 = Instantiate("w9", 1920/2 - 1024, 1080/2 + 2048, 0);
  Sprite* w9Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w9Renderer = new SpriteRenderer(w9Sprite);
  w9->AddComponent(w9Renderer);
  w9->AddComponent(wallCol9);
  wallCol9 -> SetDimension(Vector2(512,512));
  w9->AddComponent(wrb);

  BoxCollider* wallCol10 = new BoxCollider();
  GameObject* w10 = Instantiate("w10", 1920/2 - 512, 1080/2 + 2048, 0);
  Sprite* w10Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w10Renderer = new SpriteRenderer(w10Sprite);
  w10->AddComponent(w10Renderer);
  w10->AddComponent(wallCol10);
  wallCol10 -> SetDimension(Vector2(512,512));
  w10->AddComponent(wrb);

  BoxCollider* wallCol11 = new BoxCollider();
  GameObject* w11 = Instantiate("w11", 1920/2, 1080/2 + 2048, 0);
  Sprite* w11Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w11Renderer = new SpriteRenderer(w11Sprite);
  w11->AddComponent(w11Renderer);
  w11->AddComponent(wallCol11);
  wallCol11 -> SetDimension(Vector2(512,512));
  w11->AddComponent(wrb);

  BoxCollider* wallCol12 = new BoxCollider();
  GameObject* w12 = Instantiate("w12", 1920/2 + 512, 1080/2 + 2048, 0);
  Sprite* w12Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w12Renderer = new SpriteRenderer(w12Sprite);
  w12->AddComponent(w12Renderer);
  w12->AddComponent(wallCol12);
  wallCol12 -> SetDimension(Vector2(512,512));
  w12->AddComponent(wrb);

  BoxCollider* wallCol13 = new BoxCollider();
  GameObject* w13 = Instantiate("w13", 1920/2 + 1024, 1080/2 + 2048, 0);
  Sprite* w13Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w13Renderer = new SpriteRenderer(w13Sprite);
  w13->AddComponent(w13Renderer);
  w13->AddComponent(wallCol13);
  wallCol13 -> SetDimension(Vector2(512,512));
  w13->AddComponent(wrb);

  BoxCollider* wallCol14 = new BoxCollider();
  GameObject* w14 = Instantiate("w14", 1920/2 + 1024, 1080/2 + 1536, 0);
  Sprite* w14Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w14Renderer = new SpriteRenderer(w14Sprite);
  w14->AddComponent(w14Renderer);
  w14->AddComponent(wallCol14);
  wallCol14 -> SetDimension(Vector2(512,512));
  w14->AddComponent(wrb);

  BoxCollider* wallCol15 = new BoxCollider();
  GameObject* w15 = Instantiate("w15", 1920/2 + 1024, 1080/2 + 1024, 0);
  Sprite* w15Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w15Renderer = new SpriteRenderer(w15Sprite);
  w15->AddComponent(w15Renderer);
  w15->AddComponent(wallCol15);
  wallCol15 -> SetDimension(Vector2(512,512));
  w15->AddComponent(wrb);

  BoxCollider* wallCol16 = new BoxCollider();
  GameObject* w16 = Instantiate("w16", 1920/2 + 1024, 1080/2 + 512, 0);
  Sprite* w16Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w16Renderer = new SpriteRenderer(w16Sprite);
  w16->AddComponent(w16Renderer);
  w16->AddComponent(wallCol16);
  wallCol16 -> SetDimension(Vector2(512,512));
  w16->AddComponent(wrb);

  BoxCollider* wallCol17 = new BoxCollider();
  GameObject* w17 = Instantiate("w17", 1920/2 + 1024, 1080/2, 0);
  Sprite* w17Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w17Renderer = new SpriteRenderer(w17Sprite);
  w17->AddComponent(w17Renderer);
  w17->AddComponent(wallCol17);
  wallCol17 -> SetDimension(Vector2(512,512));
  w17->AddComponent(wrb);

  BoxCollider* wallCol18 = new BoxCollider();
  GameObject* w18 = Instantiate("w18", 1920/2 + 1024, 1080/2 - 512, 0);
  Sprite* w18Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w18Renderer = new SpriteRenderer(w18Sprite);
  w18->AddComponent(w18Renderer);
  w18->AddComponent(wallCol18);
  wallCol18 -> SetDimension(Vector2(512,512));
  w18->AddComponent(wrb);

  BoxCollider* wallCol19 = new BoxCollider();
  GameObject* w19 = Instantiate("w19", 1920/2 + 1024, 1080/2 - 1024, 0);
  Sprite* w19Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w19Renderer = new SpriteRenderer(w19Sprite);
  w19->AddComponent(w19Renderer);
  w19->AddComponent(wallCol19);
  wallCol19 -> SetDimension(Vector2(512,512));
  w19->AddComponent(wrb);

  BoxCollider* wallCol20 = new BoxCollider();
  GameObject* w20 = Instantiate("w20", 1920/2 + 1024, 1080/2 - 1536, 0);
  Sprite* w20Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w20Renderer = new SpriteRenderer(w20Sprite);
  w20->AddComponent(w20Renderer);
  w20->AddComponent(wallCol20);
  wallCol20 -> SetDimension(Vector2(512,512));
  w20->AddComponent(wrb);

  BoxCollider* wallCol21 = new BoxCollider();
  GameObject* w21 = Instantiate("w21", 1920/2 + 1024, 1080/2 - 2048, 0);
  Sprite* w21Sprite = new Sprite("Assets/brick.png");
  SpriteRenderer* w21Renderer = new SpriteRenderer(w21Sprite);
  w21->AddComponent(w21Renderer);
  w21->AddComponent(wallCol21);
  wallCol21 -> SetDimension(Vector2(512,512));
  w21->AddComponent(wrb);

  BoxCollider* wallCol22 = new BoxCollider();
  GameObject* w22 = Instantiate("w22", 1920/2 + 512, 1080/2 - 2048, 0);
  Sprite* w22Sprite = new Sprite("Assets/goal.png");
  SpriteRenderer* w22Renderer = new SpriteRenderer(w22Sprite);
  w22->AddComponent(w22Renderer);
  w22->AddComponent(wallCol22);
  wallCol22 -> SetDimension(Vector2(512,512));
  w22->AddComponent(wrb);

  BoxCollider* wallCol23 = new BoxCollider();
  GameObject* w23 = Instantiate("w23", 1920/2, 1080/2 - 2048, 0);
  Sprite* w23Sprite = new Sprite("Assets/goal.png");
  SpriteRenderer* w23Renderer = new SpriteRenderer(w23Sprite);
  w23->AddComponent(w23Renderer);
  w23->AddComponent(wallCol23);
  wallCol23 -> SetDimension(Vector2(512,512));
  w23->AddComponent(wrb);

  BoxCollider* wallCol24 = new BoxCollider();
  GameObject* w24 = Instantiate("w24", 1920/2 - 512, 1080/2 - 2048, 0);
  Sprite* w24Sprite = new Sprite("Assets/goal.png");
  SpriteRenderer* w24Renderer = new SpriteRenderer(w24Sprite);
  w24->AddComponent(w24Renderer);
  w24->AddComponent(wallCol24);
  wallCol24 -> SetDimension(Vector2(512,512));
  w24->AddComponent(wrb);




  // Create player game obj
  GameObject* player = Instantiate("Player", Camera::width / 2, Camera::height / 2 + 1536);

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
  // Set speed to 500
  control -> speed = 500;
  // Add control listener to player
  player -> AddComponent(control);
  player -> AddComponent(new Shoot());
  player -> AddComponent(new CameraFollow());
  ScoreBoard* s = new ScoreBoard();
  player -> AddComponent(s);

  // Pursue enemy
  for (int i = 0; i < 5; i++) {
    GameObject* enemy = Instantiate(game -> Prefab("Enemy"), rand() % Camera::width, rand() % Camera::height);

    // Initialize pursue AI behavior
    Pursue* pursue = new Pursue(enemy);
    pursue -> target = player->transform;
    pursue -> maxAcceleration = 10;
    enemy -> AddComponent(pursue);
  }

  // X Roaming enemy
  for (int i = 0; i < 50; i++) {
    GameObject* enemy = Instantiate(game -> Prefab("Enemy"), rand() % 1024 + 512, rand() % 3584 + (-1536));

    // Initialize pursue AI behavior
    MoveX* move = new MoveX(enemy);
    enemy -> AddComponent(move);
  }

  // Y Roaming enemy
  for (int i = 0; i < 50; i++) {
    GameObject* enemy = Instantiate(game -> Prefab("Enemy"), rand() % 1024 + 512, rand() % 3584 + (-1536));

    // Initialize pursue AI behavior
    MoveY* move = new MoveY(enemy);
    enemy -> AddComponent(move);
  }








}
