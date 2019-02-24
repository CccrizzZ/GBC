#include <iostream>
#include <chrono>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;
using namespace chrono;

// Game Class
class Game {
private:
	Game(){
		cout << "Game Constructed..." << '\n';
	}
public:
	// static
	static Game* Instance(){
		static Game* instance = new Game();
		return instance;
	};


	// Pen
	int pSize = 64;
	int pSpeed = 5;
	SDL_Rect Pen;
	SDL_Color PenColor = { 255, 255, 255, 255 };
	SDL_Texture* PenTexture;
	// SDL_Surface* PenSurface = IMG_Load()

	// Colors
	SDL_Color Red = { 255, 0, 0, 255 };
	SDL_Color Green = { 0, 255, 0, 255 };
	SDL_Color Blue = { 0, 0, 255, 255 };
	SDL_Color Yellow = { 255, 255, 0, 255 };
	SDL_Color Magenta = { 255, 0, 255, 255 };
	SDL_Color Cyan = { 0, 255, 255, 255 };
	SDL_Color White = { 255, 255, 255, 255 };
	SDL_Color Black = { 0, 0, 0, 255 };          // Erasing color

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
	const Uint8* Keystates;

	// SDL Window
	SDL_Window* Window;
	SDL_Renderer* Renderer;


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
		cout << "Scroll Mouse Wheel To Change The Size Of Pen" << '\n';
		cout << "Press Number Key 1-7 to Change The Color Of Pen" << '\n';
		cout << "Press \"ESC\" to Quit Game" << '\n';

		// Set up the pen
		Pen.w = Pen.h = pSize;
		Pen.x = 1024 / 2;
		Pen.y = 768 / 2;


		PenTexture = IMG_LoadTexture(Renderer, "Brush.png");
		// Set game running to true
		isRunning = true;
		return true;
	}




	// Handle Keyboard events
	void handleEvents(){
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			// Switch event's type
			switch (event.type){
			// ON KEY DOWN
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){

					// Number keys
					case '1':
						PenColor = Red;
					break;
					case '2':
						PenColor = Green;
					break;
					case '3':
						PenColor = Blue;
					break;
					case '4':
						PenColor = Yellow;
					break;
					case '5':
						PenColor = Magenta;
					break;
					case '6':
						PenColor = Cyan;
					break;
					case '7':
						PenColor = White;
					break;
					case '8':
					  PenColor = Black;
					break;

					// Movement
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

					// ESC button
					case '\033':
						isRunning = false;
					break;
				}
				break;

				// ON KEY UP
				case SDL_KEYUP:
					switch (event.key.keysym.sym) {
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

				// Mouse Wheel
				case SDL_MOUSEWHEEL:
					if(event.wheel.y > 0) { // scroll up
						pSize+=2;
					} else if(event.wheel.y < 0) { // scroll down
						pSize-=2;
					}
				break;
			}
		}
	}




	// Update function
	void update() {

		Pen.w = Pen.h = pSize;
		// Pen movement
		if (UpPressed && Pen.y - pSpeed > 0) {
			Pen.y -= pSpeed;
		}else if (DownPressed && Pen.y + pSpeed < 768-64) {
			Pen.y += pSpeed;
		}else if (LeftPressed && Pen.x - pSpeed > 0) {
			Pen.x -= pSpeed;
		}else if (RightPressed && Pen.x + pSpeed < 1024-64) {
			Pen.x += pSpeed;
		}

		// cout << "X: " << Pen.x << "|"  << "Y: " << Pen.y << '\n';

	}


	// Render function
	void render() {

		// If space bar is pressed clear the canvas
		if (SpacePressed) {
			// Set the Background color to #000
			SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);

			// Clear the screen with the draw color.
			SDL_RenderClear(Renderer);
		}

		// Set Pen Color
		SDL_SetRenderDrawColor(Renderer, PenColor.r, PenColor.g, PenColor.b, PenColor.a);

		// Now fill a rectangle on the screen with the new draw color.
		SDL_RenderFillRect(Renderer, &Pen);

	  // Submit the Changes Made Above
	  SDL_RenderPresent(Renderer);
	}


	// Return True if game is running
	bool running() {
		return isRunning;
	}

	// Return SDL renderer
	SDL_Renderer* GetRenderer() {
		return Renderer;
	}

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




	// Cleaning function
	void clean() {
		cout << "Cleaning up game......" << endl;
		SDL_DestroyTexture(PenTexture);
		SDL_DestroyRenderer(Renderer);
		SDL_DestroyWindow(Window);
		IMG_Quit();
		SDL_Quit();
	}
};
