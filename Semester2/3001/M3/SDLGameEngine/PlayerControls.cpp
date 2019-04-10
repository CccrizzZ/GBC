#include "PlayerControls.h"
#include "Input.h"
#include "GameObject.h"
#include "Game.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Time.h"
#include "Bullet.h"
#include <vector>
using namespace std;

PlayerControls::PlayerControls(){
  scoreFont = TTF_OpenFont("Assets/scorebFont.ttf", 30);

}


PlayerControls::~PlayerControls(){

}



void PlayerControls::Update(){



  // Create vector2 obj
  Vector2 direction;

  // Change x and y direction according to the key
  direction.x = Input::GetKey(SDLK_d) ? 1 : Input::GetKey(SDLK_a) ? -1 : 0;
  direction.y = Input::GetKey(SDLK_s) ? 1 : Input::GetKey(SDLK_w) ? -1 : 0;

  // Make the Vector2 vector single length (combine all director into one single direction);
  direction.Normalize();

  // Set player position
  gameObject -> transform -> SetAbsolutePositionDelta(direction * speed * Time::DeltaTime());

  // Calculate player angle in radiant
  float angle = atan2(direction.y, direction.x);

  // Change direction only when pressing buttons
  if (direction.Length() >= 0.01f) {
    // Convert player angle to degree and set angle
    gameObject -> transform -> SetAbsoluteAngle(angle * 180.0f / M_PI);
  }





  finScore = 2076 - gameObject -> transform -> GetAbsolutePosition().y;

  temp = "Score : " + to_string(finScore);
  scoreSurf = TTF_RenderText_Solid(scoreFont, temp.c_str(), scoreColor);
  scoreText = SDL_CreateTextureFromSurface(Game::Instance()->gRenderer, scoreSurf);
  SDL_RenderCopy(Game::Instance()->gRenderer, scoreText, NULL, &sRect);



  sRect.w = 200;
  sRect.h = 50;
  sRect.x = 100;
  sRect.y = 100;

}

int PlayerControls::getFinScore(){
  return finScore;
}
