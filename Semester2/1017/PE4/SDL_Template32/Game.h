#pragma once
#include <chrono>
#include <iostream>
#include <vector>
#include "Box.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
using namespace std;
using namespace chrono;

class Game {
private:
	// State check
	bool m_bRunning;
	bool m_bGotTick;
	int m_iMouseX, m_iMouseY;  // Variables to hold mouse positions.
	bool m_bMouseBtn[2] = { false, false };

	// SDL obj
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_pSurf;
	SDL_Texture* m_pText;

	// Vector contains all boxes
	vector<Box*> m_vBoxes;

	// Constructor
	Game() {
		cout << "Constructing game..." << endl;
	}
public:
	~Game() {} // Destructor.
	static Game* Instance(){ // This static method creates the static instance that can be accessed 'globally'
		static Game* instance = new Game(); // C++11 will prevent this line from running more than once. Magic statics.
		return instance;
	}


	// Variables
	bool m_bColorSet = false;




	// Functions
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
	SDL_Texture* GetTexture() { return m_pText; }
	int GetMouseX() { return m_iMouseX; }
	int GetMouseY() { return m_iMouseY; }
	bool GetMouseBtn(int i) { return m_bMouseBtn[i]; }

	bool Init(const char* title, int xpos, int ypos, int width,	int height, int flags, vector<Box*> b) {
		srand((unsigned)time(NULL));
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {// SDL init success.
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
			if (m_pWindow != 0) {// Window init success.
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
				if (m_pRenderer != nullptr) {// Renderer init success.
					if (IMG_Init(IMG_INIT_PNG) != 0){
						m_pSurf = IMG_Load(" ");
						m_pText = SDL_CreateTextureFromSurface(m_pRenderer, m_pSurf);
						SDL_FreeSurface(m_pSurf);
					}
					else return false;// Image init fail.
				}
				else return false; // Renderer init fail.
			}
			else return false; // Window init fail.
		}
		else return false; // SDL init fail.

		// Reserves space in box vector
		m_vBoxes.reserve(4);

		// Assign box vector created from XML
		m_vBoxes = b;

		m_bRunning = true; // Everything is okay, start the engine.
		return true;
	}


	bool Running() {
		return m_bRunning;
	}


	bool Tick() {

		auto duration = steady_clock::now().time_since_epoch();
		auto count = duration_cast<microseconds>(duration).count();

		int tick = 1000000 / 60;
		if (count % tick < 100){ // Gives margin of error to modulus.
			if (m_bGotTick == false) {// Drops potential duplicate frames.
				m_bGotTick = true;
				return true;
			}
			return false;
		}
		else m_bGotTick = false;
		return false;
	}


	void Update() {
		for (int i = 0; i < m_vBoxes.size(); i++) {
			m_vBoxes[i]->Update();
		}
	}


	void HandleEvents() { // SDL_GetKeyboardState is fine for spamming movement, but not one-shot key presses.
		SDL_Event event;

		while (SDL_PollEvent(&event)){
			switch (event.type){
			case SDL_QUIT:
				m_bRunning = false;
			break;

			// Keyboard Key Down
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == '\033') { // ESC button
					m_bRunning = false;
				}
			break;

			// Keyboard Key Up
			case SDL_KEYUP:
				if (event.key.keysym.sym == ' '){
					for (int i = 0; i < m_vBoxes.size(); i++){
						m_vBoxes[i]->Reset();
					}
				}

			// Mouse Button Down
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT){
					m_bMouseBtn[0] = true;
				}
				if (event.button.button == SDL_BUTTON_RIGHT){
					m_bMouseBtn[1] = true;
				}
			break;

			// Mouse Button Up
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT){
					m_bMouseBtn[0] = false;
				}
				if (event.button.button == SDL_BUTTON_RIGHT){
					m_bMouseBtn[1] = false;
					m_bColorSet = false;
				}
			break;

			// Mouse Motion
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&m_iMouseX, &m_iMouseY);
			break;
			}
		}
	}

	void Render() {
		// Set the background to #000
		SDL_SetRenderDrawColor(GetRenderer(), 0, 0, 0, 255);
		// Clear the canvas
		SDL_RenderClear(GetRenderer());

		// Render all boxes
		for (int i = 0; i < m_vBoxes.size(); i++) {
			m_vBoxes[i]->Render();
		}

		// Submit all changes made above
		SDL_RenderPresent(GetRenderer());
	}

	void Clean(){
		// Delete all boxes and point the pointer to nullptr
		for (int i = 0; i < m_vBoxes.size(); i++){
			delete m_vBoxes[i];
			m_vBoxes[i] = nullptr;
		}
		m_vBoxes.clear();
		SDL_DestroyTexture(m_pText);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
		IMG_Quit();
		SDL_Quit();
	}
};
