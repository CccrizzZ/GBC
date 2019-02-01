#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Mother(Fucking)class
class Enemy {
private:
  string name;
  int HP;
  int damage;

public:
  // Seed For Rand() Fuction
  Enemy(){srand (time(NULL));};
  ~Enemy(){};
  // Getters
  string getName();
  int getHP();
  int getDamage();

  // Setters
  void setName(string x);
  void setHP(int y);
  void setDamage(int z);

};

// Enemy Class Functions
string Enemy::getName(){
  return name;
}

int Enemy::getHP(){
  return HP;
}

int Enemy::getDamage(){
  return damage;
}

void Enemy::setName(string x) {
  name = x;
}

void Enemy::setHP(int y){
  HP = y;
}

void Enemy::setDamage(int z) {
  damage = z;
}










// Son(OB)Classes
// Forest of Mist Mob
class Orc : public Enemy {
public:
  Orc();
  ~Orc(){};
  // Actions
  void Die();
  void Taunt();
  void NormalAtt();
};

// Orc Functions
Orc::Orc(){
  cout << "[An Orc Appears]" << '\n';
  setName("Orc");
  setHP(90);
  setDamage(40);
}

void Orc::Die(){
  cout << '\n' << "Arrrrrr!!!!!" << '\n';
  cout << "Orc died, Black Blood Dripped All Over the Grass......" << '\n' << '\n' ;
}

void Orc::Taunt() {
  // Random number between 5-100
  // About 20% of chance first taunt will display
  // About 80% of chance second taunt will display
  if ((rand() % 100 + 5) % 2 != 0) {
    cout << "Ill Kill For The Horde!" << '\n';
  }else{
    cout << "Grrrr! Ill Smash You!" << '\n';
  }
}

void Orc::NormalAtt(){
  cout << "Baaaaam!!!!!!" << '\n';
  cout << "Your Lost 40 HP" << '\n';
}








// Black Water Fall Mob
class Murloc : public Enemy {
public:
  Murloc();
  ~Murloc(){};
  // Actions
  void Die();
  void Taunt();
  void NormalAtt();
};

// Murloc Functions
Murloc::Murloc(){
  cout << "[A Murloc Appears]" << '\n';
  setName("Murloc");
  setHP(60);
  setDamage(20);
}

void Murloc::Die(){
  cout << '\n' << "Arrrrrr!!!!!" << '\n';
  cout << "Murloc died, Purple Blood Dripped All Over the Shore......" << '\n' << '\n' ;
}

void Murloc::Taunt() {
  // Seed For Rand() Fuction
  // Random number between 1-100
  // About 20% of chance first taunt will display
  // About 80% of chance second taunt will display
  if ((rand() % 100 + 5) % 2 != 0) {
    cout << "I Will Eat Your Flesh With My Brothers!" << '\n';
  }else{
    cout << "You Weak Humans!" << '\n';
  }
}

void Murloc::NormalAtt(){
  cout << "slaaaaash!!!!!!" << '\n';
  cout << "Your Lost 20 HP" << '\n';
}
