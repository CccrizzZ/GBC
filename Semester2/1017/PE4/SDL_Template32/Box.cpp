#include "Game.h"

void Box::Update() {
	int mx = Game::Instance()->GetMouseX();
	int my = Game::Instance()->GetMouseY();
	if (mx < (m_rDst.x + m_rDst.w) && mx > m_rDst.x && // If cursor is within X bounds
		my < (m_rDst.y + m_rDst.h) && my > m_rDst.y) {  // And cursor is within Y bounds

		if (Game::Instance()->GetMouseBtn(0)) {
			m_rDst.x = mx - m_rDst.w/2;
			m_rDst.y = my - m_rDst.h/2;
		}

		if (Game::Instance()->GetMouseBtn(1) && !Game::Instance()->m_bColorSet) {
			m_cColor.r = rand() % 256;
			m_cColor.g = rand() % 256;
			m_cColor.b = rand() % 256;
			Game::Instance()->m_bColorSet = true;
		}
	}
}

void Box::Render() {
	SDL_SetRenderDrawColor(Game::Instance()->GetRenderer(), m_cColor.r, m_cColor.g, m_cColor.b, m_cColor.a);
	SDL_RenderFillRect(Game::Instance()->GetRenderer(), &m_rDst);
}
