#pragma once
#include <chrono>
#include <iostream>
#include "AudioManager.h"
#include "FSM.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
using namespace std;
using namespace chrono;

class Game{
private:
	bool m_bRunning;
	bool m_bGotTick;
	bool m_bLeftMouse = false;
	const Uint8* m_iKeystates;
	int m_iMouseX, m_iMouseY;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_pSurf;
	SDL_Texture* m_pText;
	StateMachine* pFSM;
	AudioManager* pAM;
	Game();
public:
	~Game();

	// Global instance
	static Game* Instance() {
		static Game* instance = new Game();
		return instance;
	}

	// Getters.
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
	SDL_Texture* GetTexture() { return m_pText; }
	StateMachine* GetFSM() { return pFSM; }
	AudioManager* GetAM() { return pAM; }

	// Returns running bool
	bool Running() { return m_bRunning; }
	// Returns mouse x and y value
	int GetMouseX() { return m_iMouseX; }
	int GetMouseY() { return m_iMouseY; }
	// Returns mouse button bool
	int GetLeftMouse() { return m_bLeftMouse; }
	// Quit Game
	void DoQuit() { m_bRunning = false; }
	// SDL key check
	bool KeyDown(SDL_Scancode c);
	// Initialization
	bool Init(const char* title, int xpos, int ypos, int width,	int height, int flags);
	bool Tick();

	// Call StateMachine's Update
	void Update() { GetFSM()->Update(); }
	// HandleEvents
	void HandleEvents();


	// Call StateMachine's Render
	void Render(){ GetFSM()->Render(); }


	void Clean();

};
