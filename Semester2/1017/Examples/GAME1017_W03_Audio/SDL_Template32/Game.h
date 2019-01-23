#pragma once
#include <chrono>
#include <iostream>
#include <vector>
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

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Surface* m_pSurf;
	SDL_Texture* m_pText;

	int m_iVol, m_iLPan, m_iRPan;
	vector<Mix_Music*> m_vMusic;
	vector<Mix_Chunk*> m_vSounds;

	Game() { cout << "Constructing game..." << endl; }
public:
	~Game() {} // Destructor.
	static Game* Instance() // This static method creates the static instance that can be accessed 'globally'
	{
		static Game* instance = new Game(); // C++11 will prevent this line from running more than once. Magic statics.
		return instance;
	}
	// Now a trio of getters.
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
	SDL_Texture* GetTexture() { return m_pText; }
	
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
							Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 8192); // Good for most games.
							Mix_AllocateChannels(16);
							// Load the tracks into the Mix_Music vector.
							m_vMusic.reserve(3);
							m_vMusic.push_back(Mix_LoadMUS("Aud/Thundercats.mp3"));
							m_vMusic.push_back(Mix_LoadMUS("Aud/Turtles.mp3"));
							m_vMusic.push_back(Mix_LoadMUS("Aud/MASK.mp3"));
							// Load the chunks into the Mix_Chunk vector.
							m_vSounds.reserve(5);					
							m_vSounds.push_back(Mix_LoadWAV("Aud/laser.wav"));
							m_vSounds.push_back(Mix_LoadWAV("Aud/jump.wav"));
							m_vSounds.push_back(Mix_LoadWAV("Aud/boom.wav"));
							m_vSounds.push_back(Mix_LoadWAV("Aud/death.wav"));
							m_vSounds.push_back(Mix_LoadWAV("Aud/power.wav"));
							/* By the way, you should check to see if any of these loads are failing and
							   you can use Mix_GetError() to print out the error message. Wavs can be finicky.*/
						}
						else return false;					
					}
					else return false;// Image init fail.
				}
				else return false; // Renderer init fail.
			}
			else return false; // Window init fail.
		}
		else return false; // SDL init fail.
		Mix_PlayMusic(m_vMusic[0], -1); // Play. -1 = looping.
		m_iVol = 10;
		Mix_VolumeMusic(m_iVol);
		m_iLPan = m_iRPan = 255;
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
		// Nothing needed here for this example.
	}
	void HandleEvents() // SDL_GetKeyboardState is fine for spamming movement, but not one-shot key presses. 
	{
		SDL_Event event;

		while (SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
			case SDL_QUIT:
				m_bRunning = false;
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				case '1':
					Mix_PlayMusic(m_vMusic[0], -1);
					break;
				case '2':
					Mix_PlayMusic(m_vMusic[1], -1); 
					break;
				case '3':
					Mix_PlayMusic(m_vMusic[2], -1);
					break;
				case '4':
					Mix_PlayChannel(-1, m_vSounds[0], 0);
					break;
				case '5':
					Mix_PlayChannel(-1, m_vSounds[1], 0);
					break;
				case '6':
					Mix_PlayChannel(-1, m_vSounds[2], 0);
					break;
				case '7':
					Mix_PlayChannel(-1, m_vSounds[3], 0);
					break;
				case '8':
					Mix_PlayChannel(-1, m_vSounds[4], 0);
					break;
				case 'p':
				case 'P':
					if (Mix_PausedMusic() == 1)
						Mix_ResumeMusic();
					else
						Mix_PauseMusic();
					break;
				case 'r':
				case 'R':
					Mix_RewindMusic();
					break;
				case '-':
					m_iVol -= 2;
					if (m_iVol < 0)
						m_iVol = 0;
					Mix_VolumeMusic(m_iVol);
					break;
				case '=': // or '+' for our purposes.
					m_iVol += 2;
					if (m_iVol > MIX_MAX_VOLUME)
						m_iVol = MIX_MAX_VOLUME; // 128.
					Mix_VolumeMusic(m_iVol);
					break;
				// No no, we're not done yet. Now for Peter Panning!
				case '\\': // Reset panning.
					m_iLPan = 255;
					m_iRPan = 255;
					// MIX_CHANNEL_POST sets the pan for the whole sound stream, i.e. all channels.
					Mix_SetPanning(MIX_CHANNEL_POST, m_iLPan, m_iRPan);
					break;
				case '[': // Left panning.
					if (m_iLPan < 255)
					{
						m_iLPan += 16;
						if (m_iLPan > 255) m_iLPan = 255;
					}
					else if (m_iRPan > 0)
					{
						m_iRPan -= 16;
						if (m_iRPan < 0) m_iRPan = 0;
					}
					Mix_SetPanning(MIX_CHANNEL_POST, m_iLPan, m_iRPan);
					break;
				case ']': // Right panning.
					if (m_iRPan < 255)
					{
						m_iRPan += 16;
						if (m_iRPan > 255) m_iRPan = 255;
					}
					else if (m_iLPan > 0)
					{
						m_iLPan -= 16;
						if (m_iLPan < 0) m_iLPan = 0;
					}
					Mix_SetPanning(MIX_CHANNEL_POST, m_iLPan, m_iRPan);
					break;
				}
				break;
			}
		}
	}
	void Render()
	{
		// This is an audio example and I guess we don't need this, but whatever.
		SDL_SetRenderDrawColor(GetRenderer(), 0, m_iLPan, m_iRPan, 255);
		SDL_RenderClear(GetRenderer());
		SDL_RenderPresent(GetRenderer());
	}
	void Clean()
	{
		SDL_DestroyTexture(m_pText);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
		for (int i = 0; i < m_vSounds.size(); i++)
			Mix_FreeChunk(m_vSounds[i]);
		m_vSounds.clear();
		for (int i = 0; i < m_vMusic.size(); i++)
			Mix_FreeMusic(m_vMusic[i]);	
		m_vMusic.clear();
		Mix_CloseAudio();
		Mix_Quit();
		IMG_Quit();
		SDL_Quit();
	}
};