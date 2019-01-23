#include <iostream>
#include <fstream>
#include "Game.h"
#include "Classes.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
using namespace std;
#define ROWS 24
#define COLS 32

// I don't want to see BuildMap here. Move it to the appropriate class eventually.
bool BuildMap(Level& l, const char* n, SDL_Renderer* r, SDL_Texture* t)
{
	ifstream inFile(n);
	char temp;
	if (inFile.is_open())
	{
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				inFile >> temp;
				l.map[row][col].SetBGTile( (temp == '*' ? ' ' : temp) );
				l.map[row][col].SetImage(r, t);
				l.map[row][col].m_rDst = { col*32, row*32, 32, 32 };
				if (temp == 'Q')
				{
					int tl, px, py;
					inFile >> tl >> px >> py;
					l.AddDoor(col, row, tl, px, py, r, t);
				}
			}
		}
		inFile.close();
		return 0;
	}
	return 1;
}

int main(int argc, char* args[]){
	/* Note: I want a squeaky-clean main like my state machine example or you'll lose marks. Move the
	   appropriate code into their respective classes. You will have to figure out the best place to
	   put what where. Most of it can go into the engine but think of the best class to put the level building stuff into. */



	Game game; // This needs to be gone after you create the singleton.
	game.Init("GAME1017 Assignment 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);
	Level levels[5] = { Level(3), Level(1), Level(1), Level(2), Level(1) };
	const char* levelNames[5] = { "Level1.txt", "Level2.txt", "Level3.txt", "Level4.txt", "Level5.txt" };
	// The below lines should be moved to the game engine class.
	SDL_Surface* tileSurf = IMG_Load("Tiles.png");
	SDL_Texture* tileText = SDL_CreateTextureFromSurface(game.GetRenderer(), tileSurf);
	SDL_Surface* playerSurf = IMG_Load("Player.png");
	SDL_Texture* playerText = SDL_CreateTextureFromSurface(game.GetRenderer(), playerSurf);

	for (int i = 0; i < 5; i++){  // This should be moved.
		if (BuildMap(levels[i], levelNames[i], game.GetRenderer(), tileText) == 1){
			return 1;
		}
	}

	int currLevel = 0;
	Player player(COLS / 2, ROWS / 2, game.GetRenderer(), playerText);
	while (game.Running()){
		game.HandleEvents();
		if (game.Tick()){ // You won't need parameters once you have a globally-accessible game instance and state machine. Trust me.
			game.Update(levels[currLevel], player, currLevel);
			game.Render(levels[currLevel], player);
		}
	}

	// Shut down the game
	SDL_FreeSurface(tileSurf); // Move these to the Clean method of the engine.
	SDL_DestroyTexture(tileText);
	SDL_FreeSurface(playerSurf);
	SDL_DestroyTexture(playerText);
	game.Clean();
	//system("pause");
	return 0;
}
