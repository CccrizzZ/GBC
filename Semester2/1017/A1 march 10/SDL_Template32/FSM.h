#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Button.h"
#include "Classes.h"

using namespace std;

// Abstract class for all states
class State {
protected:
	State() {}
public:
	virtual void Update() = 0;
	virtual void Render();
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void Resume() = 0;
};





// TitleState
class TitleState : public State {
private:
	vector<Button*> m_vButtons;
	// Logo
	SDL_Rect srcR, destR;
	SDL_Surface* LogoSurf;
	SDL_Texture* LogoText;
public:
	TitleState() {}
	void Update();
	void Render();
	void Enter();
	void Exit();
	void Resume() {}
	enum btn { play, quit };
};


// GameState
class GameState : public State {
public:
	GameState() {}
	void Update();
	void Render();
	void Enter();
	void Exit();
	void Resume() { cout << "Resuming Game..." << '\n'; }
	// Sound effect
	enum sfx { pickup, death, door };

	bool isWon;
	int currPoints;

	// map Tile image
	SDL_Surface* tileSurf;
	SDL_Texture* tileText;

	// Player
	Player p;
	SDL_Surface* playerSurf;
	SDL_Texture* playerText;
	void pmove(Level& l, Player& p, int& c);

	// Levels
	int currLevel;
	const char* levelNames[5] = { "Level1.txt", "Level2.txt", "Level3.txt", "Level4.txt", "Level5.txt" };
	Level Levels[5] = { Level(3), Level(1), Level(1), Level(2), Level(1) };
	bool BuildMap(Level& l, const char* n, SDL_Renderer* r, SDL_Texture* t);
	void rendermap(Level& l, Player& p, int c);


	Item i1;
	Item i2;
	Item i3;
	Item i4;
	Item i5;



};


// PauseState
class PauseState : public State {
public:
	PauseState() {}
	void Update();
	void Render();
	void Enter();
	void Exit();
	void Resume() {}
};


// WinState
class WinState : public State {
private:
	vector<Button*> wButtons;
	// Logo
	SDL_Rect wsrcR, wdestR;
	SDL_Surface* wSurf;
	SDL_Texture* wText;
public:
	WinState(){};
	void Enter();
	void Update();
	void Render();
	void Exit();
	void Resume() {}
	enum wsfx { win };
	enum wbtn { m };


};


// LoseState
class LoseState : public State {
public:
	vector<Button*> lButtons;
	LoseState(){}
	void Enter();
	void Update();
	void Render();
	void Exit();
	void Resume() {}
	enum lbtn { menu };

	// Lost title
	SDL_Rect LsrcR, LdestR;
	SDL_Surface* LostSurf;
	SDL_Texture* LostText;
	enum Lsfx { death };

};






class StateMachine{
private:
	vector<State*> m_vStates;
public:
	void Update();
	void Render();
	void PushState(State* pState);
	void ChangeState(State* pState);
	void PopState();
	void Clean();

	// State vector getter
	vector<State*>& GetStates() {
		return m_vStates;
	}

};
