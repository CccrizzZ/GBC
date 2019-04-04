#include "SteeringAgent.h"
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"

SteeringAgent::SteeringAgent(){

}

SteeringAgent::~SteeringAgent(){

}

SteeringAgent::SteeringAgent(GameObject* go) : Behaviour(go){

}

void SteeringAgent::Update(){
  //  For all the element in steerings
  for (SteeringBehaviour* steering : steerings) {
    // Set velocity
    velocity += steering -> steering.weight * steering-> steering.linear;
    // Set angularSpeed
    angularSpeed += steering -> steering.weight * steering -> steering.angular;
  }

  // If velocity reached limit, keep going at maxSpeed
  if (velocity.Length() >= maxSpeed) {
    velocity.Normalize();
    velocity *= maxSpeed;
  }

  // Set position
  gameObject -> transform -> position += velocity / 60.0f;
  // Convert velocity to degree and set steer angle
  gameObject -> transform -> angle = atan2(velocity.y, velocity.x) * 180.0f / M_PI + 90.0f;


}
