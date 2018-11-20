#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include <iostream>
#include "Game.cpp"
using namespace std;

int main(){
  Game game;
  game.init(
    "",  // Title
    SDL_WINDOWPOS_CENTERED, // x position
    SDL_WINDOWPOS_CENTERED, // y position
    1024, // width
    768, // height
    0 // flag
  );

  while (game.running()) {
    game.handleEvents();
    game.update();
    game.render();
  }
  game.clean();
  system("pause");
  return 0;
}
