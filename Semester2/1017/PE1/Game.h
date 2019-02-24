#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
using namespace std;
using namespace chrono;

// Game Class
class Game {
public:
	// Variable
	int count=0;

	// Box
	int randN = rand() % 256;
	uint8_t randC = static_cast<uint8_t>(randN);

	int bSpeed = 5;
	SDL_Color NormC = { 255, 255, 255, 255 };
	SDL_Color Col = NormC;
	SDL_Color ClickedC = { randC, randC, randC, 255 };
	SDL_Rect Box;

	// State Check
	bool isRunning;
	bool gotTick;

	// Key Check
	bool MouseClick;
	bool UpPressed;
	bool DownPressed;
	bool LeftPressed;
	bool RightPressed;
	bool SpacePressed;

	// SDL shit
	SDL_Window* Window;
	SDL_Renderer* Renderer;

	// Functions
	Game (){};
	~Game (){};

	// Initialization function
	bool init(const char* title, int xpos, int ypos, int width,	int height, int flags){
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)	{
			// initialize the window if SDL initialized.
			cout << "SDL init success" << endl;
			Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
			// If window created
			if (Window) {
				cout << "Window creation successful" << endl;
				// Create renderer
				Renderer = SDL_CreateRenderer(Window, -1, 0);
				// If renderer created
				if (Renderer) {
					cout << "Renderer creation successful" << endl;
				} else {
					// Renderer init failed.
					cout << "Renderer init failed" << endl;
					return false;
				}
			} else {
				// Window init fail.
				cout << "Window init failed" << endl;
				return false;
			}
		} else {
			// SDL init fail.
			cout << "SDL init failed" << endl;
			return false;
		}


		// Everything is okay, start the engine.
		cout << "Initialization successful" << endl;
		cout << "Press \"ESC\" to Quit Game" << '\n';

		// Set up the Box
		Box.w = Box.h = 64;
		Box.x = 1024 / 2;
		Box.y = 768 / 2;

		// Set game running to true
		isRunning = true;
		return true;
	};


	// Handle Keyboard events
	void handleEvents(){
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			// Switch event's type
			switch (event.type){
			// ON KEY DOWN
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
					case 'w':
					case 'W':
						if (!UpPressed){
							UpPressed = true;
						}
					break;
					case 's':
					case 'S':
						if (!DownPressed){
							DownPressed = true;
						}
					break;
					case 'a':
					case 'A':
						if (!LeftPressed){
							LeftPressed = true;
						}
					break;
					case 'd':
					case 'D':
						if (!RightPressed){
							RightPressed = true;
						}
					break;
					case ' ':
						if (!SpacePressed){
							SpacePressed = true;
						}
					break;
					case '\033': // ESC button
						isRunning = false;
					break;
				}
				break;

				// ON KEY UP
				case SDL_KEYUP:
					switch (event.key.keysym.sym){
						case 'w':
						case 'W':
							UpPressed = false;
						break;
						case 's':
						case 'S':
							DownPressed = false;
						break;
						case 'a':
						case 'A':
							LeftPressed = false;
						break;
						case 'd':
						case 'D':
							RightPressed = false;
						break;
						case ' ':
							SpacePressed = false;
						break;
					}

				// Mouse Click
				case SDL_MOUSEBUTTONDOWN:
					if (event.button.button == SDL_BUTTON_LEFT){
						MouseClick = !MouseClick;
						if (MouseClick) {
							Col = ClickedC;
						}else{
							Col = NormC;
						}
					}
				break;
			}
		}
	};


	// Render function
	void render(){
		// Set the Background color to #000
		SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
		// Clear the screen to the draw color.
		SDL_RenderClear(Renderer);
		// Set box color
		SDL_SetRenderDrawColor(Renderer, Col.r, Col.g, Col.b, Col.a);
		// Draw the box
		SDL_RenderFillRect(Renderer, &Box);




		// Submit the Changes Made Above
		SDL_RenderPresent(Renderer);
	};


	// Return True if game is running
	bool running(){ return isRunning; }

	// Game ticking function
	bool Tick() {
		auto duration = steady_clock::now().time_since_epoch();
		auto count = duration_cast<microseconds>(duration).count();

		int tick = 1000000 / 60;

		// Gives margin of error to modulus.
		if (count % tick < 100){
			// Drops potential duplicate frames.
			if (gotTick == false) {
				gotTick = true;
				return true;
			}
			return false;
		}else {
			gotTick = false;
		}
		return false;
	}

	// Update function
	void update(){
		if (UpPressed) {
			Box.y -= bSpeed;
		}else if (DownPressed) {
			Box.y += bSpeed;
		}else if (LeftPressed) {
			Box.x -= bSpeed;
		}else if (RightPressed) {
			Box.x += bSpeed;
		}
		count++;
		cout << count << '\n';
	};

	// Cleaning function
	void clean(){
		cout << "Cleaning up game......" << endl;
		SDL_DestroyRenderer(Renderer);
		SDL_DestroyWindow(Window);
		IMG_Quit();
		SDL_Quit();
	};
};
