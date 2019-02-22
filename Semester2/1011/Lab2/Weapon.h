#pragma once
#include <iostream>
#include <string>
using namespace std;

class Weapon {
private:
  string name;
  string desc;
  int damage = 0;

public:
  Weapon(){};
  Weapon (string name, string desc, int damage);
  ~Weapon (){};

  // Setters
  void setName(string name);
  void setDesc(string desc);
  void setDamage(int damage);

  // Getters
  string getName();
  string getDesc();
  int getDamage();
};

Weapon::Weapon(string name, string desc, int damage){
  setName(name);
  setDesc(desc);
  setDamage(damage);
}


// Setters
void Weapon::setName(string name){
  this -> name = name;
}

void Weapon::setDesc(string desc){
  this -> desc = desc;
}

void Weapon::setDamage(int damage){
  this -> damage = damage;
}



// Getters
string Weapon::getName(){
  return name;
}

string Weapon::getDesc(){
  return desc;
}

int Weapon::getDamage(){
  return damage;
}
