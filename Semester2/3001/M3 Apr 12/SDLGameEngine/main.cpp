#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "DemoProjectGame.h"
using namespace std;


Game* game = new DemoProjectGame();

int main(int argc, char* args[]){
	srand(time(NULL));

	// Run awake before init
	game->Awake();

	// If game initialize run game loop
	if( !game->Init() ) {
		printf( "Failed to initialize!\n" );
	}else{
		game->Setup();
		while (!Game::quit){
			game->Update();
		}
	}

	//Free resources and close SDL
	game->End();
	system("pause");
	return 0;
}
