#include <algorithm> // For min/max.
#include <cmath>	 // For cos/sin.
#include "Game.h"
#include "Sprites.h"

using namespace std;

AnimatedSprite::AnimatedSprite(SDL_Rect s, SDL_Rect d): Sprite(s, d) {}

void AnimatedSprite::Animate()
{
	m_iFrame++;
	if (m_iFrame == m_iFrameMax)
	{
		m_iFrame = 0;
		m_iSprite++;
		if (m_iSprite == m_iSpriteMax)
		{
			m_iSprite = 0; // 0 will be replaced with m_iSpriteMin
		}
	}
}

Player::Player(SDL_Rect s, SDL_Rect d):AnimatedSprite(s,d)
{
	m_bGrounded = false;
	m_dAccelX = m_dAccelY = m_dVelX = m_dVelY = 0.0;
	m_dGrav = GRAV;
	m_dMaxAccelX = 2.0;
	m_dMaxVelX = 6.0;
	m_dMaxVelY = m_dGrav;
	m_dDrag = 0.925;
	m_iDir = 1;
}

void Player::SetDir(int dir)
{ // Will be used to set direction of sprite. Just added it for you.
	m_iDir = dir;
}

void Player::MoveX()
{
	m_dAccelX += 0.25 * m_iDir; // Change to speed var.
}

void Player::Update()
{
	m_dAccelX = min(max(m_dAccelX, -(m_dMaxAccelX)), (m_dMaxAccelX));
	m_dVelX = (m_dVelX + m_dAccelX) * m_dDrag;
	m_dVelX = min(max(m_dVelX, -(m_dMaxVelX)), (m_dMaxVelX));
	m_rDst.x += (int)m_dVelX;
	m_rDst.x = min(max(m_rDst.x, 0), 1024-128);
	m_dVelY += m_dAccelY + m_dGrav/7;
	m_dVelY = min(max(m_dVelY, -(m_dMaxVelY * 10)), (m_dMaxVelY));
	m_rDst.y += (int)m_dVelY;
}

Obstacle::Obstacle(int x, bool b, SDL_Rect src, 
	SDL_Rect dst, bool p, bool r)
{
	m_iX = x;
	if (b) // Construct the Sprite
	{
		m_pSprite = new Sprite(src,dst);
		m_bIsPlatform = p;
		m_bRotates = r;
	}
}

Obstacle::~Obstacle()
{
	if (m_pSprite != nullptr)
	{
		delete m_pSprite;
		m_pSprite = nullptr;
	}
}