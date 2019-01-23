#pragma once
#include <iostream>
#include <vector>
using namespace std;

class State // This is the abstract base class for all specific states.
{
public:
	virtual void Update() = 0; // Having at least one 'pure virtual' method like this, makes a class abtract.
	virtual void Render();     // Meaning we cannot create objects of the class.
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual void Resume() = 0; // Virtual keyword means we CAN override in derived class, also needed for abstract.
protected:
	State() {}
};

class PauseState : public State
{
public:
	PauseState() {}
	void Update(); // Method prototype. We don't really need to use virtual here anymore.
	void Render();
	void Enter(); 
	void Exit(); 
	void Resume() {}
};

class GameState : public State
{
public:
	GameState() {}
	void Update();
	void Render();
	void Enter();
	void Exit();
	void Resume() { cout << "Resuming Game..." << endl; }
	enum sfx { jump, boom, laser };
};

class TitleState : public State
{
public:
	TitleState() {}
	void Update();
	void Render();
	void Enter(); 
	void Exit();
	void Resume() {}
	enum sfx { boop };
};

class StateMachine
{
public:
	void Update();
	void Render();
	void PushState(State* pState);
	void ChangeState(State* pState);
	void PopState();
	void Clean();
	vector<State*>& GetStates() { return m_vStates; }

private:
	vector<State*> m_vStates;
};