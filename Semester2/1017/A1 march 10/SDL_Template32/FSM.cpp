#include "FSM.h"
#include "Game.h"
#include "Classes.h"
#include <fstream>

void State::Render(){
	SDL_RenderPresent(Game::Instance()->GetRenderer());
}







// Title State
void TitleState::Enter(){
	cout << "Entering Title..." << '\n';
	// Load the Logo
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
	SDL_FreeSurface(LogoSurf);
	SDL_DestroyTexture(LogoText);
	m_vButtons.clear();
	m_vButtons.shrink_to_fit();
}

















// Game State
bool GameState::BuildMap(Level& l, const char* n, SDL_Renderer* r, SDL_Texture* t){
	ifstream inFile(n);
	char temp;
	if (inFile.is_open()){
		for (int row = 0; row < ROWS; row++){
			for (int col = 0; col < COLS; col++){
				inFile >> temp;
				l.map[row][col].SetBGTile( (temp == '*' ? ' ' : temp) );
				l.map[row][col].SetImage(r, t);
				l.map[row][col].m_rDst = { col*32, row*32, 32, 32 };
				if (temp == 'Q'){
					int tl, px, py;
					inFile >> tl >> px >> py;
					l.AddDoor(col, row, tl, px, py, r, t);
				}
			}
		}
		inFile.close();
		return 0;
	}
	return 1;
}







void GameState::Enter(){
	cout << "Entering Game..." << '\n';

	// Load tile texture
	tileSurf = IMG_Load("img/Tiles.png");
	tileText = SDL_CreateTextureFromSurface(Game::Instance() -> GetRenderer(), tileSurf);

	// BuildMap
	for (int i = 0; i < sizeof(levelNames)/sizeof(levelNames[0]); i++) {
		BuildMap(Levels[i], levelNames[i], Game::Instance()->GetRenderer(), tileText);
	}


	// Set currLevel
	currLevel = 0;

	// Set currPoints
	currPoints = 0;

	// Load Player
	playerSurf = IMG_Load("img/Player.png");
	playerText = SDL_CreateTextureFromSurface(Game::Instance() -> GetRenderer(), playerSurf);
	p = Player(COLS/2, ROWS/2, Game::Instance() -> GetRenderer(), playerText);




	i1 = Item(10, 10, Game::Instance() -> GetRenderer(), tileText);
	i2 = Item(20, 10, Game::Instance() -> GetRenderer(), tileText);
	i3 = Item(14, 14, Game::Instance() -> GetRenderer(), tileText);
	i4 = Item(10, 19, Game::Instance() -> GetRenderer(), tileText);
	i5 = Item(17, 15, Game::Instance() -> GetRenderer(), tileText);





	Game::Instance()->GetAM()->LoadMusic("audio/Theme.mp3");
	Game::Instance()->GetAM()->LoadSound("audio/pickup.wav");
	Game::Instance()->GetAM()->LoadSound("audio/death.wav");
	Game::Instance()->GetAM()->LoadSound("audio/door.wav");
	Game::Instance()->GetAM()->PlayMusic();
}


bool DoorCollisionCheck(Player p, Door c){
	bool safe = true;

	if (!((p.m_rDst.x > c.m_rDst.x + c.m_rDst.w) ||
		  (p.m_rDst.x + p.m_rDst.w < c.m_rDst.x) ||
		  (p.m_rDst.y + p.m_rDst.h < c.m_rDst.y)  ||
		  (p.m_rDst.y > c.m_rDst.y + c.m_rDst.h)))	{
		safe = false;
	}
	return safe;
}

// bool CollisionCheck(SDL_Rect p, SDL_Rect c){
// 	bool safe = true;
//
// 	if (!((p.m_rDst.x > c.m_rDst.x + c.m_rDst.w) ||
// 		  (p.m_rDst.x + p.m_rDst.w < c.m_rDst.x) ||
// 		  (p.m_rDst.y + p.m_rDst.h < c.m_rDst.y)  ||
// 		  (p.m_rDst.y > c.m_rDst.y + c.m_rDst.h)))	{
// 		safe = false;
// 	}
// 	return safe;
// }

void GameState::pmove(Level& l, Player& p, int& c) {


	// Player movement
	if (Game::Instance()->KeyDown(SDL_SCANCODE_W) == 1 &&  l.map[(p.m_rDst.y / 32)-1][p.m_rDst.x / 32].m_bIsObstacle != true){
		p.m_rDst.y -= 32;
	}

	if (Game::Instance()->KeyDown(SDL_SCANCODE_A) == 1 && l.map[p.m_rDst.y / 32][(p.m_rDst.x / 32) - 1].m_bIsObstacle != true) {
		p.m_rDst.x -= 32;
	}

	if (Game::Instance()->KeyDown(SDL_SCANCODE_S) == 1 && l.map[(p.m_rDst.y / 32) + 1][p.m_rDst.x / 32].m_bIsObstacle != true) {
		p.m_rDst.y += 32;
	}

	if (Game::Instance()->KeyDown(SDL_SCANCODE_D) == 1 && l.map[p.m_rDst.y / 32][(p.m_rDst.x / 32) + 1].m_bIsObstacle != true) {
		p.m_rDst.x += 32;
	}


	if (l.map[p.m_rDst.y / 32][(p.m_rDst.x / 32)].m_bIsHazard == true) {
		p.m_bIsDead=true;
	}else{
		for (int i = 0; i < l.m_iNumDoors; i++){
			if (p.m_rDst.x == l.doors[i].m_rDst.x && p.m_rDst.y == l.doors[i].m_rDst.y){
				Game::Instance()->GetAM()->PlaySound(sfx::door);
				c = l.doors[i].m_iToLevel;
				p.m_rDst.x = l.doors[i].m_DestX * 32;
				p.m_rDst.y = l.doors[i].m_DestY * 32;
			}
		}
	}
}


void GameState::Update(){
	// Player movement
	pmove(Levels[currLevel], p, currLevel);

	if (Game::Instance()->KeyDown(SDL_SCANCODE_P) == 1){
		// Press "P" to go into PauseState
		Game::Instance()->GetFSM()->PushState(new PauseState());
	}else if (Game::Instance()->KeyDown(SDL_SCANCODE_ESCAPE) == 1){
		// Press "Esc" to go into TitleState
		Game::Instance()->GetFSM()->ChangeState(new TitleState());
	}else if (p.m_bIsDead==true) {
		// If player is dead go into LoseState
		Game::Instance()->GetFSM()->ChangeState(new LoseState());
	}else if (currPoints==5) {
		isWon = true;
	}else if (isWon) {
		// Enter WinState
		Game::Instance()->GetFSM()->ChangeState(new WinState());
	}

	if (p.m_rDst.x == i1.m_rDst.x && p.m_rDst.y == i1.m_rDst.y) {
		Game::Instance()->GetAM()->PlaySound(sfx::pickup);
		currPoints+=1;
	}else if (p.m_rDst.x == i2.m_rDst.x && p.m_rDst.y == i2.m_rDst.y) {
		Game::Instance()->GetAM()->PlaySound(sfx::pickup);
		currPoints+=1;
	}else if (p.m_rDst.x == i3.m_rDst.x && p.m_rDst.y == i3.m_rDst.y) {
		Game::Instance()->GetAM()->PlaySound(sfx::pickup);
		currPoints+=1;
	}else if (p.m_rDst.x == i4.m_rDst.x && p.m_rDst.y == i4.m_rDst.y) {
		Game::Instance()->GetAM()->PlaySound(sfx::pickup);
		currPoints+=1;
	}else if (p.m_rDst.x == i5.m_rDst.x && p.m_rDst.y == i5.m_rDst.y) {
		Game::Instance()->GetAM()->PlaySound(sfx::pickup);
		currPoints+=1;
	}






	// if (Game::Instance()->KeyDown(SDL_SCANCODE_H) == 1){
	// 	Game::Instance()->GetAM()->PlaySound(sfx::win);
	// }





}



// Rendering the game
void GameState::rendermap(Level& l, Player& p, int c) {
	// 1. Drawing the tiles.
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++){
			if (l.map[row][col].m_cOutput != ' '){
				SDL_RenderCopy(Game::Instance()->GetRenderer(), l.map[row][col].m_pTexture, &l.map[row][col].m_rSrc, &l.map[row][col].m_rDst);
			}
		}
	}

	// 2. Drawing the level doors.
	for (int i = 0; i < l.m_iNumDoors; i++){
		SDL_RenderCopy(l.doors[i].m_pRenderer, l.doors[i].m_pTexture, &l.doors[i].m_rSrc, &l.doors[i].m_rDst);
	}

	// 3. Drawing Item.
	if (currLevel==0) {
		SDL_RenderCopy(i1.m_pRenderer, i1.m_pTexture, &i1.m_rSrc, &i1.m_rDst);
	}else if (currLevel==1) {
		SDL_RenderCopy(i2.m_pRenderer, i2.m_pTexture, &i2.m_rSrc, &i2.m_rDst);
	}else if (currLevel==2) {
		SDL_RenderCopy(i3.m_pRenderer, i3.m_pTexture, &i3.m_rSrc, &i3.m_rDst);
	}else if (currLevel==3) {
		SDL_RenderCopy(i4.m_pRenderer, i4.m_pTexture, &i4.m_rSrc, &i4.m_rDst);
	}else if (currLevel==4) {
		SDL_RenderCopy(i5.m_pRenderer, i5.m_pTexture, &i5.m_rSrc, &i5.m_rDst);
	}




	// 4. Drawing the player.
	SDL_RenderCopy(p.m_pRenderer, p.m_pTexture, &p.m_rSrc, &p.m_rDst);



}




void GameState::Render(){
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 0, 0, 0, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	rendermap(Levels[currLevel], p, currLevel);
	State::Render();
}

void GameState::Exit(){
	cout << "Exiting Game..." << '\n';
	SDL_FreeSurface(tileSurf);
	SDL_DestroyTexture(tileText);

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
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 40, 40, 40, 255);
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
	// Play win sfx
	Game::Instance()->GetAM()->LoadSound("audio/winstate.wav");
	Game::Instance()->GetAM()->PlaySound(wsfx::win);

	// Load logo
	wSurf = IMG_Load("img/won.png");
	wText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), wSurf);
	wButtons.push_back(new Button("img/menu.png", { 312,450,400,100 }));


}

void WinState::Update(){
	// Logo size and position
	wdestR.h = 326;
	wdestR.w = 418;
	wdestR.x = 303;
	wdestR.y = 50;

	// Button Update
	for (int i = 0; i < (int)wButtons.size(); i++){
		wButtons[i]->Update();
	}

	// Button event
	if (wButtons[wbtn::m]->Clicked()){
		Game::Instance()->GetFSM()->ChangeState(new TitleState());
	}
}

void WinState::Render(){
	// Set background to white
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 255, 255, 255, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	for (int i = 0; i < (int)wButtons.size(); i++){
		wButtons[i]->Render();
	}
	// Renders the title logo
	SDL_RenderCopy(Game::Instance()->GetRenderer(), wText, NULL, &wdestR);

	State::Render();  // SDL_RenderPresent
}

void WinState::Exit(){
	cout << "Exiting WinState..." << '\n';
	Game::Instance()->GetAM()->ClearMusic();
	Game::Instance()->GetAM()->ClearSounds();
}












// LoseState
void LoseState::Enter(){
	cout << "Entering LoseState..." << '\n';

	// Load death sound and play it
	Game::Instance()->GetAM()->LoadSound("audio/death.wav");
	Game::Instance()->GetAM()->PlaySound(Lsfx::death);

	// Load button
	lButtons.push_back(new Button("img/menu.png", { 312,450,400,100 }));

	// Load the Logo
	LostSurf = IMG_Load("img/wasted.png");
	LostText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), LostSurf);

}


void LoseState::Update(){
	// Logo size and position
	LdestR.h = 100;
	LdestR.w = 500;
	LdestR.x = 262;
	LdestR.y = 200;

	// Button Update
	for (int i = 0; i < (int)lButtons.size(); i++){
		lButtons[i]->Update();
	}

	// Button event
	if (lButtons[lbtn::menu]->Clicked()){
		Game::Instance()->GetFSM()->ChangeState(new TitleState());
	}
}

void LoseState::Render(){
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), 40, 40, 40, 255);
	SDL_RenderClear(Game::Instance()->GetRenderer());
	// Logo
	SDL_RenderCopy(Game::Instance()->GetRenderer(), LostText, NULL, &LdestR);
	// Renders all the buttons
	for (int i = 0; i < (int)lButtons.size(); i++){
		lButtons[i]->Render();
	}
	State::Render();
}



void LoseState::Exit(){
	cout << "Exiting LoseState..." << '\n';
	for (int i = 0; i < (int)lButtons.size(); i++){
		delete lButtons[i];
		lButtons[i] = nullptr;
	}
	SDL_FreeSurface(LostSurf);
	SDL_DestroyTexture(LostText);
	Game::Instance()->GetAM()->ClearSounds();
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
