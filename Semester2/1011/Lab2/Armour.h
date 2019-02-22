#pragma once
#include <iostream>
#include <string>
using namespace std;

class Armour {
private:
  string name;
  string desc; // Description
  int ap=0; // "Armour point" same as HP

public:
  Armour(){};
  Armour (string name, string desc, int ap);
  ~Armour (){};

  // Setters
  void setName(string name);
  void setDesc(string desc);
  void setAp(int ap);

  // Getters
  string getName();
  string getDesc();
  int getAp();
};

Armour::Armour(string name, string desc, int ap){
  setName(name);
  setDesc(desc);
  setAp(ap);
}

// Setters
void Armour::setName(string name){
  this -> name = name;
}

void Armour::setDesc(string desc){
  this -> desc = desc;
}

void Armour::setAp(int ap){
  this -> ap = ap;
}


// Getters
string Armour::getName(){
  return name;
}

string Armour::getDesc(){
  return desc;
}

int Armour::getAp(){
  return ap;
}
