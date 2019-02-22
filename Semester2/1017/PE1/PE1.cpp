#include "pch.h"
#include <iostream>
#include <ctime>
#include "SDL.h"
#include "Game.h"
using namespace std;

int main(int argc, char *argv[]) {
	// Define game obj
	Game pe1;

	// Init the window.
	pe1.init(
		"Practice Excercise 1", // window title
		SDL_WINDOWPOS_CENTERED, // x position
		SDL_WINDOWPOS_CENTERED, // y position
		1024, // width
		768, // height
		0 // flag for disply option
	);

	// Game running loop
	while (pe1.isRunning) {
		pe1.handleEvents();
    if (pe1.Tick()) {
      pe1.update();
      pe1.render();
    }
	}


	// Clean up the game.
	pe1.clean();
	system("pause");
	return 0;
}
