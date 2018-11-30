// #define SDL_MAIN_HANDLED
#include <iostream>
#include <fstream>
#include <string>
// #include <SDL.h> okay~
#include "Game.h"
using namespace std;

bool BuildMap(Level& l, const char* n);
void PrintMap(Level& l, const Player& p);


int main(){
  // Variables
  bool quit = true;
  char input;
  Player player;

  // Path for Levels text
  Level levels[5];

  if (BuildMap(levels[0], "Level_Home.txt") == 1) {
    int currLevel=0;

    while (!quit) {
      input = _getch();
      switch (input){
        case 'w':
        case 'W':
        if (player.m_y > 0 && levels[currLevel].map[player.m_y -1][player.m_x].m_isHazard==true){
          cout << "YOU GOT KILLED BY MOTHER NATURE!!!" << '\n';
          cout << "GAME OVER!!!" << '\n';
          break;
        }else if (levels[currLevel].map[player.m_y -1][player.m_x].m_isObstacle!=true){
          player.m_y--;
        }
        break;
        case 's':
        case 'S':
        if (player.m_y < 24-1 && levels[currLevel].map[player.m_y + 1][player.m_x].m_isHazard==true){
          cout << "YOU GOT KILLED BY MOTHER NATURE!!!" << '\n';
          cout << "GAME OVER!!!" << '\n';
          quit = true;
        }else if (levels[currLevel].map[player.m_y + 1][player.m_x].m_isObstacle!=true) {
          player.m_y++;
        }
        break;
        case 'a':
        case 'A':
        if (player.m_x > 0 && levels[currLevel].map[player.m_y][player.m_x - 1].m_isHazard==true){
          cout << "YOU GOT KILLED BY MOTHER NATURE!!!" << '\n';
          cout << "GAME OVER!!!" << '\n';
          quit = true;
        }else if (levels[currLevel].map[player.m_y][player.m_x - 1].m_isObstacle!=true) {
          player.m_x--;
        }
        break;
        case 'd':
        case 'D':
        if (player.m_x < 32-1 && levels[currLevel].map[player.m_y][player.m_x + 1].m_isHazard==true){
          cout << "YOU GOT KILLED BY MOTHER NATURE!!!" << '\n';
          cout << "GAME OVER!!!" << '\n';
          quit = true;
        }else if (levels[currLevel].map[player.m_y][player.m_x + 1].m_isObstacle!=true){
          player.m_x++;
        }
        break;
        case 'q':
        case 'Q':
        quit = true;
        break;
      }
      system("cls");
    }
  }
  return 0;
}


bool BuildMap(Level& l, const char* n){
  ifstream inFile(n);
  if (inFile.is_open()) {
    // Traverse 2d array of this object
    for (int row = 0; row < 24; row++) {
      for (int col = 0; col < 32; col++) {
        inFile >> l.map[row][col].value; // Putting all text character into the 2d array of Level object
        if (l.map[row][col].value=='~') {
          l.map[row][col].m_isHazard = true; // Mark for Hazard
        }else if (l.map[row][col].value=='+') {
          l.map[row][col].m_isObstacle = true; // Mark for Obstacle
        }
      }
    }
    inFile.close();
    return 0; // If complete return 0
  }
  return 1; // If no file return 1
}

void PrintMap(Level& l, const Player& p){
  // Traverse 2d array of this object
  for (int row = 0; row < 24; row++) {
    for (int col = 0; col < 32; col++) {
      // If tile's X and Y equals player's X and Y cout "@"
      if (row == p.m_y && col == p.m_x) {
        cout << "@";
      }else{
        cout << l.map[row][col].value;
      }
    }
    cout << "\n"; // Break in the end of every row
  }
}
