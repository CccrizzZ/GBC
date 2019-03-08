#include "Bullet.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Time.h"
#include "Component.h"


Bullet::Bullet(Vector2 direct){
  bDirection = direct;
  DeleteNow = false;
  bSpeed = 3.0f;


  // Crete bullet
  bullet = Instantiate("Bullet", direct.x, direct.y);
  bGraphic = Instantiate("bGraphic", 0, 0, 90);
  bGraphic -> transform -> SetParentRelative(bullet -> transform);
  bGraphic -> AddComponent(new SpriteRenderer("Assets/Cannon_Ball.png"));
  bGraphic -> transform -> SetAbsoluteScale(Vector2(0.1f, 0.1f));

}


Bullet::~Bullet(){

}


void Bullet::Update(){

  bullet -> transform -> SetAbsolutePositionDelta(bDirection * bSpeed * Time::DeltaTime());

  if (bDirection.x >= 1024 || bDirection.x <= 0 || bDirection.y >= 768 || bDirection.y <= 0){
    DeleteNow = true;
  }
}
