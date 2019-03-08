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

}


PlayerControls::~PlayerControls(){

}


void PlayerControls::Update(){


  vBullets.reserve(1);
  // Update bullet
  for (int i = 0; i < vBullets.size(); i++){
		vBullets[i] -> Update();

    // delete bullet when its outside of screen
		if (vBullets[i] -> canDel()){
			delete vBullets[i];
			vBullets[i] = nullptr;
			vBullets.erase(vBullets.begin() + i);
		}
		vBullets.shrink_to_fit();
	}


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


  // Quit on Escape button
  if (Input::GetKey(SDLK_ESCAPE)) {
    Game::quit = true;
  }


  // Fire bullet on space bar
  if (Input::GetKey(SDLK_SPACE) && canFire) {
    vBullets.push_back(new Bullet(direction));


    canFire = false;
  }
}
