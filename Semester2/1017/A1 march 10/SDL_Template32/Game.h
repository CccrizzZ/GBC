#pragma once
#include <chrono>
#include <iostream>
#include "AudioManager.h"
#include "FSM.h"
#include "Classes.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
using namespace std;
using namespace chrono;

class Game {
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

	Game() { cout << "Constructing game..." << '\n'; }
public:
	~Game() {
		delete pFSM;
		delete pAM;
	}
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
	int GetMouseX() { return m_iMouseX; }
	int GetMouseY() { return m_iMouseY; }
	int GetLeftMouse() { return m_bLeftMouse; }
	void DoQuit() { m_bRunning = false; }
	bool KeyDown(SDL_Scancode c){
		if (m_iKeystates != nullptr)
		{
			if (m_iKeystates[c] == 1)
				return true;
			else
				return false;
		}
		return false;
	}




	bool Init(const char* title, int xpos, int ypos, int width,	int height, int flags) {
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
			if (m_pWindow != 0) {
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
				if (m_pRenderer == nullptr) {
					return false;
				}
				if (IMG_Init(IMG_INIT_PNG) != 0) {
					if (Mix_Init(MIX_INIT_MP3) != 0){
						Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 8192);
					}else{
						cout << "Audio init failed" << '\n';
						return false;
					}
				}else{
					cout << "Image init failed" << '\n';
					return false;
				}
			}else{
				cout << "Window init failed" << '\n';
				return false; // Window init fail.
			}
		}else {
			return false; // SDL init fail.
		}

		pAM = new AudioManager();
		pAM -> SetMusicVolume(15);
		pFSM = new StateMachine();
		// Go into title state
		pFSM -> ChangeState(new TitleState());
		m_iKeystates = SDL_GetKeyboardState(NULL);

		m_bRunning = true;
		return true;
	}


	// Returns running bool
	bool Running() {
		return m_bRunning;
	}


	bool Tick(){
		auto duration = steady_clock::now().time_since_epoch();
		auto count = duration_cast<microseconds>(duration).count();
		int tick = 1000000 / 60;
		if (count % tick == 0){
			if (m_bGotTick == false){
				m_bGotTick = true;
				return true;
			}
			return false;
		}
		else m_bGotTick = false;
		return false;
	}


	// Call StateMachine's Update
	void Update() {
		GetFSM()->Update();
	}


	void HandleEvents(){
		SDL_Event event;

		while (SDL_PollEvent(&event)){
			switch (event.type){
			case SDL_QUIT:
				m_bRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT){
					m_bLeftMouse = true;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT){
					m_bLeftMouse = false;
				}
				break;
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&m_iMouseX, &m_iMouseY);
				break;
			}
		}
	}


	// Call StateMachine's Render
	void Render(){
		GetFSM()->Render();
	}


	void Clean(){
		// Clean state
		GetFSM()->Clean();
		SDL_DestroyTexture(m_pText);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
		IMG_Quit();
		SDL_Quit();
	}
};
