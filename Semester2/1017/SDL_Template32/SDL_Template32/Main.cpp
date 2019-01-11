#include <iostream>
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
using namespace std;

int main(int argc, char* args[])
{
	Game game; // We going to change this to a singleton.

	// But look how clean this main is. Can we clean up our old Milestone 3 the same way?
	game.init("SDL Practice Exercise", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	while (game.running())
	{
		game.handleEvents();
		if (game.tick())
		{
			game.update();
			game.render();
		}
	}
	game.clean();
	return 0;
}