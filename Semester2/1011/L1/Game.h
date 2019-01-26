#pragma once
#include <iostream>
#include <string>
#include "Achievement.h"
using namespace std;


class Game {
private:
  string name;
  string publisher;
  string developer;

public:
  Game (){};
  ~Game (){};
  Game(const char *n, const char *p, const char *d, Achievement a[]);
  Achievement myList[5];
  void setName(string n);
  void setPub(string p);
  void setDev(string d);
  void setAchi(Achievement a[]);
  string getNam();
  string getPub();
  string getDev();
  void getAchi();
  void render();
};



Game::Game(const char *n, const char *p, const char *d, Achievement a[]){
  setName(n);
  setPub(p);
  setDev(d);
  for (int i = 0; i < sizeof(myList)/sizeof(myList[0]); i++) {
    myList[i] = a[i];
  }
}

void Game::setName(string n){
  name=n;
}

void Game::setPub(string p){
  publisher=p;
}

void Game::setDev(string d){
  developer=d;
}

void Game::setAchi(Achievement a[]){
  for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
    myList[i]=a[i];
  }
}

string Game::getNam(){
  return name;
}

string Game::getPub(){
  return publisher;
}

string Game::getDev(){
  return developer;
}





void Game::render(){
  char in;

  cout << "-----------------" << '\n';
  cout << '\n';
  cout << "Game Title: " << name << '\n';

  cout << "Publisher: " << publisher << '\n';

  cout << "Developer: " << developer << '\n'<< '\n';

  cout << "Achievement List: "<< '\n';
  cout << "-----------------" << '\n';
  for (int i = 0; i < 5; i++) {
    cout << '\n' << "Title: " << myList[i].getTitle() << '\n';
    cout << "Description: " << myList[i].getDes() << '\n';
    cout << "Score: " << myList[i].getScore() << '\n'<< '\n';
    cout << "-----------------" << '\n';
  }
  cout << '\n';
  std::cout << "Press Any Key to Exit" << '\n';
  in = _getch();
  switch (in) {
    default:

    break;
  }

}
