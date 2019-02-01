#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "Enemy.h"
using namespace std;

// Forest Battle Loop
void ForestBattle() {

  Orc Orc1 = Orc();
  bool battle = true;
  bool yourturn = true;
  bool enemyturn = false;

  while (battle) {
    char input;
    cout << '\n' << "------------------------" << '\n';
    cout << "Orc HP: " << Orc1.getHP() << '\n';
    cout << "------------------------" << '\n';
    yourturn = true;



    // Player's turn
    while (yourturn) {
      cout << '\n' << "------------------------" << '\n';
      cout << "1. Normal Attack" << '\n';
      cout << "2. Special Attack" << '\n';
      cout << "------------------------" << '\n' << '\n';
      input = _getch();
      switch (input) {
        case '1':
        cout << '\n' << "------------------------" << '\n';
        cout << "[You Performed Normal Attack Caust 30 Damage]" << '\n';
        cout << "------------------------" << '\n';
        Orc1.setHP(Orc1.getHP()-30);
        yourturn = false;
        break;
        case '2':
        cout << '\n' << "------------------------" << '\n';
        cout << "[You Performed Special Attack Caust 80 Damage]" << '\n';
        cout << "------------------------" << '\n';
        Orc1.setHP(Orc1.getHP()-80);
        yourturn = false;
        break;
        default:
        cout << "Please Choose From The Option Provided Above!" << '\n';
        break;
      }
    }
    if ((rand() % 100 + 5) % 2 != 0) {
      Orc1.Taunt();
    }else{
      Orc1.NormalAtt();
    }
    if (Orc1.getHP()<=0) {
      Orc1.Die();

      battle = false;
    }
  }
}










// Waterfall Battle Loop
void WaterBattle() {
  Murloc Mur1 = Murloc();
  bool battle = true;
  bool yourturn = true;
  bool enemyturn = false;

  while (battle) {
    char input;
    cout << '\n' << "------------------------" << '\n';
    cout << "Murloc HP: " << Mur1.getHP() << '\n';
    cout << "------------------------" << '\n';
    yourturn = true;



    // Player's turn
    while (yourturn) {
      cout << '\n' << "------------------------" << '\n';
      cout << "1. Normal Attack" << '\n';
      cout << "2. Special Attack" << '\n';
      cout << "------------------------" << '\n' << '\n';
      input = _getch();
      switch (input) {
        case '1':
        cout << '\n' << "------------------------" << '\n';
        cout << "[You Performed Normal Attack Caust 30 Damage]" << '\n';
        cout << "------------------------" << '\n';
        Mur1.setHP(Mur1.getHP()-30);
        yourturn = false;
        break;
        case '2':
        cout << '\n' << "------------------------" << '\n';
        cout << "[You Performed Special Attack Caust 80 Damage]" << '\n';
        cout << "------------------------" << '\n';
        Mur1.setHP(Mur1.getHP()-80);
        yourturn = false;
        break;
        default:
        cout << "Please Choose From The Option Provided Above!" << '\n';
        break;
      }
    }
    if ((rand() % 100 + 5) % 2 != 0) {
      Mur1.Taunt();
    }else{
      Mur1.NormalAtt();
    }
    if (Mur1.getHP()<=0) {
      Mur1.Die();
      battle = false;
    }
  }
}


// Pub Loop
void TownPub() {
  // Flag For Pub
  bool PubFlag = true;
  char input;
  while (PubFlag) {
    cout << "------------------------" << '\n';
    cout << "Choose Your Drink: " << '\n';
    cout << "1. Malt Beer" << '\n';
    cout << "2. Shot of Whisky" << '\n';
    cout << "Press \"E\" To Go Back In Town" << '\n';
    cout << "------------------------" << '\n' << '\n';
    input = _getch();
    switch (input) {
      case 'E':
        PubFlag = false;
      break;
      case 'e':
        PubFlag = false;
      break;
      case '1':
        cout << "------------------------" << '\n';
        cout << "Grrr....Taste Bitter" << '\n';
        cout << "[Healed 10 Points Of HP]" << '\n';
        cout << "------------------------" << '\n' << '\n';
      break;
      case '2':
        cout << "------------------------" << '\n';
        cout << "Grrr....My throat......Burning..Like....." << '\n';
        cout << "[Healed 50 Points Of HP]" << '\n';
        cout << "------------------------" << '\n' << '\n';
      break;
      default:
        cout << "Please Choose From The Option above!" << '\n';
      break;
    }
  }
}











// Forest Loop
void ForestExplore() {
  cout << "It Is Very Foggy....." << '\n';
  if ((rand() % 100 + 5) % 2 != 0){
    ForestBattle();
  }else{
    cout << "[You See Nothing But Fog and Trees]" << '\n';
  }
}


void ForestOfMist() {
  // Forest input
  char input;
  // Flag for Forest
  bool ForestFlag = true;
  while (ForestFlag) {
    cout << "------------------------" << '\n';
    cout << "You Are In The Forest of Mist" << '\n';
    cout << "Press Any Key To Explore" << '\n';
    cout << "Press \"E\" To Go Back In Town" << '\n';
    cout << "------------------------" << '\n' << '\n';
    input = _getch();
    switch (input) {
      case 'E':
        ForestFlag = false;
      break;
      case 'e':
        ForestFlag = false;
      break;
      default:
        cout << "------------------------" << '\n';
        cout << "[Walking Through Forest......]" << '\n';
        ForestExplore();
      break;
    }
  }
}














// BlackWaterFall Loop
void WaterfallExplore() {
  cout << "Water Splashing, But No Rainbow....." << '\n';
  if ((rand() % 100 + 5) % 2 != 0){
    Murloc Enemy2 = Murloc();
    WaterBattle();
  }else{
    cout << "[You See Nothing But Stones And Water]" << '\n';
  }
}


void BlackWaterFall() {
  // Flag for Waterfall
  bool WaterFlag = true;
  while (WaterFlag) {
    char input;
    cout << "------------------------" << '\n';
    cout << "You Are In The Black Waterfall" << '\n';
    cout << "Press Any Key To Explore" << '\n';
    cout << "Press \"E\" To Go Back In Town" << '\n';
    cout << "------------------------" << '\n' << '\n';
    input = _getch();
    switch (input) {
      case 'E':
        WaterFlag = false;
      break;
      case 'e':
        WaterFlag = false;
      break;
      default:
        cout << "[Walking Through Waterfall......]" << '\n';
        WaterfallExplore();
      break;
    }
  }
}
