#include "FSM.h"
#include "Game.h"

void State::Render(){
	SDL_RenderPresent(Game::Instance()->GetRenderer());
}







// Title State
void TitleState::Enter(){
	cout << "Entering Title..." << '\n';
	LogoSurf = IMG_Load("img/malibu.png");
	LogoText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), LogoSurf);
	m_vButtons.push_back(new Button("img/play.png", { 312,420,400,100 }));
	m_vButtons.push_back(new Button("img/exit.png", { 312,600,400,100 }));
	Game::Instance()->GetAM()->LoadMusic("audio/Theme.mp3");
	Game::Instance()->GetAM()->PlayMusic();
}

void TitleState::Update(){
	// Logo size and position
	destR.h = 326;
	destR.w = 418;
	destR.x = 303;
	destR.y = 50;

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
	// Set background to white
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 255, 255, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());

	// Renders the title logo
	SDL_RenderCopy(Game::Instance()->GetRenderer(), LogoText, NULL, &destR);

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
	m_vButtons.clear();
	m_vButtons.shrink_to_fit();
}












// Game State
void GameState::Enter(){
	cout << "Entering Game..." << '\n';
	Game::Instance()->GetAM()->LoadMusic("audio/Theme.mp3");
	Game::Instance()->GetAM()->LoadSound("audio/pickup.wav");
	Game::Instance()->GetAM()->LoadSound("audio/death.wav");
	Game::Instance()->GetAM()->LoadSound("audio/winstate.wav");
	Game::Instance()->GetAM()->LoadSound("audio/door.wav");
	Game::Instance()->GetAM()->PlayMusic();
}

void GameState::Update(){
	// Press "P" to go into PauseState
	if (Game::Instance()->KeyDown(SDL_SCANCODE_P) == 1){
		Game::Instance()->GetFSM()->PushState(new PauseState());

		// Press "Esc" to go into TitleState
	}else if (Game::Instance()->KeyDown(SDL_SCANCODE_ESCAPE) == 1){
		Game::Instance()->GetFSM()->ChangeState(new TitleState());
	}

	// Trigger sounds
	// if (Game::Instance()->KeyDown(SDL_SCANCODE_L) == 1){
	// 	Game::Instance()->GetAM()->PlaySound(sfx::pickup);
	// }
	// if (Game::Instance()->KeyDown(SDL_SCANCODE_K) == 1){
	// 	Game::Instance()->GetAM()->PlaySound(sfx::death);
	// }
	// if (Game::Instance()->KeyDown(SDL_SCANCODE_J) == 1){
	// 	Game::Instance()->GetAM()->PlaySound(sfx::door);
	// }
	// if (Game::Instance()->KeyDown(SDL_SCANCODE_H) == 1){
	// 	Game::Instance()->GetAM()->PlaySound(sfx::win);
	// }





}

void GameState::Render(){
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 0, 0, 0, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	State::Render();
}

void GameState::Exit(){
	cout << "Exiting Game..." << '\n';
	// Clear all the music
	Game::Instance()->GetAM()->ClearMusic();
	Game::Instance()->GetAM()->ClearSounds();
}














// Pause State
void PauseState::Enter(){
	cout << "Entering Pause..." << '\n';
	Game::Instance()->GetAM()->ToggleMusic();
}

void PauseState::Update(){
	// Press "R" to exite Pause State
	if (Game::Instance()->KeyDown(SDL_SCANCODE_R) == 1){
		Game::Instance()->GetFSM()->PopState();
	}
}

void PauseState::Render(){
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 255, 0, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	State::Render();
}

void PauseState::Exit(){
	cout << "Exiting Pause..." << '\n';
	Game::Instance()->GetAM()->ToggleMusic();
}











// WinState
void WinState::Enter(){
	cout << "Entering WinState..." << '\n';
}

void WinState::Update(){

}

void WinState::Render(){

}

void WinState::Exit(){
	cout << "Exiting WinState..." << '\n';
}












// LoseState
void LoseState::Enter(){
	cout << "Entering LoseState..." << '\n';
}

void LoseState::Update(){

}

void LoseState::Render(){

}

void LoseState::Exit(){
	cout << "Exiting LoseState..." << '\n';
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
