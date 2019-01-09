#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Game.cpp"
using namespace std;


void Game() {
	SDL_Rect box;
	box.h = (1024 / 2);
	box.w = (768 / 2);
	box.x = 200;
	box.y = 100;

}



class Game {
private:
	bool m_bClicked = false;
	bool m_bRunning;
	bool m_bGottick;
	bool m_bUpPressed;
	bool m_bDownPressed;
	bool m_bLeftPressed;
	bool m_bRightPressed;

	int iSpeed = 4;
	SDL_Color m_cNorm = { 255,255,255,255 };
	SDL_Color m_cCol = m_cNorm;
	SDL_Rect m_rActor;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flag) {
		
		// If SDL init success
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		}else {

		}
		
	};
	
	void render() {

	};

	void clean() {

	};
	
};


int main(int argc, char* args[])
{
	SDL_Window* window;
	SDL_Surface* surface;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"MySDL",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1024,
		768,
		0
	);


	//Get window surface
	surface = SDL_GetWindowSurface(window);
	//Fill the surface with #ff0066
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface -> format, 0xFF, 0x00, 0x66));
	//Update the surface
	SDL_UpdateWindowSurface(window);
	


	//Wait two thousand milliseconds
	SDL_Delay(5000);

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}