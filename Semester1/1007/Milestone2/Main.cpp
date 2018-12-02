// #define SDL_MAIN_HANDLED
#include <iostream>
#include <fstream>
#include <string>
// #include <SDlevels.h> okay~
#include "Game.h"
using namespace std;

// Unfinished and full of bugs 
// Sorry this is really messy. (I came from Javascript)
// And I didn't quite understand the structure of the instructions.
// Ill start drawing mind maps for my code on weeknds.
// + is Obstacle
// ~ is lava and water(Hazard)

bool BuildMap(Level& l, string n);
void PrintMap(Level& l, const Player& p);


int main(){
  // Variables
  bool quit = false;
  char input;
  Player player;
  // Path for Levels text
  string files[]={
    "Level_Home.txt",
    "Level_Town.txt",
    "Level_Forest.txt",
    "Level_Volcano.txt"
  };
  Level levels[5];
  int currLevel=0;
  player.m_y=10;
  player.m_x=10;

  if (BuildMap(levels[currLevel], files[currLevel]) == 0) {

    while (!quit) {
      BuildMap(levels[currLevel], files[currLevel]);
      PrintMap(levels[currLevel], player);
      input = _getch();
      switch (input){
        case 'w':
        case 'W':
        if (player.m_y > 0 && levels[currLevel].map[player.m_y -1][player.m_x].m_isHazard==true){
          quit = true;
          cout << "YOU GOT KILLED BY MOTHER NATURE!!!" << '\n';
          cout << "GAME OVER!!!" << '\n';
        }else if (levels[currLevel].map[player.m_y -1][player.m_x].isDoor()==true){
          if (levels[currLevel].map[player.m_y -1][player.m_x].value=='D') {
            currLevel=1;
            break;
          }else if (levels[currLevel].map[player.m_y -1][player.m_x].value=='F') {
            currLevel=2;
            break;
          }else if (levels[currLevel].map[player.m_y -1][player.m_x].value=='V') {
            currLevel=3;
            break;
          }else if (levels[currLevel].map[player.m_y -1][player.m_x].value=='T') {
            currLevel=1;
            break;
          }
        }else if (levels[currLevel].map[player.m_y -1][player.m_x].m_isObstacle!=true){
          player.m_y--;
        }
        break;
        case 's':
        case 'S':
        if (player.m_y < 24-1 && levels[currLevel].map[player.m_y + 1][player.m_x].m_isHazard==true){
          quit = true;
          cout << "YOU GOT KILLED BY MOTHER NATURE!!!" << '\n';
          cout << "GAME OVER!!!" << '\n';
        }else if (levels[currLevel].map[player.m_y + 1][player.m_x].isDoor()==true){
          if (levels[currLevel].map[player.m_y + 1][player.m_x].value=='D') {
            currLevel=1;
            break;
          }else if (levels[currLevel].map[player.m_y + 1][player.m_x].value=='F') {
            currLevel=2;
            break;
          }else if (levels[currLevel].map[player.m_y + 1][player.m_x].value=='V') {
            currLevel=3;
            break;
          }else if (levels[currLevel].map[player.m_y + 1][player.m_x].value=='T') {
            currLevel=1;
            break;
          }
        }else if (levels[currLevel].map[player.m_y + 1][player.m_x].m_isObstacle!=true) {
          player.m_y++;
        }
        break;
        case 'a':
        case 'A':
        if (player.m_x > 0 && levels[currLevel].map[player.m_y][player.m_x - 1].m_isHazard==true){
          quit = true;
          cout << "YOU GOT KILLED BY MOTHER NATURE!!!" << '\n';
          cout << "GAME OVER!!!" << '\n';
        }else if (levels[currLevel].map[player.m_y][player.m_x - 1].isDoor()==true){
          if (levels[currLevel].map[player.m_y][player.m_x - 1].value=='D') {
            currLevel=1;
            break;
          }else if (levels[currLevel].map[player.m_y][player.m_x - 1].value=='F') {
            currLevel=2;
            break;
          }else if (levels[currLevel].map[player.m_y][player.m_x - 1].value=='V') {
            currLevel=3;
            break;
          }else if (levels[currLevel].map[player.m_y][player.m_x - 1].value=='T') {
            currLevel=1;
            break;
          }
        }else if (levels[currLevel].map[player.m_y][player.m_x - 1].m_isObstacle!=true) {
          player.m_x--;
        }
        break;
        case 'd':
        case 'D':
        if (player.m_x < 32-1 && levels[currLevel].map[player.m_y][player.m_x + 1].m_isHazard==true){
          quit = true;
          cout << "YOU GOT KILLED BY MOTHER NATURE!!!" << '\n';
          cout << "GAME OVER!!!" << '\n';
        }else if (levels[currLevel].map[player.m_y][player.m_x + 1].isDoor()==true){
          if (levels[currLevel].map[player.m_y][player.m_x + 1].value=='D') {
            currLevel=1;
            break;
          }else if (levels[currLevel].map[player.m_y][player.m_x + 1].value=='F') {
            currLevel=2;
            break;
          }else if (levels[currLevel].map[player.m_y][player.m_x + 1].value=='V') {
            currLevel=3;
            break;
          }else if (levels[currLevel].map[player.m_y][player.m_x + 1].value=='T') {
            currLevel=1;
            break;
          }
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
  system("pause");
  return 0;
}


















bool BuildMap(Level& l, string n){
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
        } else if (l.map[row][col].value=='D') {
          l.map[row][col].m_isDoor=true;
          if (l.m_iNumDoors<3) {
            l.AddDoor(row, col, 1, 10,10);
          }
        }else if (l.map[row][col].value=='T') {
          l.map[row][col].m_isDoor=true;
          if (l.m_iNumDoors<3) {
            l.AddDoor(row, col, 2, 10,19);
          }
        }else if (l.map[row][col].value=='F') {
          l.map[row][col].m_isDoor=true;
          if (l.m_iNumDoors<3) {
            l.AddDoor(row, col, 3, 2,2);
          }
        }else if (l.map[row][col].value=='V') {
          l.map[row][col].m_isDoor=true;
          if (l.m_iNumDoors<3) {
            l.AddDoor(row, col, 4, 23,17);
          }
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
