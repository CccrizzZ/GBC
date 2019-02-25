#pragma once
#include <iostream>
#include <cstdint>
#include "SDL.h"
#include "SDL_image.h"

class Box{
private:
	SDL_Rect m_rDst;
	SDL_Rect m_rStartPos;
	SDL_Color m_cColor;
public:

	// Constructor
	Box(SDL_Rect rect, int r, int g, int b){

		// int to unit8 conversion
		uint8_t red = static_cast<uint8_t>(r);
		uint8_t green = static_cast<uint8_t>(g);
		uint8_t blue = static_cast<uint8_t>(b);

		// Set the positions
		m_rDst = m_rStartPos = rect;

		// Set m_cColor
		m_cColor = { red, green, blue, 255 };
	}

	void Update();
	void Render();
	void Reset() {
		m_rDst = m_rStartPos;
	}


};
