#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Box{
private:
	SDL_Rect m_rDst;
	SDL_Rect m_rStartPos;
	SDL_Color m_cColor;
public:
	Box(SDL_Rect r){
		m_rDst = m_rStartPos = r;
		m_cColor = { 255, 255, 255, 255 };
	}

  void Update() {
    if (Game::Instance()->GetMouseBtn(1) && !Game::Instance()->m_bColorSet) {
      m_cColor.r = rand() % 256;
      m_cColor.g = rand() % 256;
      m_cColor.b = rand() % 256;
    }

  }

};
