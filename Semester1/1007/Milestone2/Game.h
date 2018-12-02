#pragma once
#include <string>
#include <conio.h>
using namespace std;



class Sprite{
public:
  char m_cOutput;
};




// Class foe Level Object
class LOTile: public Sprite{
public:
  int m_x;
  int m_y;

  LOTile(int m_x, int m_y){
    this -> m_x = m_x;
    this -> m_y = m_y;
  }
  LOTile(){}
};





class BGTile: public Sprite{
public:
  char value;
  bool m_isObstacle;
  bool m_isHazard;
  bool m_isDoor;

  void SetBGTile(const char x){
    this -> m_cOutput = x;
  }

  bool isObstacle(){
    return m_isObstacle;
  }

  bool isHazard(){
    return m_isHazard;
  }

  bool isDoor(){
    return m_isDoor;
  }

};






class Player: public LOTile{
public:
  Player(){
    this -> m_cOutput = '@';
  }
};




class Door: public LOTile{
public:
  int m_iToLevel; // Represents an index of a "Level" object. requires when collision with door happens
  int m_iDestX; // Spawn point after teleport
  int m_iDestY;
  Door(){}


  void SetDoor(const int m_x, const int m_y, const int m_iToLevel, const int m_iDestX, const int m_iDestY) {
    this -> m_x = m_x;
    this -> m_y = m_y;
    this -> m_iToLevel = m_iToLevel;
    this -> m_iDestX = m_iDestX;
    this -> m_iDestY = m_iDestY;
  }
};




class Level{
public:
  int m_iNumDoors; // ????????? Actual Door counter???????
  BGTile map[24][32];
  Door doors[3]; // Stores doors in this Level
  Level(){
    m_iNumDoors = 0;
  }


  void AddDoor(const int m_x, const int m_y, const int m_iToLevel, const int m_iDestX, const int m_iDestY) {
    if (m_iNumDoors < 3) {
      doors[m_iNumDoors++].SetDoor(m_x,m_y,m_iToLevel,m_iDestX,m_iDestY);
      m_iNumDoors++;
    }else{
      cout << "Can't add more doors!" << '\n';
    }
  }

};
