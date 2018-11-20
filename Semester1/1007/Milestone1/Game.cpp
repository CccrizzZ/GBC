#include "Game.h"
using namespace std;

bool Game::init(
  const char* title,
  int xpos,
  int ypos,
  int width,
  int height,
  int flags
){
  // Attempts to initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    cout << "SDL successfully initialized!" << '\n';
    // Create the "window"
    m_pWindow = SDL_CreateWindow(
                title,
                xpos,
                ypos,
                width,
                height,
                flags
              );
    if (m_pWindow!=0) {
      cout << "Window successfully initialized!" << '\n';

      // Create renderer
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
      if (m_pRenderer!=0) {
        cout << "Renderer successfully created!" << '\n';
        SDL_SetRenderDrawColor(
          m_pRenderer,
          255,
          255,
          255,
          255
        );

      }else{
        cout << "Failed to create renderer!" << '\n';
      }
    }
  }
}

bool Game::running(){

}

void Game::update(){

}

void Game::handleEvents(){
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
      m_bRunning = false;
      break;
    }
  }
}

void Game::render(){
  // Clear the screen to the draw color;
  SDL_RenderClear(m_pRenderer);
  // Draw new.
  SDL_RenderPresent(m_pRenderer);
}

void Game::clean(){
  cout << "cleaning game....." << '\n';
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}
