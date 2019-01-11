#pragma once
#include <chrono>
#include "SDL.h"
using namespace std;
using namespace chrono;

class Game
{
private:
	bool m_bClicked = false;
	bool m_bRunning;
	bool m_bGotTick;
	// Next the four bools for input.
	bool m_bUpPressed;
	bool m_bDownPressed;
	bool m_bLeftPressed;
	bool m_bRightPressed;
	int m_iSpeed = 4;
	SDL_Color m_cNorm = { 255, 255, 255, 255 };
	SDL_Color m_cCol = m_cNorm;
	SDL_Color m_cClicked = { 255, 0, 0, 255 };
	SDL_Rect m_rActor;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) // SDL init success.
		{
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
			if (m_pWindow != 0) // Window init success.
			{
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
				if (m_pRenderer == nullptr) // Renderer init fail.
					return false;
			}
			else
			{
				cout << "window init fail" << endl;
				return false; // Window init fail.
			}
		}
		else return false; // SDL init fail.
		m_rActor.w = m_rActor.h = 64;
		m_rActor.x = width / 2;
		m_rActor.y = height / 2;
		m_bRunning = true; // Everything is okay, start the engine.
		return true;
	}
	bool running() { return m_bRunning; };
	bool tick()
	{
		auto duration = steady_clock::now().time_since_epoch();
		auto count = duration_cast<microseconds>(duration).count();
		int tick = 1000000 / 30;

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
	void update()
	{
		if (m_bUpPressed)
			m_rActor.y -= m_iSpeed;
		if (m_bDownPressed)
			m_rActor.y += m_iSpeed;
		if (m_bLeftPressed)
			m_rActor.x -= m_iSpeed;;
		if (m_bRightPressed)
			m_rActor.x += m_iSpeed;;
	}
	void handleEvents()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				m_bRunning = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case 'w':
				case 'W':
					if (!m_bUpPressed)
						m_bUpPressed = true;
					break;
				case 's':
				case 'S':
					if (!m_bDownPressed)
						m_bDownPressed = true;
					break;
				case 'a':
				case 'A':
					if (!m_bLeftPressed)
						m_bLeftPressed = true;
					break;
				case 'd':
				case 'D':
					if (!m_bRightPressed)
						m_bRightPressed = true;
					break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				case 'w':
				case 'W':
					m_bUpPressed = false;
					break;
				case 's':
				case 'S':
					m_bDownPressed = false;
					break;
				case 'a':
				case 'A':
					m_bLeftPressed = false;
					break;
				case 'd':
				case 'D':
					m_bRightPressed = false;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				m_bClicked = !m_bClicked; // Toggling the click state bool.
				// Then set the color. Do I really need three SDL_Colors? How else could I do it?
				if (m_bClicked) m_cCol = m_cClicked;
				else m_cCol = m_cNorm;
				break;
			}
		}
	}
	void render()
	{
		// Set the color of the screen.
		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
		// Clear the screen with the draw color.
		SDL_RenderClear(m_pRenderer);
		// Set a new draw color.
		SDL_SetRenderDrawColor(m_pRenderer, m_cCol.r, m_cCol.g, m_cCol.b, m_cCol.a);
		// Now fill a rectangle on the screen with the new draw color.
		SDL_RenderFillRect(m_pRenderer, &m_rActor);
		// Flip the buffers and send changes to the screen.
		SDL_RenderPresent(m_pRenderer);
	}
	void clean()
	{
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
		SDL_Quit();
	}
};