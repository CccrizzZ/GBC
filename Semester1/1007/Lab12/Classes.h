#pragma once

class LOTile{
public:
  int m_x;
  int m_y;

  LOTile(const int m_x=0, const int m_y=0){
    this -> m_x = m_x;
    this -> m_y = m_y;
  }
};

// Call this specific constructor public LOTile
class Door : public LOTile{
public:
  int m_iToLevel;
  int m_iDestX;
  int m_iDestY;
};
