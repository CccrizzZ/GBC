#include "pch.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Loop.cpp"
#include "Game.h"
using namespace std;


void Welcome();

int main(){
  Welcome();
  return 0;
}




// Game Manu
void Welcome(){
  // Variables
  bool r = true;
  string x; // Name
  string pro; // Profession
  char y; // Y/N

  // Welcome Screen
  cout << "[You Spawn All Naked on A Piece of Cloud]" << '\n';
  cout << "Developer: Get Up! Mortal!" << '\n' << '\n';
  cout << "------------------------" << '\n';
  cout << "Please Enter Your Name: " << '\n';
  cin >> x;
  cout << "Your name is " << x << '\n';
  cout << "------------------------" << '\n' << '\n';

  // Choose Profession Loop
  while (r == true) {
    char input;
    cout << "------------------------" << '\n';
    cout << "Please Choose Your Profession: " << '\n';
    cout << "1. Knight" << '\n';
    cout << "2. Wizard" << '\n';
    input = _getch();

    switch (input) {
      case '1':
        cout << "Your Profession Is: Knight" << '\n';
        cout << "------------------------" << '\n' << '\n';
        pro = "Wizard";
        r = false;
      break;
      case '2':
        cout << "Your Profession Is: Wizard" << '\n';
        cout << "------------------------" << '\n' << '\n';
        pro = "Wizard";
        r = false;
      break;
      default:
        cout << "Please Choose From The Option Provided Above!" << '\n';
        cout << "------------------------" << '\n' << '\n';
      break;
    }
  }




  // Kick You Into the Game Loop
  cout << "------------------------" << '\n';
  cout << "Developer: Are You Ready to Start Your Advanture ?  (Y/N)" << '\n';
  y = _getch();
  switch (y) {
    case 'y':
      cout << '\n' << "Developer: Welcome to Peaceful Island !" << '\n';
      cout << "------------------------" << '\n' << '\n';

    break;
    case 'Y':
      cout << '\n' << "Developer: Welcome to Peaceful Island !" << '\n';
      cout << "------------------------" << '\n' << '\n';


    break;
    default:
      cout << "Developer: \"GO! YOU MORTAL!\", [You got Kicked off The Edge of The Cloud....]" << '\n';
      cout << "------------------------" << '\n' << '\n';
    break;
  }
  Game newgame = Game(x,pro);
  newgame.runGame();

}
