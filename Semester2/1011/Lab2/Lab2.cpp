#include "pch.h"
#include <string>
#include "conio.h"
#include <iostream>
#include "Player.h"
using namespace std;

// Up to 3 characters
Player pList[3];

// Prototype
void Select(string playername);
void Build(int slotnum, string myname);
void Readlist(Player p[]);

int main() {
  // Welcome
  cout << "--------------------------------" << '\n';
  cout << "Welcome to Team Fortess Classic Character Builder!" << '\n';
  cout << "--------------------------------" << '\n' << '\n';
  string pname;
  cout << '\n' << "Please enter your name" << '\n';
  cin >> pname;
  Select(pname);
  Readlist(pList);
  return 0;
}






void exam(int z) {
  if (pList[z].getHp()!=0) {
    cout << '\n' << "--------------------------------" << '\n';
    cout << "Player Name: " << pList[z].getName() << '\n';
    cout << "HP: " << pList[z].getHp() << '\n';
    cout << "Profession: " <<  pList[z].getDesc() << '\n';
    cout << "Discription: " << pList[z].getProfession() << '\n' << '\n';
    pList[z].getWeapon();
    pList[z].getArmour();
  }else{
    cout << '\n' << "**Empty Slot**" << '\n';
  }
}



void Readlist(Player p[]) {
  bool quit = false;

  while (!quit) {
    cout << '\n' << "--------------------------------" << '\n';
    cout << "Select your charachter to see details" << '\n';
    for (int i = 0; i < 3; i++) {
      cout << i+1 << ". " << pList[i].getName() << '\n';
    }
    cout << "Press \'E\' to exit" << '\n';
    cout << "--------------------------------" << '\n';


    char input;
    input = _getch();
    switch (input) {
      case 'e':
      case 'E':
        quit = true;
      break;
      case '1':
        exam(0);
        quit = false;
      break;
      case '2':
        exam(1);
        quit = false;
      break;
      case '3':
      quit = false;
        exam(2);
      break;
      default:
        cout << '\n' << "Please select from above!" << '\n';
      break;
    }
  }
}





void Select(string playername) {
  bool selecting = true;
  while (selecting) {
    char input;
    cout << '\n' << "**You are in editing mode**" << '\n';
    cout << "Select a slot below:" << '\n';
    for (int i = 0; i < 3; i++) {
      cout << i+1 << ". " << pList[i].getName() << '\n';
    }
    cout << "Press \'E\' to exit" << '\n';
    input = _getch();
    switch (input) {
      case 'e':
      case 'E':
        selecting = false;
      break;
      case '1':
        Build(1,playername);
      break;
      case '2':
        Build(2,playername);
      break;
      case '3':
        Build(3,playername);
      break;
      default:
        cout << '\n' << "Please select from above!" << '\n';
      break;
    }
    if (pList[3].getHp()!=0) {
      selecting = false;
    }
  }
}

void Build(int slotnum, string myname) {
  int slot = slotnum-1;
  bool prof = true;

  while (prof) {
    char input;
    cout << '\n' << myname << ", "<< "select your profession:" << '\n';
    cout << "1.Scout" << '\n';
    cout << "2.Soldier" << '\n';
    cout << "3.Pyro" << '\n';
    cout << "4.Heavy" << '\n';
    cout << "Press \'E\' to exit" << '\n';
    input = _getch();
    switch (input) {
      case 'e':
      case 'E':
        prof = false;
      break;
      case '1':
        pList[slot] = Player(myname+"(Scout)", "Scout", "Fast but fragile", 100, PyroW, PyroA);
        prof = false;
      break;
      case '2':
        pList[slot] = Player(myname+"(Soldier)", "Soldier", "Major job is to output explosion", 100, PyroW, PyroA);
        prof = false;
      break;
      case '3':
        pList[slot] = Player(myname+"(Pyro)", "Pyro", "Major job is to wipe out all enemy with flamethrower", 100, PyroW, PyroA);
        prof = false;
      break;
      case '4':
        pList[slot] = Player(myname+"(Heavy)", "Heavy", "Slow but deadly", 100, PyroW, PyroA);
        prof = false;
      break;
      default:
        cout << "Please select from above!" << '\n';
      break;
    }
  }
}
