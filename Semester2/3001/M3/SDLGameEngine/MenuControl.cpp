#include "MenuControl.h"
#include "Scene1.h"
#include "Scene0.h"
#include "DemoProjectGame.h"
#include "Input.h"
#include "Game.h"
using namespace std;



MenuControl::MenuControl(){
}


MenuControl::~MenuControl(){
}



void MenuControl::Update(){

  if (Input::GetKeyDown(SDLK_y)) {
    DemoProjectGame::Instance() -> SetScene(new Scene1());
  }else if (Input::GetKeyDown(SDLK_e)) {
    Game::Instance() -> End();
  }


}
