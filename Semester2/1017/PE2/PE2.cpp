#include "pch.h"
#include <iostream>
#include <ctime>
#include "SDL.h"
#include "Game.h"
using namespace std;

int main(int argc, char *argv[]) {
	// Define game obj
	Game::Instance() -> init(
    "Practice Excercise 2", // window title
    SDL_WINDOWPOS_CENTERED, // x position
    SDL_WINDOWPOS_CENTERED, // y position
    1024, // width
    768, // height
    0 // flag for disply option
  );

	// Game running loop
	while (Game::Instance() -> running()) {
		Game::Instance() -> handleEvents();
    if (Game::Instance() -> Tick()) {
      Game::Instance() -> update();
      Game::Instance() -> render();
    }
	}


	// Clean up the game.
	Game::Instance() -> clean();
	system("pause");
	return 0;
}
