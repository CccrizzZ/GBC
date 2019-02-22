#pragma once
#include <iostream>
#include <string>
#include "Data.cpp"
#include "Weapon.h"
#include "Armour.h"
using namespace std;

class Player {
private:
  string name = "(Empty Slot)";
  string profession;
  string desc;
  int hp;
  Weapon Wlist[5];
  Armour Alist[5];

public:
  Player(){};
  Player (string name, string profession, string desc, int hp, Weapon w[], Armour a[]);
  virtual ~Player (){};

  // Setters
  void setName(string name);
  void setHp(int hp);
  void setDesc(string d);
  void setProfession(string p);
  void setWeapon(Weapon x[]);
  void setArmour(Armour a[]);

  // Getters
  string getName();
  string getProfession();
  string getDesc();
  int getHp();
  void getWeapon();
  void getArmour();
};

Player::Player(string name, string profession, string desc, int hp, Weapon w[], Armour a[]){
  setName(name);
  setDesc(profession);
  setProfession(desc);
  setHp(hp);
  setWeapon(w);
  setArmour(a);
}

// Setters
void Player::setName(string name){
  this -> name = name;
}

void Player::setHp(int hp){
  this -> hp = hp;
}

void Player::setDesc(string d){
  this -> desc = d;
}

void Player::setProfession(string p){
  this -> profession = p;
}

void Player::setWeapon(Weapon x[]){
  for (int i = 0; i < sizeof(x)/sizeof(x[0]) ; i++) {
    Wlist[i] = x[i];
  }
}

void Player::setArmour(Armour x[]){
  for (int i = 0; i < sizeof(x)/sizeof(x[0]) ; i++) {
    Alist[i] = x[i];
  }
}

// Getters
string Player::getName(){
  return name;
}

string Player::getProfession(){
  return profession;
}

string Player::getDesc(){
  return desc;
}

int Player::getHp(){
  return hp;
}

void Player::getWeapon(){
  cout << '\n' << "--------------------------------" << '\n';
  cout << "Weapons:" << '\n';
  cout << "--------------------------------" << '\n';
  for (int i = 0; i < sizeof(Wlist)/sizeof(Wlist[0]); i++) {
    if (Wlist[i].getDamage()!=0) {
      cout << i+1 <<"."<< '\n';
      cout << "Weapon Name: " << Wlist[i].getName() << '\n';
      cout << "Weapon Discription: " << Wlist[i].getDesc() << '\n';
      cout << "Weapon Damage: " << Wlist[i].getDamage() << '\n';
      cout << "--------------------------------" << '\n';

    }
  }
}

void Player::getArmour(){
  cout << '\n' << "--------------------------------" << '\n';
  cout << "Armours:" << '\n';
  cout << "--------------------------------" << '\n';
  for (int i = 0; i < sizeof(Alist)/sizeof(Alist[0]); i++) {
    if (Alist[i].getAp()!=0) {
      cout << i+1 << "." << Alist[i].getName() << '\n';
      cout << "Discription: " << Alist[i].getDesc() << '\n';
      cout << "Armour Points: " << Alist[i].getAp() << '\n';
      cout << "--------------------------------" << '\n';

    }
  }
}
