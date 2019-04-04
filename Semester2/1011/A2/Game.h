#pragma once
#include <iostream>
#include <string>
using namespace std;



class Game {
public:
  Game (){};
  ~Game ();

  void Preparation();
  void OutOfTown();
  void GasStationLoot();
  void RedAlarm();
  void Barn();
  void Supermarket();
  void Arrival();
};
