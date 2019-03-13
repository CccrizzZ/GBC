#include "FSM.h"
#include "Game.h"
#include "Button.h"
#include <fstream>

void State::Render(){
	SDL_RenderPresent(Game::Instance()->GetRenderer());
}











// Title State
void TitleState::Enter(){
	cout << "Entering Title..." << '\n';
  m_vButtons.push_back(new Button("img/new-game.png", { 312,420,300,50 }));
	m_vButtons.push_back(new Button("img/exit.png", { 357,600,210,50 }));
}

void TitleState::Update(){

	// Button Update
	for (int i = 0; i < (int)m_vButtons.size(); i++){
		m_vButtons[i]->Update();
	}

	// Button event
	if (m_vButtons[btn::play]->Clicked()){
		Game::Instance()->GetFSM()->ChangeState(new GameState());
	}else if (m_vButtons[btn::quit]->Clicked()){
		Game::Instance()->DoQuit();
	}
}

void TitleState::Render(){
	// // Set background to white
	// SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 255, 255, 255);
	// SDL_RenderClear(Game::Instance()->GetRenderer());
  //
	// // Renders the title logo
	// SDL_RenderCopy(Game::Instance()->GetRenderer(), LogoText, NULL, &destR);

	// Renders all the buttons
	for (int i = 0; i < (int)m_vButtons.size(); i++){
		m_vButtons[i]->Render();
	}
	State::Render();  // SDL_RenderPresent
}

void TitleState::Exit(){
	cout << "Exiting Title..." << '\n';

	// Clear all music and sfx
	Game::Instance()->GetAM()->ClearMusic();
	Game::Instance()->GetAM()->ClearSounds();

	// Deallocate all buttons and delete vector
	for (int i = 0; i < (int)m_vButtons.size(); i++){
		delete m_vButtons[i];
		m_vButtons[i] = nullptr;
	}
	SDL_FreeSurface(LogoSurf);
	SDL_DestroyTexture(LogoText);
	m_vButtons.clear();
	m_vButtons.shrink_to_fit();
}











// GameState
void GameState::Enter(){
  cout << "Entering Game..." << '\n';

	// Load bg texture
	bgSurf = IMG_Load("img/Backgrounds.png");
	bgText = SDL_CreateTextureFromSurface(Game::Instance() -> GetRenderer(), bgSurf);

}

void GameState::Update(){
if (Game::Instance()->KeyDown(SDL_SCANCODE_P) == 1){
		// // Press "P" to go into PauseState
		// Game::Instance()->GetFSM()->PushState(new PauseState());
	}else if (Game::Instance()->KeyDown(SDL_SCANCODE_ESCAPE) == 1){
		// Press "Esc" to go into TitleState
		Game::Instance()->GetFSM()->ChangeState(new TitleState());
	}
}

void GameState::Render(){

}

void GameState::Exit(){

}















// StateMachine
void StateMachine::Update(){
	if (!m_vStates.empty()){
		m_vStates.back()->Update();
	}
}

void StateMachine::Render(){
	if (!m_vStates.empty())
		m_vStates.back()->Render();
}

void StateMachine::PushState(State* pState){
	m_vStates.push_back(pState);
	m_vStates.back()->Enter();
}

void StateMachine::ChangeState(State* pState){
	if (!m_vStates.empty()){
		m_vStates.back()->Exit();
		delete m_vStates.back();
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
	pState->Enter();
	m_vStates.push_back(pState);
}

void StateMachine::PopState(){
	if (!m_vStates.empty()){
		m_vStates.back()->Exit();
		delete m_vStates.back();
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
	m_vStates.back()->Resume();
}

void StateMachine::Clean(){
	while (!m_vStates.empty()){
		m_vStates.back()->Exit();
		delete m_vStates.back();
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
}
