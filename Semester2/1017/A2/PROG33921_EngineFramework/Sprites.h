#pragma once
#include <vector>
#include "SDL.h"
using namespace std;

class Sprite
{
protected:
	SDL_Rect m_rSrc; // Rectangle for source pixels.
	SDL_Rect m_rDst; // Rectangle for destination window.

public:
	Sprite(SDL_Rect s, SDL_Rect d) :m_rSrc(s), m_rDst(d) {}
	SDL_Rect* GetSrcP() { return &m_rSrc; }
	SDL_Rect* GetDstP() { return &m_rDst; }
};

class AnimatedSprite : public Sprite
{
protected:
	int m_iSprite = 0,	// Which sprite to display for animation.
		m_iSpriteMax,	// How many sprites total.
		m_iFrame = 0,	// Frame counter.
		m_iFrameMax;	// Number of frames per sprite.
	double m_X,		// X coordinate. 
		m_Y,		// Y coordinate.
		m_dSpeed,	// Speed in pixels to move per change.
		m_dRadius,	// Radius of sprite's circle bound.
		m_dAngle;	// Angle of sprite.

public:
	AnimatedSprite(double, double, double, int, int, double, SDL_Rect, SDL_Rect); // Constructor.
	virtual void Update() = 0;
	void Animate();
	virtual void Render();
	void UpdateDst();
	double GetRadius() { return m_dRadius; }
	double GetX() { return m_X; }
	double GetY() { return m_Y; }
};

class Player : public AnimatedSprite
{ // heavily modify this for A2 as you see fit.
public:
	bool m_bIsDead; // Being lazy and making this public.
	int m_iDeathCtr;
	int m_iDeathCtrMax;
	Player(double, double);
	void Update();
	void Render();
};

class Background : public Sprite
{
private:
	int m_iSpeed; // Scroll speed of background.
public:
	Background(SDL_Rect s, SDL_Rect d, int spd):Sprite(s, d), m_iSpeed(spd) {}
	void Update() { m_rDst.x -= m_iSpeed; }
};