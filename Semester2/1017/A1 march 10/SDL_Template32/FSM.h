#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "Button.h"
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
	enum sfx { pickup, death, win, door };
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
public:
	WinState(){};
	void Enter();
	void Update();
	void Render();
	void Exit();
};


// LoseState
class LoseState : public State {
public:
	LoseState(){}
	void Enter();
	void Update();
	void Render();
	void Exit();
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
