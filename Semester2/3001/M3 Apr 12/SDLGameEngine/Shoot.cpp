#include "Shoot.h"
#include "Input.h"
#include "Game.h"


Shoot::Shoot()
{
}


Shoot::~Shoot()
{
}

void Shoot::Update(){
  Behaviour::Update();
  if (Input::GetKeyDown(SDLK_SPACE)) {
    Instantiate(game->Prefab("Bullet"), gameObject->transform->GetAbsolutePosition(), gameObject->transform->GetAbsoluteAngle() - 90);
  }
}
