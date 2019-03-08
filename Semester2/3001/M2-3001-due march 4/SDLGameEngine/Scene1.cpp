#include <iostream>
#include "Scene1.h"
#include "Camera.h"
#include "Transform.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "PlayerControls.h"
#include "SteeringAgent.h"
#include "Pursue.h"
#include "BoxCollider.h"
#include "Rigidbody.h"
#include "Game.h"
using namespace std;

Scene1::Scene1(){

}


Scene1::~Scene1(){

}


void Scene1::Setup() {
  // Rigidbody from box 2d
  Rigidbody* rigid = new Rigidbody();

  // Collider from box 2d
  BoxCollider* col = new BoxCollider();

  // Static rigidbody
  rigid -> SetBodyType(rigid -> bodyType::staticBody);






  // Create player game obj
  GameObject* player = Instantiate("Player", Camera::width / 2, Camera::height / 2);

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

  player -> AddComponent(rigid);


  // Prefab 10 freezing enemy at random position on the screen
  for (int i = 0; i < 10; i++) {
    Instantiate(game -> Prefab("Enemy"), rand() % Camera::width, rand() % Camera::height);
  }

  // A single AI with pursue behavior
  GameObject* go = Instantiate("AI", 500, 900);
  GameObject* aiGraphic = Instantiate("AIGraphic", 0, 0, 90);

  // Set AI graphics
  aiGraphic -> transform -> SetParentRelative(go -> transform);
  aiGraphic -> transform -> SetAbsoluteScale(Vector2(0.3f, 0.3f));
  aiGraphic -> AddComponent(new SpriteRenderer("Assets/Enemy.png"));

  go -> AddComponent(rigid);


  // Initialize AI behavior
  Pursue* pursue = new Pursue(go);
	pursue -> target = player->transform;
	pursue -> maxAcceleration = 10;
	go -> AddComponent(pursue);
}
