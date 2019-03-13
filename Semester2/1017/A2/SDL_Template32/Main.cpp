#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Game.h"
using namespace std;

int main(int argc, char* args[]){
	// Define game obj
	Game::Instance() -> Init(
		"GAME1017 Assignment 2", // window title
		SDL_WINDOWPOS_CENTERED, // x position
		SDL_WINDOWPOS_CENTERED, // y position
		1024, // width
		768, // height
		0 // flag for disply option
	);

	// Game loop
	while (Game::Instance() -> Running()) {
		Game::Instance() -> HandleEvents();
    if (Game::Instance() -> Tick()) {
      Game::Instance() -> Update();
      Game::Instance() -> Render();
    }
	}

	// Clean up the game.
	Game::Instance() -> Clean();
	system("pause");
	return 0;
}
