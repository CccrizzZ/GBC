#include "MoveX.h"
#include "SteeringAgent.h"
#include "Time.h"
#include "Vector2.h"
#include "Game.h"
#include "DemoProjectGame.h"



MoveX::MoveX(){
}


MoveX::~MoveX(){
}


MoveX::MoveX(GameObject* go) : SteeringBehaviour(go){
  counter = 0;
  turn = false;
}

void MoveX::Update(){
  SteeringBehaviour::Update();

  if (turn == false) {
    direction.x = 1;
    direction.y = 0;
    angle = atan2(direction.y, direction.x);
    gameObject -> transform -> SetAbsoluteAngle(angle * 180.0f / M_PI);
    gameObject -> transform -> SetAbsolutePositionDelta(direction * speed *  Time::DeltaTime());
    counter++;
    if (counter >= distance) {
      turn = true;
    }
  }

  if (turn == true) {
    direction.x = -1;
    direction.y = 0;
    angle = atan2(direction.y, direction.x);
    gameObject -> transform -> SetAbsoluteAngle(angle * 180.0f / M_PI);
    gameObject -> transform -> SetAbsolutePositionDelta(direction * speed *  Time::DeltaTime());
    counter--;
    if (counter <= 0) {
      turn = false;
    }
  }


  // Enemy firing
  if ((rand()%1000+1)>=990) {
    Instantiate(game->Prefab("EnemyBullet"), gameObject->transform->GetAbsolutePosition(), gameObject->transform->GetAbsoluteAngle() - 90);

  }
}
