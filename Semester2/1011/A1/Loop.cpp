#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "Enemy.h"
using namespace std;


// Forest Battle Loop
void ForestBattle() {

  Orc Enemy1 = Orc();
  bool battle = true;
  char input;
  while (battle) {
    cout << "------------------------" << '\n';
    cout << "Orc HP: " << Enemy1.getHP() << '\n';
    cout << "1. Normal Attack" << '\n';
    cout << "2. Special Attack" << '\n';
    cout << "------------------------" << '\n';
    input = _getch();
    switch (input) {
      case '1':
      cout << "[You Performed Normal Attack]" << '\n';
      break;
      case '2':
      cout << "[You Performed Special Attack]" << '\n';

      break;
      default:
      cout << "Please Choose From The Option Provided Above!" << '\n';
      break;
    }
  }
}








// Waterfall Battle Loop
void WaterBattle() {

}


// Pub Loop
void TownPub() {
  // Flag For Pub
  bool PubFlag = true;
  char input;
  while (PubFlag) {
    cout << "Choose Your Drink: " << '\n';
    cout << "1. Malt Beer" << '\n';
    cout << "1. Shot of Whisky" << '\n';
    cout << "Press \"E\" To Go Back In Town" << '\n';
    input = _getch();

    switch (input) {
      case 'E':
        PubFlag = false;
      break;
      case 'e':
        PubFlag = false;
      break;
      case '1':
        cout << "Grrr....Taste Bitter" << '\n';
        cout << "[Healed 10 Points Of HP]" << '\n';
      break;
      case '2':
        cout << "Grrr....My throat......Burning..Like....." << '\n';
        cout << "[Healed 50 Points Of HP]" << '\n';
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
    cout << "You Are In The Forest of Mist" << '\n';
    cout << "Press Any Key To Explore" << '\n';
    cout << "Press \"E\" To Go Back In Town" << '\n';
    input = _getch();

    switch (input) {
      case 'E':
        ForestFlag = false;
      break;
      case 'e':
        ForestFlag = false;
      break;
      default:
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
  char input;
  // Flag for Waterfall
  bool WaterFlag = true;
  while (WaterFlag) {
    char input;
    cout << "Press Any Key To Explore" << '\n';
    cout << "Press \"E\" To Go Back In Town" << '\n';
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
