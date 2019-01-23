#include <chrono>
#include <iostream>
#include <string>
#include "Game.h"
#include "Classes.h"
#define ROWS 24
#define COLS 32
using namespace std;
using namespace chrono;

bool Game::Init(const char* title, int xpos, int ypos, int width,
				int height, int flags)
{
	// Attempt to initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init success" << endl;
		// Init the window.
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) // Window init success.
		{
			cout << "Window creation successful" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // Renderer init success.
			{
				cout << "renderer creation success" << endl;
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else
			{
				cout << "renderer init fail" << endl;
				return false; // Renderer init fail.
			}
		}
		else
		{
			cout << "window init fail" << endl;
			return false; // Window init fail.
		}
		if (IMG_Init(IMG_INIT_PNG))
		{
			cout << "image init success" << endl;
		}
	}
	else
	{
		cout << "SDL init fail" << endl;
		return false; // SDL init fail.
	}
	cout << "init success" << endl;
	m_bRunning = true; // Everything is okay, start the engine.
	return true;
}

bool Game::Running()
{
	return m_bRunning;
}

bool Game::Tick()
{
	auto duration = steady_clock::now().time_since_epoch();
	auto count = duration_cast<microseconds>(duration).count();
	int tick = 1000000 / m_iFPS;

	if (count % tick == 0) // Drops potential duplicate frames.
	{
		if (m_bGotTick == false)
		{
			m_bGotTick = true;
			cout << "Tick " << tick << " @ " << count << endl;
			return true;
		}
		return false;
	}
	else m_bGotTick = false;
	return false;
}

void Game::Update(Level& l, Player& p, int& c)
{
	if (p.m_bIsDead)
		return;
	// All of this collision checking code will need to change. Also it won't be in the Game::Update()
	if (m_bUpPressed && l.map[(p.m_rDst.y / 32) - 1][p.m_rDst.x / 32].m_bIsObstacle != true)
		p.m_rDst.y -= 32;
	if (m_bDownPressed && l.map[(p.m_rDst.y / 32) + 1][p.m_rDst.x / 32].m_bIsObstacle != true)
		p.m_rDst.y += 32;
	if (m_bLeftPressed && l.map[p.m_rDst.y / 32][(p.m_rDst.x / 32) - 1].m_bIsObstacle != true)
		p.m_rDst.x -= 32;
	if (m_bRightPressed && l.map[p.m_rDst.y / 32][(p.m_rDst.x / 32) + 1].m_bIsObstacle != true)
		p.m_rDst.x += 32;
	if (l.map[p.m_rDst.y / 32][p.m_rDst.x / 32].m_bIsHazard == true) // Player died.
	{
		p.m_bIsDead = true;
		p.m_rSrc.x = 32;
		return;
	}
	else // Check doors.
	{
		for (int i = 0; i < l.m_iNumDoors; i++)
		{
			if (p.m_rDst.x == l.doors[i].m_rDst.x && p.m_rDst.y == l.doors[i].m_rDst.y)
			{
				c = l.doors[i].m_iToLevel;
				p.m_rDst.x = l.doors[i].m_DestX * 32;
				p.m_rDst.y = l.doors[i].m_DestY * 32;
			}
		}
	}
}

void Game::HandleEvents()
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
		}
	}
}

void Game::Render(Level& l, Player& p)
{
	SDL_RenderClear(m_pRenderer); // Clear the screen to the draw color.
	for (int row = 0; row < ROWS; row++) // Drawing the tiles.
	{
		for (int col = 0; col < COLS; col++)
		{
			if (l.map[row][col].m_cOutput != ' ')
				SDL_RenderCopy(m_pRenderer, l.map[row][col].m_pTexture, &l.map[row][col].m_rSrc, &l.map[row][col].m_rDst);
		}
	}
	for (int i = 0; i < l.m_iNumDoors; i++) // Drawing the level doors.
		SDL_RenderCopy(l.doors[i].m_pRenderer, l.doors[i].m_pTexture, &l.doors[i].m_rSrc, &l.doors[i].m_rDst);
	SDL_RenderCopy(p.m_pRenderer, p.m_pTexture, &p.m_rSrc, &p.m_rDst); // Drawing the player.
	SDL_RenderPresent(m_pRenderer); // Draw anew.
}

void Game::Clean()
{
	cout << "cleaning game" << endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	IMG_Quit();
	SDL_Quit();
}