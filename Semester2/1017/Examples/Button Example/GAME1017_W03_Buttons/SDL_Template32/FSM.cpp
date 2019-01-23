#include "FSM.h"
#include "Game.h"

void State::Render()
{
	SDL_RenderPresent(Game::Instance()->GetRenderer());
}

void PauseState::Enter()
{
	cout << "Entering Pause..." << endl;
	Game::Instance()->GetAM()->ToggleMusic();
}

void PauseState::Update()
{
	if (Game::Instance()->KeyDown(SDL_SCANCODE_R) == 1)
		Game::Instance()->GetFSM()->PopState();
}

void PauseState::Render()
{
	cout << "Rendering Pause..." << endl;
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 255, 0, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	State::Render();
}

void PauseState::Exit()
{
	cout << "Exiting Pause..." << endl;
	Game::Instance()->GetAM()->ToggleMusic();
}

void GameState::Enter()
{ 
	cout << "Entering Game..." << endl;
	Game::Instance()->GetAM()->LoadMusic("Aud/Turtles.mp3");
	Game::Instance()->GetAM()->LoadSound("Aud/jump.wav");
	Game::Instance()->GetAM()->LoadSound("Aud/death.wav");
	Game::Instance()->GetAM()->LoadSound("Aud/laser.wav");
	Game::Instance()->GetAM()->PlayMusic();
}

void GameState::Update()
{
	if (Game::Instance()->KeyDown(SDL_SCANCODE_P) == 1)
		Game::Instance()->GetFSM()->PushState(new PauseState());
	else if (Game::Instance()->KeyDown(SDL_SCANCODE_X) == 1)
		Game::Instance()->GetFSM()->ChangeState(new TitleState());

	if (Game::Instance()->KeyDown(SDL_SCANCODE_J) == 1)
		Game::Instance()->GetAM()->PlaySound(sfx::jump);
	if (Game::Instance()->KeyDown(SDL_SCANCODE_K) == 1)
		Game::Instance()->GetAM()->PlaySound(sfx::boom);
	if (Game::Instance()->KeyDown(SDL_SCANCODE_L) == 1)
		Game::Instance()->GetAM()->PlaySound(sfx::laser);
}

void GameState::Render()
{
	cout << "Rendering Game..." << endl;
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 0, 255, 0, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	State::Render();
}

void GameState::Exit()
{ 
	cout << "Exiting Game..." << endl;
	Game::Instance()->GetAM()->ClearMusic();
	Game::Instance()->GetAM()->ClearSounds();
}

void TitleState::m_Test()
{
	cout << "Blah..." << endl;
}

void TitleState::Enter()
{ 
	cout << "Entering Title..." << endl;
	m_vButtons.push_back(new Button("Img/button.png", { 312,100,400,100 }));
	m_vButtons.push_back(new Button("Img/exit.png", { 312,300,400,100 }));
	Game::Instance()->GetAM()->LoadMusic("Aud/Thundercats.mp3");
	Game::Instance()->GetAM()->LoadSound("Aud/power.wav");
	Game::Instance()->GetAM()->PlayMusic();
}

void TitleState::Update()
{
	if (Game::Instance()->KeyDown(SDL_SCANCODE_B) == 1)
		Game::Instance()->GetAM()->PlaySound(sfx::boop);
	for (int i = 0; i < (int)m_vButtons.size(); i++)
		m_vButtons[i]->Update();
	// Parse buttons.
	if (m_vButtons[btn::play]->Clicked())
		Game::Instance()->GetFSM()->ChangeState(new GameState());
	else if (m_vButtons[btn::exit]->Clicked())
		Game::Instance()->DoQuit();
}

void TitleState::Render()
{
	cout << "Rendering Title..." << endl;
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 0, 0, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	for (int i = 0; i < (int)m_vButtons.size(); i++)
		m_vButtons[i]->Render();
	State::Render();
}

void TitleState::Exit()
{ 
	cout << "Exiting Title..." << endl;
	Game::Instance()->GetAM()->ClearMusic();
	Game::Instance()->GetAM()->ClearSounds();
	for (int i = 0; i < (int)m_vButtons.size(); i++)
	{
		delete m_vButtons[i];
		m_vButtons[i] = nullptr;
	}
	m_vButtons.clear();
	m_vButtons.shrink_to_fit();

}

void StateMachine::Update()
{
	if (!m_vStates.empty()) // empty() and back() are methods of the vector type.
		m_vStates.back()->Update();
}

void StateMachine::Render()
{
	if (!m_vStates.empty())
		m_vStates.back()->Render();
}

void StateMachine::PushState(State* pState)
{
	m_vStates.push_back(pState); // push_back() is a method of the vector type.
	m_vStates.back()->Enter();
}

void StateMachine::ChangeState(State* pState)
{
	if (!m_vStates.empty())
	{
		m_vStates.back()->Exit();
		delete m_vStates.back(); // De-allocating the state in the heap.
		m_vStates.back() = nullptr; // Nullifying pointer to the de-allocated state.
		m_vStates.pop_back(); // Removes the now-null pointer from the vector.
	}
	pState->Enter();
	m_vStates.push_back(pState);
}

void StateMachine::PopState()
{
	if (!m_vStates.empty())
	{
		m_vStates.back()->Exit();
		delete m_vStates.back();
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
	m_vStates.back()->Resume();
}

void StateMachine::Clean()
{
	while (!m_vStates.empty()) // Because we can exit the game in the pause state with the window's 'X'.
	{						   // Ensures that ALL states left in the vector are cleaned up.
		m_vStates.back()->Exit();
		delete m_vStates.back();
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
}