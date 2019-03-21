#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Button.h"
#include "Sprites.h"
#include "SDL_ttf.h"
using namespace std;

class State {
protected:
	TTF_Font* m_Font;
	SDL_Texture* m_pFontText;
	SDL_Rect m_rFontRect;

public:
	virtual void Update() = 0; // A 'pure virtual' method.
	virtual void Render();
	void RenderFont(bool, const char*, int, int);
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void Resume() = 0;
};

class PauseState : public State{
private:
	vector<Button*> m_vButtons;
	enum btn { resume, exit };

public:
	PauseState() {}
	void Update(); // Method prototype.
	void Render();
	void Enter();
	void Exit();
	void Resume() {}
};

class GameState : public State{
private:
	Player* m_pPlayer;
	int m_iTime, m_iLastTime, m_iTimeCtr;

	string m_sTime;

public:
	GameState() : m_iTime(0), m_iLastTime(-1),	m_iTimeCtr(0) {}
	void Update();
	void Render();
	void Enter();
	void Exit();
	void Resume() { cout << "Resuming Game..." << endl; }
};

class TitleState : public State{
private:
	vector<Button*> m_vButtons;
	enum btn { play, exit };

public:
	TitleState() {}
	void Update();
	void Render();
	void Enter();
	void Exit();
	void Resume() {}
};

class LoseState : public State{
private:
	vector<Button*> m_vButtons;
	enum btn { exit };
	string m_sTime;

public:
	LoseState(int t) { m_sTime = to_string(t); }
	void Update();
	void Render();
	void Enter();
	void Exit();
	void Resume() {}
};

class StateMachine{
private:
	vector<State*> m_vStates;

public:
	~StateMachine();
	void Update();
	void Render();
	void PushState(State* pState);
	void ChangeState(State* pState);
	void PopState();
	void Clean();
	vector<State*>& GetStates() { return m_vStates; }
};
