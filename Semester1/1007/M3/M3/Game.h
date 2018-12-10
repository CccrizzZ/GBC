#include <iostream>
#include <chrono>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#define FPS 60 // Frame per second
#define SIZE 64 // Player icon size
#define COLS 32 // Map X
#define ROWS 24 // Map Y
using namespace std;
using namespace chrono;

// Sprite class
class Sprite{
public:
	char m_cOutput;
	SDL_Rect m_rSrc;  // The source rectangle
	SDL_Rect m_rDst; // The destination
	SDL_Texture* m_pTexture;
	SDL_Renderer* m_pRenderer;

	Sprite(){};
	~Sprite(){};


	void SetX(int x) {
		m_rDst.x = x*32;
	}

	void SetY(int y) {
		m_rDst.y = y*32;
	}

	void SetImage(SDL_Renderer* r, SDL_Texture* t){
		m_pRenderer = r;
		m_pTexture = t;
	}

	const SDL_Rect* GetSrc(){
		return &m_rSrc;
	}
	const SDL_Rect* GetDst(){
		return &m_rDst;
	}

};



// LOTile class
class LOTile: public Sprite{
public:
	LOTile(){};
	LOTile(int x, int y){
		SetX(x);
		SetY(y);
	}
};



// BGTile class
class BGTile: public Sprite{
public:
  char value;
  bool m_isObstacle;
  bool m_isHazard;
  bool m_isDoor;


  bool isObstacle(){
    return m_isObstacle;
  }

  bool isHazard(){
    return m_isHazard;
  }

  bool isDoor(){
    return m_isDoor;
  }
};



// Player class
class Player: public LOTile{
private:
	int m_iSpeed = 4;
public:
	Player(int x, int y, SDL_Renderer* r, SDL_Texture* t): LOTile(x, y){
		m_rSrc = {0,0,32,32};
		SetImage(r,t);
		m_rDst.w = m_rDst.h = 32;
	}

	void MoveX(int x) {
		m_rDst.x += x*m_iSpeed;
	}

	void MoveY(int y) {
		m_rDst.y += y*m_iSpeed;
	}

	void die(SDL_Renderer* r, SDL_Texture* t){
		m_iSpeed = 0;
		m_rSrc = {32,0,32,32};
		SetImage(r,t);
		m_rDst.w = m_rDst.h = 32;
		cout << "You killed by hazard" << '\n';
		cout << "Your tombstone lying there silently........" << '\n';
	}
};





// Door class
class Door: public LOTile{
public:
	int m_iToLevel; // Represents an index of a "Level" object. requires when collision with door happens
  int m_iDestX; // Spawn point after teleport
  int m_iDestY;
  Door(){};


  void SetDoor(int x, int y, SDL_Renderer* r, SDL_Texture* t, int l, int dx, int dy ){
		SetX(x);
		SetY(y);
		SetImage(r,t);
		this -> m_iToLevel = l;
		this -> m_iDestX = dx;
		this -> m_iDestY = dy;
  }
};





// Level class
class Level{
public:
	int m_iNumDoors; // Door Counter
	BGTile map[ROWS][COLS] = {}; // Array of map
	Door doors[3]; // Stores doors in this Level

	Level(){
		m_iNumDoors = 0; // Set door counter to 0 when Level created
	}

	void AddDoor(int x, int y, SDL_Renderer* r, SDL_Texture* t, int l, int dx, int dy ) {
    if (m_iNumDoors <3) {
      doors[m_iNumDoors++].SetDoor(x, y, r, t, l, dx, dy);
      m_iNumDoors++;
			cout << "Door added!" << '\n';
    }else{
      cout << "Can't add more doors!" << '\n';
    }
  }
};




// Door Collision Detection  return true = yes , return false = no
bool DoorCollisionCheck(Level& l ,Player& p){ // x is currLevel
	// Traverse all doors in the tile
	for (int i = 0; i < l.m_iNumDoors; i++){
		if ((p.m_rDst.x + p.m_rDst.w >= l.doors[i].m_rDst.x) &&
				(p.m_rDst.y + p.m_rDst.h >= l.doors[i].m_rDst.y ) &&
				(p.m_rDst.x <= l.doors[i].m_rDst.x + l.doors[i].m_rDst.w) &&
				(p.m_rDst.y <= l.doors[i].m_rDst.y + l.doors[i].m_rDst.h)
			) {
			return true;
		}
		return false;
	}
}


// Check what tile player collide with
char CollisionCheck(Level& l, Player& p){
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			if ((p.m_rDst.x + p.m_rDst.w >= l.map[row][col].m_rDst.x) &&
					(p.m_rDst.y + p.m_rDst.h >= l.map[row][col].m_rDst.y ) &&
					(p.m_rDst.x <= l.map[row][col].m_rDst.x + l.map[row][col].m_rDst.w) &&
					(p.m_rDst.y <= l.map[row][col].m_rDst.y + l.map[row][col].m_rDst.h)
				) {
				return l.map[row][col].value;
			}
		}
	}
}





// Game class
class Game{
private:
	// My variables
	bool m_bRunning;
	bool m_bGotTick;
	int m_iFPS;

	// Keyheck
	bool m_bUpPressed;
	bool m_bDownPressed;
	bool m_bLeftPressed;
	bool m_bRightPressed;

	// SDL variables
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
public:
	Game() :m_iFPS(FPS), m_bGotTick(false) {};
	~Game() {};

	// For SDL initialization
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags){
		if (SDL_Init(SDL_INIT_EVERYTHING)==0) {
			cout << "SDL Initialized!" << '\n';
			// Initialization for window
			m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

			if (m_pWindow != 0) { // If window initialization succeed
				cout << "Window Initialized!" << '\n';
				/* Create a renderer (target window where rendering is displayed,
															rendering driver index or -1 for the first one that supports the requested flag,
															0 or Renderer flags names
														);              */
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);  // Create Renderer for the window we just created
																														// Returns the render or NULL for error
				// Test to see if renderer is initalized
				if (m_pRenderer != 0 ) {
					cout << "Renderer Initialized!" << '\n';
				}else{
					cout << "Renderer initialization failed" << '\n';
					return false; // return false if Renderer failed to initialize
				}

			}else{
				cout << "Window initialization failed" << '\n';
				return false; // return false if window init failed
			}

		}else{ // If SDL failed to initialize
			cout << "SDL init failed" << '\n';
			return false;
		}

		// Initialization for SDL image
		if (IMG_Init(IMG_INIT_PNG)) {
			cout << "image init success!" << '\n';
		}else {
			cout << "image init failed" << '\n';
		}

		m_bRunning = true; // Everything is okay, start the engine.
		return true;
	}



	// Check key pressed
	void update(Level& l ,Player& p ,int& c, SDL_Renderer* r, SDL_Texture* t){ // int c represents currLevel

		if (m_bUpPressed) {
			if (DoorCollisionCheck(l,p)==1) {
				c = l.doors[0].m_iToLevel;
				p.m_rDst.x = l.doors[0].m_iDestX;
				p.m_rDst.y = l.doors[0].m_iDestY;
			}
			if (DoorCollisionCheck(l,p)==0) {
				switch (CollisionCheck(l,p)) {
					case '+':
					case '-':
					m_bUpPressed = false;
					break;
					case '~':
					p.die(r,t);
					m_bUpPressed = false;
					break;
					default:
					break;
				}
			}
			p.MoveY(-1);

		}
		if (m_bDownPressed) {
			if (DoorCollisionCheck(l,p)==1) {
				c = l.doors[0].m_iToLevel;
				p.m_rDst.x = l.doors[0].m_iDestX;
				p.m_rDst.y = l.doors[0].m_iDestY;
			}
			if (DoorCollisionCheck(l,p)==0) {
				switch (CollisionCheck(l,p)) {
					case '+':
					case '-':
					m_bDownPressed = false;
					break;
					case '~':
					p.die(r,t);
					m_bDownPressed = false;
					break;
					default:
					break;
				}
			}
			p.MoveY(1);
		}
		if (m_bLeftPressed) {
			if (DoorCollisionCheck(l,p)==1) {
				c = l.doors[0].m_iToLevel;
				p.m_rDst.x = l.doors[0].m_iDestX;
				p.m_rDst.y = l.doors[0].m_iDestY;
			}

			if (DoorCollisionCheck(l,p)==0) {
				switch (CollisionCheck(l,p)) {
					case '+':
					case '-':
					m_bLeftPressed = false;
					break;
					case '~':
					p.die(r,t);
					m_bLeftPressed = false;
					break;
					default:
					break;
				}
			}
			p.MoveX(-1);
		}
		if (m_bRightPressed) {
			if (DoorCollisionCheck(l,p)==1) {
				c = l.doors[0].m_iToLevel;
				p.m_rDst.x = l.doors[0].m_iDestX;
				p.m_rDst.y = l.doors[0].m_iDestY;
			}
			if (DoorCollisionCheck(l,p)==0) {
				switch (CollisionCheck(l,p)) {
					case '+':
					case '-':
					m_bRightPressed = false;
					break;
					case '~':
					p.die(r,t);
					m_bRightPressed = false;
					break;
					default:
					break;
				}
			}
			p.MoveX(1);
		}


	}


	// Rendering the game
	void render(Level& l, Player& p) {
		SDL_RenderClear(m_pRenderer); // Clear the screen to the draw color.
		// Traverse the 2d array
		for (int row = 0; row < 24; row++) {
			for (int col = 0; col < 32; col++) {
				SDL_RenderCopy(GetRenderer(), l.map[row][col].m_pTexture, l.map[row][col].GetSrc(), l.map[row][col].GetDst());
			}
		}
		SDL_RenderCopy(GetRenderer(), l.doors[0].m_pTexture, l.doors[0].GetSrc(), l.doors[0].GetDst());

		SDL_RenderCopy(GetRenderer(), p.m_pTexture, p.GetSrc(), p.GetDst());
		SDL_RenderPresent(GetRenderer());
	}


	// Returns true if game is running
	bool running(){
		return m_bRunning;
	}


	// Tick function
	bool tick(){
		auto duration = steady_clock::now().time_since_epoch();
		auto count = duration_cast<microseconds>(duration).count();
		int tick = 1000000 / m_iFPS;

		if (count % tick == 0){ // Drops potential duplicate frames.
			if (m_bGotTick == false){
				m_bGotTick = true;
				//cout << "Tick " << tick << " @ " << count << endl;
				return true;
			}
			return false;
		}
		else m_bGotTick = false;
		return false;
	}




	void handleEvents(Player& p){
		SDL_Event event;

		while (SDL_PollEvent(&event)){
			switch (event.type){
				case SDL_QUIT: // From SDL_Event struct (occurs when player clicked the "X" button of the last opening window)
					m_bRunning = false;
					break;
				case SDL_KEYDOWN: // From SDL_Event struct (occurs whenever player press something on keyboard)
					switch (event.key.keysym.sym){ // event.key.keysym.sym = (the value of the key pressed)
						case 'w':
						case 'W':
						if (!m_bUpPressed){
							m_bUpPressed = true;
						}
							break;
						case 's':
						case 'S':
							if (!m_bDownPressed){
								m_bDownPressed = true;
							}
							break;
						case 'a':
						case 'A':
							if (!m_bLeftPressed){
								m_bLeftPressed = true;
							}
							break;
						case 'd':
						case 'D':
							if (!m_bRightPressed){
								m_bRightPressed = true;
							}
							break;
					}
					break;
				case SDL_KEYUP:
					switch (event.key.keysym.sym){
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

	void clean(){
		cout << "cleaning game......" << '\n';
		SDL_DestroyTexture(m_pTexture);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
		IMG_Quit();
		Mix_Quit();
		SDL_Quit();
	}


	SDL_Renderer* GetRenderer() {
		return m_pRenderer;
	}






};
