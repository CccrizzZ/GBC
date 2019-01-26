#pragma once
#include "Game.h"
using namespace std;

class Platform {
private:
  string name;
  string manufacture;

public:
  Platform(){};
  ~Platform (){};
  Platform(const char *n, const char *m, Game g[]);
  Game games[5];
  void setNam(string n);
  void setManu(string m);
  void render();
  string getManu();
  string getName();
};

string Platform::getName(){
  return name;
}

Platform::Platform (const char *n, const char *m, Game g[]){
  setNam(n);
  setManu(m);
  for (int i = 0; i < sizeof(games)/sizeof(games[0]); i++) {
    games[i] = g[i];
  }
}

void Platform::setManu(string m){
  manufacture=m;
}

void Platform::setNam(string n){
  name=n;
}



string Platform::getManu() {
  return manufacture;
}


void Platform::render(){
  char input;
  cout << '\n' << "-----------------" << '\n';
  cout << "Platform Name: ";
  getName();
  cout << '\n';
  cout << "Choose Your Game :" << '\n';
  cout << "1. " << games[0].getNam() << '\n';
  cout << "2. " << games[1].getNam() << '\n';
  cout << "3. " << games[2].getNam() << '\n';
  cout << "4. " << games[3].getNam() << '\n';
  cout << "5. " << games[4].getNam() << '\n';
  cout << "press \'e\' to return to previous menu" << '\n';
  input = _getch();
  switch (input) {
    case 'e':

    break;
    case '1':
      games[0].render();

    break;
    case '2':
      games[1].render();

    break;
    case '3':
      games[2].render();

    break;
    case '4':
      games[3].render();

    break;
    case '5':
      games[4].render();

    break;
    default:
    cout << "Please select choices given above !" << '\n';
    break;
  }

}
