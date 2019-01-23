#pragma once
#include <chrono>
#include <iostream>
#include "AudioManager.h"
#include "FSM.h" // Needed for the StateMachine class.
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
using namespace std;
using namespace chrono;

class Game
{
private:
	bool m_bRunning;
	bool m_bGotTick;
	const Uint8* m_iKeystates; // Pointer to an 'array' of key states with values of 1 or 0.
							   // The const just prevents us from changing the array.
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_pSurf;
	SDL_Texture* m_pText;
	StateMachine* m_pFSM; // Pointer to the StateMachine object created dynamically.
	AudioManager* m_pAM;

	Game() { cout << "Constructing game..." << endl; }
public:
	~Game() { delete m_pFSM; } // Destructor.
	static Game* Instance() // This static method creates the static instance that can be accessed 'globally'
	{
		static Game* instance = new Game(); // C++11 will prevent this line from running more than once. Magic statics.
		return instance;
	}
	// Now a trio of getters.
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
	SDL_Texture* GetTexture() { return m_pText; }
	StateMachine* GetFSM() { return m_pFSM; }
	AudioManager* GetAM() { return m_pAM; }
	bool KeyDown(SDL_Scancode c) // This tests the scancode parameter against the keystates. Scancode is SDL2.
	{
		if (m_iKeystates != nullptr)
		{
			if (m_iKeystates[c] == 1)
				return true;
			else
				return false;
		}
		return false;
	}
	bool Init(const char* title, int xpos, int ypos, int width,	int height, int flags)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // SDL init success.
		{
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
			if (m_pWindow != 0) // Window init success.
			{
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
				if (m_pRenderer != nullptr) // Renderer init success.
				{
					if (IMG_Init(IMG_INIT_PNG) != 0)
					{
						m_pSurf = IMG_Load(" ");
						m_pText = SDL_CreateTextureFromSurface(m_pRenderer, m_pSurf);
						SDL_FreeSurface(m_pSurf);
						if (Mix_Init(MIX_INIT_MP3) != 0) // Mixer init success.
						{
							Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 8192);
						}
						else return false; // Mixer init fail.
					}
					else return false; // Image init fail.
				}
				else return false; // Renderer init fail.
			}
			else return false; // Window init fail.
		}
		else return false; // SDL init fail.
		m_pAM = new AudioManager(); // Creates the audio manager object.
		m_pAM->SetMusicVolume(10); // Set low volume so we can hear sfx.
		m_pFSM = new StateMachine(); // Creates the state machine object/instance.
		m_pFSM->ChangeState(new TitleState()); // Invoking the ChangeState method to set the initial state, Title.
		m_iKeystates = SDL_GetKeyboardState(NULL); // We only need to put this here. Why?
		m_bRunning = true; // Everything is okay, start the engine.
		return true;
	}
	bool Running() { return m_bRunning; };
	bool Tick()
	{
		auto duration = steady_clock::now().time_since_epoch();
		auto count = duration_cast<microseconds>(duration).count();
		int tick = 1000000 / 60;

		if (count % tick == 0) // Drops potential duplicate frames.
		{
			if (m_bGotTick == false)
			{
				m_bGotTick = true;
				return true;
			}
			return false;
		}
		else m_bGotTick = false;
		return false;
	}
	void Update()
	{
		GetFSM()->Update(); // Invokes the update of the state machine.
	}
	void HandleEvents() // Significantly shorter handle events. 
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) // SDL_PollEvent invokes SDL_PumpEvents() which we need to refresh the keyboard states.
		{
			switch (event.type)
			{
			case SDL_QUIT:
				m_bRunning = false;
				break;
			case SDL_KEYDOWN:
				//m_iKeystates = SDL_GetKeyboardState(NULL); // Why don't we need this?
				break;
			case SDL_KEYUP:
				//m_iKeystates = SDL_GetKeyboardState(NULL); // Why don't we need this?
				break;
			}
		}
	}
	void Render()
	{
		GetFSM()->Render(); // Invokes the render of the state machine.
	}
	void Clean()
	{
		GetFSM()->Clean();
		SDL_DestroyTexture(m_pText);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
		IMG_Quit();
		SDL_Quit();
	}
};