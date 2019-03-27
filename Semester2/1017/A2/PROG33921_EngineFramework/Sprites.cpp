#include <algorithm> // For min/max.
#include <cmath>	 // For cos/sin.
#include "Game.h"
#include "Sprites.h"
using namespace std;

AnimatedSprite::AnimatedSprite(double x, double y, double a, int fm, int sm, double spd,
	SDL_Rect s, SDL_Rect d): Sprite(s, d), m_X(x), m_Y(y), m_dAngle(a), m_iFrameMax(fm),
	m_iSpriteMax(sm), m_dSpeed(spd) {}

void AnimatedSprite::Animate()
{
	m_iFrame++;
	if (m_iFrame == m_iFrameMax)
	{
		m_iFrame = 0;
		m_iSprite++;
		if (m_iSprite == m_iSpriteMax)
		{
			m_iSprite = 0;
			if (m_rSrc.y == 64)
				m_rSrc.y = -64;
		}
	}
}

void AnimatedSprite::Render(){
	SDL_RenderCopyEx(Game::Instance()->GetRenderer(), Game::Instance()->GetSprTexture(), &m_rSrc, &m_rDst, m_dAngle, nullptr, SDL_FLIP_NONE);
}

void AnimatedSprite::UpdateDst(){
	m_rDst.x = (int)(m_X - m_rDst.w / 2);
	m_rDst.y = (int)(m_Y - m_rDst.h / 2);
}

Player::Player(double x, double y) : AnimatedSprite(x+32, y+32, 90, 3, 4, 6.0f, { 0, 0, 64, 64 }, { (int)x, (int)y, 64, 64 }){
	m_bIsDead = false;
	m_iDeathCtr = 0;
	m_iDeathCtrMax = 60;
	m_dRadius = 18;
}

void Player::Update(){
	this->Animate();
	m_rSrc.x = m_rSrc.w * m_iSprite; // Update animation.
	if (m_bIsDead)
		return;
	if (Game::Instance()->KeyDown(SDL_SCANCODE_A) && m_X > 32)
		m_X -= m_dSpeed;
	else if (Game::Instance()->KeyDown(SDL_SCANCODE_D) && m_X < 992)
		m_X += m_dSpeed;
	if (Game::Instance()->KeyDown(SDL_SCANCODE_W))
		m_Y -= m_dSpeed;
	else if (Game::Instance()->KeyDown(SDL_SCANCODE_S))
		m_Y += m_dSpeed;
	this->UpdateDst(); // Send x and y to dest rectangle.
}

void Player::Render(){
	this->AnimatedSprite::Render(); // Invoking base class Render().
}
