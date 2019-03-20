#include <string>
#include "FSM.h"
#include "Game.h"
#define ROWS 12
#define COLS 16
#define SIZE 64

void State::Render()
{
	SDL_RenderPresent(Game::Instance()->GetRenderer());
}

void State::RenderFont(bool r, const char* c, int x, int y)
{
	if (r)
	{
		SDL_Color textColor = { 255, 255, 255, 0 }; // White text.
		SDL_Surface* fontSurf = TTF_RenderText_Solid(m_Font, c, textColor);
		SDL_DestroyTexture(m_pFontText); // Need to de-allocate previous font texture.
		m_pFontText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), fontSurf);
		m_rFontRect = { x, y, fontSurf->w, fontSurf->h };
		SDL_FreeSurface(fontSurf);
	}
	SDL_RenderCopy(Game::Instance()->GetRenderer(), m_pFontText, 0, &m_rFontRect);
}

// Begin TitleState
void TitleState::Enter()
{
	cout << "Entering Title..." << endl;
	Game::Instance()->SetLeftMouse(false);
	m_vButtons.push_back(new Button("Img/play.png", { 0,0,400,100 }, { 312,200,400,100 }));
	m_vButtons.push_back(new Button("Img/exit.png", { 0,0,400,100 }, { 312,400,400,100 }));
}

void TitleState::Update()
{
	// Update buttons. Allows for mouseovers.
	for (int i = 0; i < (int)m_vButtons.size(); i++)
		m_vButtons[i]->Update();
	// Parse buttons. Make sure buttons are in an if..else structure.
	if (m_vButtons[btn::play]->Clicked())
		Game::Instance()->GetFSM()->ChangeState(new GameState());
	else if (m_vButtons[btn::exit]->Clicked())
	{
		SDL_Delay(500); // Just pause to let the button sound play.
		Game::Instance()->QuitGame();
	}
}

void TitleState::Render()
{
	cout << "Rendering Title..." << endl;
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 128, 0, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	for (int i = 0; i < (int)m_vButtons.size(); i++)
		m_vButtons[i]->Render();
	State::Render();
}

void TitleState::Exit()
{
	cout << "Exiting Title..." << endl;
	for (int i = 0; i < (int)m_vButtons.size(); i++)
	{
		delete m_vButtons[i];
		m_vButtons[i] = nullptr;
	}
	m_vButtons.clear();
	m_vButtons.shrink_to_fit();
}
// End TitleState

// Begin GameState
void GameState::Enter()
{
	cout << "Entering Game..." << endl;
	Game::Instance()->GetAM()->LoadMusic("Aud/game.mp3");
	Game::Instance()->GetAM()->PlayMusic();
	m_Font = TTF_OpenFont("Img/LTYPE.TTF", 20);
	//m_pPlayer = new Player(480, 352);
}

void GameState::Update()
{
	if (Game::Instance()->KeyDown(SDL_SCANCODE_P) == 1)
	{
		Game::Instance()->GetFSM()->PushState(new PauseState());
		return;
	}
	m_iTimeCtr++;
}

void GameState::Render()
{
	cout << "Rendering Game..." << endl;
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 0, 255, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	m_iTime =  m_iTimeCtr / 30;
	m_sTime = "TIME: " + to_string(m_iTime);
	RenderFont((m_iLastTime < m_iTime?1:0), m_sTime.c_str(), 32, 50);
	m_iLastTime = m_iTime;
	State::Render();
}

void GameState::Exit()
{
	cout << "Exiting Game..." << endl;
	Game::Instance()->GetAM()->ClearMusic(); // De-allocate the music track.
	TTF_CloseFont(m_Font);
	SDL_DestroyTexture(m_pFontText);
}
// End GameState

// Begin PauseState
void PauseState::Enter()
{
	cout << "Entering Pause..." << endl;
	m_vButtons.push_back(new Button("Img/resume.png", { 0,0,200,80 }, { 412,200,200,80 }));
	m_vButtons.push_back(new Button("Img/exit.png", { 0,0,400,100 }, { 412,400,200,80 }));
	Game::Instance()->GetAM()->ToggleMusic(); // Pause the music.
}

void PauseState::Update()
{
	// Update buttons. Allows for mouseovers.
	for (int i = 0; i < (int)m_vButtons.size(); i++)
		m_vButtons[i]->Update();
	// Parse buttons. Make sure buttons are in an if..else structure.
	if (m_vButtons[btn::resume]->Clicked())
		Game::Instance()->GetFSM()->PopState();
	else if (m_vButtons[btn::exit]->Clicked())
	{
		Game::Instance()->GetFSM()->Clean(); // Clear all states, including GameState on bottom.
		Game::Instance()->GetFSM()->ChangeState(new TitleState()); // Then change to a new TitleState.
	}
}

void PauseState::Render()
{
	cout << "Rendering Pause..." << endl;
	Game::Instance()->GetFSM()->GetStates().front()->Render();
	SDL_SetRenderDrawBlendMode(Game::Instance()->GetRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 64, 64, 128, 128);
	SDL_Rect rect = { 256, 128, 512, 512 };
	SDL_RenderFillRect(Game::Instance()->GetRenderer(), &rect);
	for (int i = 0; i < (int)m_vButtons.size(); i++)
		m_vButtons[i]->Render();
	State::Render();
}

void PauseState::Exit()
{
	cout << "Exiting Pause..." << endl;
	Game::Instance()->GetAM()->ToggleMusic(); // Resume the music.
	for (int i = 0; i < (int)m_vButtons.size(); i++)
	{
		delete m_vButtons[i];
		m_vButtons[i] = nullptr;
	}
	m_vButtons.clear();
	m_vButtons.shrink_to_fit();
}
// End PauseState

// Begin LoseState
void LoseState::Enter()
{
	cout << "Entering Lose..." << endl;
	m_vButtons.push_back(new Button("Img/exit.png", { 0,0,400,100 }, { 412,400,200,80 }));
	Game::Instance()->GetAM()->LoadMusic("Aud/lose.mp3");
	Game::Instance()->GetAM()->PlayMusic();
	m_Font = TTF_OpenFont("Img/LTYPE.TTF", 40);
	// Do the font stuff once, so Render() only needs to invoke SDL_RenderCopy().
	m_sTime = "YOU CRASHED! FINAL TIME: " + m_sTime;
	SDL_Color textColor = { 255, 255, 255, 0 }; // White text.
	SDL_Surface* fontSurf = TTF_RenderText_Solid(m_Font, m_sTime.c_str(), textColor);
	m_pFontText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), fontSurf);
	m_rFontRect = { 200, 250, fontSurf->w, fontSurf->h };
	SDL_FreeSurface(fontSurf);
}

void LoseState::Update()
{
	// Update buttons. Allows for mouseovers.
	for (int i = 0; i < (int)m_vButtons.size(); i++)
		m_vButtons[i]->Update();
	// Parse buttons. Make sure buttons are in an if..else structure.
	if (m_vButtons[btn::exit]->Clicked())
	{
		Game::Instance()->GetFSM()->Clean(); // Clear all states, including GameState on bottom.
		Game::Instance()->GetFSM()->ChangeState(new TitleState()); // Then change to a new TitleState.
	}
}

void LoseState::Render()
{
	cout << "Rendering Lose..." << endl;
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 0, 0, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	for (int i = 0; i < (int)m_vButtons.size(); i++)
		m_vButtons[i]->Render();
	SDL_RenderCopy(Game::Instance()->GetRenderer(), m_pFontText, 0, &m_rFontRect);
	State::Render();
}

void LoseState::Exit()
{
	cout << "Exiting Lose..." << endl;
	Game::Instance()->GetAM()->ClearMusic(); // De-allocate the music track.
	TTF_CloseFont(m_Font);
	SDL_DestroyTexture(m_pFontText);
	for (int i = 0; i < (int)m_vButtons.size(); i++)
	{
		delete m_vButtons[i];
		m_vButtons[i] = nullptr;
	}
	m_vButtons.clear();
	m_vButtons.shrink_to_fit();
}
// End PauseState

// Begin StateMachine
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
	while (!m_vStates.empty()) // Ensures that ALL states left in the vector are cleaned up.
	{						   
		m_vStates.back()->Exit();
		delete m_vStates.back();
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
}

StateMachine::~StateMachine()
{
	cout << "Destroying FSM..." << endl;
	Clean();
}
// End StateMachine