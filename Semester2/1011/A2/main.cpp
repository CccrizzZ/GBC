#include <iostream>
#include "Game.h"
using namespace std;


int main() {
  cout << "--------------------" << '\n';
  cout << "Zombie Apocalypse" << '\n';
  cout << "--------------------" << '\n' << '\n';

  Game* game1 = new Game();

  game1->Preparation();

  system("pause");
  return 0;
}
