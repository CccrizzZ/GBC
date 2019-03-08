#include "Pursue.h"
#include "SteeringAgent.h"
#include "Time.h"
#include "Vector2.h"
#include "Game.h"
#include "DemoProjectGame.h"


Pursue::Pursue(){

}


Pursue::~Pursue(){

}


Pursue::Pursue(GameObject* go) : SteeringBehaviour(go){

}


void Pursue::Start() {
  lastTargetPosition = target -> position;
}

void Pursue::Update() {
  // Call SteeringBehaviour's Update
  SteeringBehaviour::Update();

  // Calculate target direction
  Vector2 direction = target -> position - gameObject -> transform -> position + 100;

  // Get distance
  float distance = direction.Length();

  // Get speed
  float speed = 0.5; //agent -> velocity.Length();

  // Calculate prediction
  float prediction = speed < distance / maxPredirection ? maxPredirection : distance / speed;

  // Calculate target direction
  Vector2 targetVel = (target -> position - lastTargetPosition) * 60.0f;

  // Calculate direction to target
  steering.linear = target -> position + targetVel * prediction - gameObject -> transform -> position;

  // maxAcceleration in that direction
  steering.linear.Normalize();
  steering.linear *= maxAcceleration;

  // Output steering
	steering.angular = 0;
	lastTargetPosition = target->position;

  // Make the AI move
  gameObject -> transform -> SetAbsolutePositionDelta(direction * speed * Time::DeltaTime());

  // Make the AI turn
  float angle = atan2(direction.y, direction.x);
  gameObject -> transform -> SetAbsoluteAngle(angle * 180.0f / M_PI);


  // Enemy fire will go in to a new class
  if (direction.x > 10 && direction.y > 10) {
    Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition(), gameObject->transform->GetAbsoluteAngle() - 90);
  }

}
