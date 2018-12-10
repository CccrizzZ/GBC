#define SDL_MAIN_HANDLED
#include "Game.h"
#include <SDL.h>
#include <iostream>
#include <fstream>
using namespace std;

// There is BUGS!!!!!!!


bool BuildMap(Level& l, string n, SDL_Renderer* r, SDL_Texture* t);

int main() {
	cout << "Sorry I can't get collision with obstacles or hazards working" << '\n';
	// Game Player Tiles
	Game m3;


	// SDL initialization
	m3.init(
		"Mildestoned3", // window title
		SDL_WINDOWPOS_CENTERED, // x position
		SDL_WINDOWPOS_CENTERED, // y position
		1024, // width
		768, // height
		0 // flag for disply option
	);

	// SDL tiles & textures pointers
	SDL_Surface* tileSurf = IMG_Load("Tile.png");
	SDL_Texture* tileText = SDL_CreateTextureFromSurface(m3.GetRenderer(), tileSurf);
	SDL_Surface* playerSurf = IMG_Load("Player.png");
	SDL_Texture* playerText = SDL_CreateTextureFromSurface(m3.GetRenderer(),playerSurf);

	// File path
	string files[3] = {
		"Level_Home.txt",
		"Level_Town.txt"
	};

	// Array for all levels in the game
	Level Levels[3] = {};

	// Current level var
	int currLevel = 0;

	// Player
	Player p(COLS/2, ROWS/2, m3.GetRenderer(), playerText);



	for (int i = 0; i < (sizeof(files)/sizeof(files[0]))-1; i++) {
		BuildMap(Levels[i],files[i], m3.GetRenderer(), tileText);
	}

	// Game Loop
	while (m3.running()) {
		m3.handleEvents(p);
		if (m3.tick()) {
			m3.update(Levels[currLevel], p, currLevel, m3.GetRenderer(), playerText);
			m3.render(Levels[currLevel], p);
		}
	}

	m3.clean();
	system("pause");
	return 0;
}









// BuildMap function (n is file path)
bool BuildMap(Level& l, string n, SDL_Renderer* r, SDL_Texture* t){
	// Open the .txt file
	ifstream inFile(n);
	// If the file is opened
	if (inFile.is_open()) {
		// Traverse the map array in level object
		for (int row = 0; row < 24; row++) {
			for (int col = 0; col < 32; col++) {
				// put all char in the text file into the 2D array
				inFile >> l.map[row][col].value;
				// Set up the map
				if (l.map[row][col].value == '.'){ // Floor-Home
					l.map[row][col].m_rSrc = {64, 32, 32, 32};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = {col*32, row*32, 32, 32};
				}else if (l.map[row][col].value == '+') { // Wall-Home
					l.map[row][col].m_rSrc = {128, 32, 32, 32};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = {col*32, row*32, 32, 32};
					l.map[row][col].m_isObstacle = true;
				}else if (l.map[row][col].value == 'D') { // TownDoor-Home
					l.map[row][col].m_rSrc = {192, 32, 32, 32};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = l.doors[0].m_rDst = {col*32, row*32, 32, 32};
					l.map[row][col].m_isDoor = true;
					l.AddDoor(col, row, r, t, 1, 8*32, 10*32);
				}else if (l.map[row][col].value == '~') { // Water-Town
					l.map[row][col].m_rSrc = {192, 0, 32, 32};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = {col*32, row*32, 32, 32};
					l.map[row][col].m_isHazard = true;
				}else if (l.map[row][col].value == ',') { // Floor-Town
					l.map[row][col].m_rSrc = {0, 0, 32, 32};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = {col*32, row*32, 32, 32};
				}else if (l.map[row][col].value == '-') { // Wall-Town
					l.map[row][col].m_rSrc = {32, 32, 32,32};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = {col*32, row*32, 32, 32};
					l.map[row][col].m_isObstacle = true;
				}else if (l.map[row][col].value == 'W') { // Bush-Town
					l.map[row][col].m_rSrc = {0, 32, 32, 64};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = {col*32, row*32, 32, 32};
				}else if (l.map[row][col].value == 'H') { // HomeDoor-Town
					l.map[row][col].m_rSrc = {192, 32, 32, 32};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = l.doors[0].m_rDst = {col*32, row*32, 32, 32};
					l.map[row][col].m_isDoor = true;
					l.AddDoor(col, row, r,t, 0, 8*32, 11*32);
				}else if (l.map[row][col].value == '=') { // Stairs??????-Town
					l.map[row][col].m_rSrc = {160, 32, 32, 32};
					l.map[row][col].SetImage(r,t);
					l.map[row][col].m_rDst = {col*32, row*32, 32, 32};
				}
			}
		}
		cout << "Map build!" << '\n';
		return true;
	}else{
		// If the file is missing
		cout << "Failed to build map" << '\n';
		return false;
	}
}
