#include <iostream>
#include "Scene0.h"
#include "Scene1.h"
#include "Game.h"
#include "DemoProjectGame.h"
#include "Renderer.h"
#include "SpriteRenderer.h"
#include "Sprite.h"
#include "MenuControl.h"
using namespace std;



Scene0::Scene0(){

}


Scene0::~Scene0(){

}


void Scene0::Setup(){
  Scene::Setup();


  GameObject* GB = Instantiate("GameButton", 1920/2, 1080/2 + 200, 0);
  Sprite* sGB = new Sprite("Assets/startgame.png");
  SpriteRenderer* rGB = new SpriteRenderer(sGB);
  GB->AddComponent(rGB);

  MenuControl* mc = new MenuControl();
  GB->AddComponent(mc);

  GameObject* EB = Instantiate("ExitButton", 1920/2, 1080/2 + 300, 0);
  Sprite* sEB = new Sprite("Assets/exitgame.png");
  SpriteRenderer* rEB = new SpriteRenderer(sEB);
  EB->AddComponent(rEB);


  GameObject* Logo = Instantiate("Logo", 1920/2, 1080/2 - 300, 0);
  Sprite* sLogo = new Sprite("Assets/Touch-Down.png");
  SpriteRenderer* rLogo = new SpriteRenderer(sLogo);
  Logo->AddComponent(rLogo);


  




}
