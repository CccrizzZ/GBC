#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;


class Game {
public:
  // Variables
  string pnam;
  string pprof;

  // Functions
  Game (){};
  ~Game ();
  Game(string PlayerName, string PlayerProfession);
  string getPprof();
  string getPnam();
  void runGame();
  void Welcome();
};

Game::Game(string PlayerName, string PlayerProfession){
  pnam = PlayerName;
  pprof = PlayerProfession;
}

Game::~Game(){
  cout << '\n' << "------------------------" << '\n';
  cout << "GAME OVER!" << '\n';
  cout << "------------------------" << '\n' << '\n';
}

string Game::getPprof(){
  return pprof;
}

string Game::getPnam(){
  return pnam;
}

void Game::runGame(){
  // Flag For Game Running
  bool running = true;
  while (running) {
    char input;
    cout << '\n' << "------------------------" << '\n';
    cout << "Where Do You Wanna Go?" << '\n';
    cout << "1. Forest of Mist" << '\n';
    cout << "2. Black Waterfall" << '\n';
    cout << "3. Town Pub" << '\n';
    cout << "Press \"E\" To Exit The Game" << '\n';
    input = _getch();
    switch (input) {
      case 'e':
        running = false;
      break;
      case 'E':
        running = false;
      break;
      case '1':
        ForestOfMist();
      break;
      case '2':
        BlackWaterFall();
      break;
      case '3':
        TownPub();
      break;
      default:
        cout << "Please Choose From The Option Provided Above!" << '\n';
      break;
    }
  }
}
