#include "SteeringBehaviour.h"
#include "Game.h"


SteeringBehaviour::SteeringBehaviour(){
}


SteeringBehaviour::~SteeringBehaviour(){
}

SteeringBehaviour::SteeringBehaviour(GameObject* go) : Behaviour(go){

}

void SteeringBehaviour::Start(){

}

void SteeringBehaviour::Update() {
  // Set color to red
  SDL_SetRenderDrawColor(Game::gRenderer, 255, 0, 0, 255);
  // Draw red line for steering behaviour
  SDL_RenderDrawLine(
    Game::gRenderer,
    gameObject -> transform -> position.x,
    gameObject -> transform -> position.y,
    gameObject -> transform -> position.x + steering.linear.x * 100 ,
    gameObject -> transform -> position.y + steering.linear.y * 100
  );

}
