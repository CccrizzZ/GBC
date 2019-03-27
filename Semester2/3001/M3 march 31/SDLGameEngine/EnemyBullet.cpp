#include "EnemyBullet.h"
#include "GameObject.h"
#include "Transform.h"
#include "Behaviour.h"
#include "Time.h"
#include "Game.h"
using namespace std;


EnemyBullet::EnemyBullet(){
}


EnemyBullet::~EnemyBullet(){

}

void EnemyBullet::Awake(){
  Behaviour::Awake();
  triggerEventListener = make_shared<EventListener<Collider*>>(bind(&EnemyBullet::OnTriggerEnter, this, placeholders::_1));
  gameObject -> OnTriggerEnter.AddListener(triggerEventListener);
}


void EnemyBullet::Update(){
  Behaviour::Update();
  Vector2 up = gameObject -> transform -> Up();
  gameObject -> transform ->SetAbsolutePositionDelta(ebSpeed * up * Time::DeltaTime());

  timer += Time::DeltaTime();
  if (timer > destroyTime) {
    game -> Destroy(gameObject);
  }


}


void EnemyBullet::Cleanup(){
  Behaviour::Cleanup();
  gameObject -> OnTriggerEnter.RemoveListener(triggerEventListener);
}

void EnemyBullet::OnTriggerEnter(Collider* col){
  if (col -> gameObject -> name == "Player") {
    game -> Destroy(col -> gameObject);
  }
}
