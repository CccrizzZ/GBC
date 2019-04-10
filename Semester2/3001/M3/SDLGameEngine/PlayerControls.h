#pragma once
#include "Behaviour.h"
#include "Bullet.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
using namespace std;

class PlayerControls :	public Behaviour {
public:
	PlayerControls();
	~PlayerControls();

	// Global instance
	static PlayerControls* Instance() {
		static PlayerControls* instance = new PlayerControls();
		return instance;
	}

	// Player speed
	float speed;

	TTF_Font* scoreFont;
	SDL_Color scoreColor = {255,255,255,255};
	SDL_Surface* scoreSurf;
	SDL_Texture* scoreText;
	SDL_Rect sRect;
	string temp;

	// Player final score
	int finScore;
	int getFinScore();

	// Update function
	void Update();
};
