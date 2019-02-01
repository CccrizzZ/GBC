#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
private:
  string Pname;
  string Profession;
  int playerHP;
  int NormalAttDamage;
  int SpecialAttDamage;

public:
  Player (){};
  virtual ~Player (){};

  // Getters
  string getName();
  int getHP();
  int getNormDamage();
  int getSpecDamage();


  // Setters
  void setName(string Pname);
  void setProf(string Profession);
  void setHP(int playerHP);
  void setNormDamage(int NormalAttDamage);
  void setSpecDamage(int SpecialAttDamage);
};


// Getter
string Player::getName(){
  return Pname;
}

int Player::getHP(){
  return playerHP;
}

int Player::getNormDamage(){
  return NormalAttDamage;
}

int Player::getSpecDamage(){
  return SpecialAttDamage;
}


// Setter
void Player::setName(string Pname) {
  this -> Pname = Pname;
}

void Player::setProf(string Profession) {
  this -> Profession = Profession;
}

void Player::setHP(int playerHP) {
  this -> playerHP = playerHP;
}

void Player::setNormDamage(int NormalAttDamage) {
  this -> NormalAttDamage = NormalAttDamage;
}

void Player::setSpecDamage(int SpecialAttDamage) {
  this -> SpecialAttDamage = SpecialAttDamage;
}





// Knight Profession
class Knight : public Player{
public:
	Knight();
	~Knight(){};
  Knight(string Pn);
  void Die();
  void NormalAtt();
  void SpecialAtt();
};

Knight::Knight(string Pn){
  setName(Pn);
  setProf("Knight");
  setHP(100);
  setNormDamage(20);
  setSpecDamage(40);
}

void Knight::Die(){
  cout << '\n' << "Ohhhhh!!!!!" << '\n';
  cout << "[You Died, You Saw Your Own Gut Came Out.]" << '\n';
  cout << "[Your Life Memory Flashed Over Infront of Your Eyes......]" << '\n';
}





//  Wizard Profession
class Wizard : public Player{
public:
  Wizard ();
  ~Wizard (){};
  Wizard(string Pn);
  void Die();
  void NormalAtt();
  void SpecialAtt();
};

Wizard::Wizard(string Pn){
  setName(Pn);
  setHP(80);
  setNormDamage(30);
  setSpecDamage(90);
}

void Wizard::Die(){
  cout << '\n' << "awwwwwww!!!!!" << '\n';
  cout << "[You Died, Your Blood Flood the Ground Underneath You]." << '\n';
  cout << "[Euphoric Rushed Inside Your Brain.]" << '\n';
  cout << "[Your are Falling Into Void..........]" << '\n';
}
