#include "Game.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

// List for all player choices
list <int> playerChoices;

// Return player last choice
int getLastChoice(list <int> l){

  return l.back();
}

void Game::Preparation(){
  cout << "--------------------" << '\n';
  cout << "Preparation" << '\n';
  cout << "--------------------" << '\n' << '\n';
  cout << "This is the year 2066, and Tyrant virus leaked in Area 51 in Nevada." << '\n';
  cout << "Few month later, Nevada doomed, all airports on westcoast are closed..." << '\n';
  cout << "You lives in LA, you were ordered by government to evacuate in 3 month." << '\n';
  cout << "Government predicted the virus will reach LA in 3 month." << '\n' << '\n';

  cout << "You planned to move to Florida in the end of second month." << '\n';
  cout << "You have 2 month to prepare for your trip, what are you gona do?" << '\n' << '\n';

  cout << "Enter \'weapon and food\' to prepare for weapon and food" << '\n';
  cout << "Enter \'drug and fuel\' to prepare for all kinds of drugs and fuel" << '\n'<< '\n';


  string choice1 = "weapon and food";
  string choice2 = "drug and fuel";
  string temp;

  bool prep = true;
  bool pass = false;

  // Preparation loop
  while (prep) {
    getline(cin, temp);

    if (temp == choice1) {
      playerChoices.push_back(100);
      pass = true;
      prep = false;
    }else if (temp == choice2) {
      playerChoices.push_back(200);
      pass = true;
      prep = false;
    }else{
      cout << "Please choose from above!" << '\n';
    }
  }

  if (getLastChoice(playerChoices)==100) {
    OutOfTown();
  }else if (getLastChoice(playerChoices)==200) {
    RedAlarm();
  }


}




// Stay in car *
// Abandon car
void Game::OutOfTown(){
  cout << '\n' << "--------------------" << '\n';
  cout << "Out of Town" << '\n';
  cout << "--------------------" << '\n' << '\n';

  cout << "You found that a lot of people are having the same plan as you do." << '\n';
  cout << "The highway is packed with cars and trucks." << '\n' << '\n';

  cout << "Suddently you hear people screaming and gunshots in a distance." << '\n';
  cout << "Black smoke came out ahead of you, people are abandoning their car and running away." << '\n' << '\n';

  cout << "You do have weapons, what are you going to do?" << '\n' << '\n';

  cout << "Enter \'stay in car\' to load weapon and see whats going on." << '\n';
  cout << "Enter \'abandon car\' to run away." << '\n'<< '\n';


  string choice1 = "stay in car";
  string choice2 = "abandon car";
  string temp;

  bool prep = true;
  bool pass = false;

  // Preparation loop
  while (prep) {
    getline(cin, temp);

    if (temp == choice1) {
      playerChoices.push_back(100);
      pass = true;
      prep = false;
    }else if (temp == choice2) {
      playerChoices.push_back(200);
      pass = true;
      prep = false;
    }else{
      cout << "Please choose from above!" << '\n';
    }
  }

  if (getLastChoice(playerChoices)==100) {
    cout << '\n' << "--------------------" << '\n';
    cout << "You dead!" << '\n';
    cout << "--------------------" << '\n' << '\n';

    cout << "Turns out there is a mass shooting happening on the highway." << '\n';
    cout << "The car infront you exploded due to a leaked gas tank." << '\n';

  }else if (getLastChoice(playerChoices)==200) {
    GasStationLoot();
  }

}


// Sneak up *
// Take them out
void Game::GasStationLoot(){
  cout << '\n' << "--------------------" << '\n';
  cout << "Gas Station" << '\n';
  cout << "--------------------" << '\n' << '\n';

  cout << "You arrived at a gas station out of town, there is a truck parking outside with battery on." << '\n';
  cout << "Looks like there are 3 people looting the store in the gas station" << '\n' << '\n';

  cout << "Enter \'open fire\' to shoot at those people and loot them." << '\n';
  cout << "Enter \'sneak up\' to sneak up and steal their car." << '\n'<< '\n';

  string choice1 = "open fire";
  string choice2 = "sneak up";
  string temp;

  bool prep = true;
  bool pass = false;

  // Preparation loop
  while (prep) {
    getline(cin, temp);

    if (temp == choice1) {
      playerChoices.push_back(100);
      pass = true;
      prep = false;
    }else if (temp == choice2) {
      playerChoices.push_back(200);
      pass = true;
      prep = false;
    }else{
      cout << "Please choose from above!" << '\n';
    }
  }

  if (getLastChoice(playerChoices)==100) {
    cout << "You fired your weapon at those people..." << '\n';
    cout << "You killed 2 and left one guy on the ground holding his own gut." << '\n';
    cout << "You took their truck and escaped." << '\n' << '\n';


    Arrival();
  }else if (getLastChoice(playerChoices)==200) {
    cout << '\n' << "--------------------" << '\n';
    cout << "You dead!" << '\n';
    cout << "--------------------" << '\n' << '\n';

    cout << "You started the car, they ran out of the store and start to shoot." << '\n';
    cout << "You drove for 5 seconds and lost control of the car." << '\n';
    cout << "The car stopped, you got eaten by zombies." << '\n';
  }


}


void Game::Arrival(){
  cout << '\n' << "--------------------" << '\n';
  cout << "Arrival" << '\n';
  cout << "--------------------" << '\n' << '\n';

  cout << "You finaly made it to Florida!" << '\n';
  cout << "But your advanture just begun." << '\n';
  cout << '\n' << '\n' << "-----------The-End------------" << '\n' << '\n';

}





// go inside
// keep moving
void Game::RedAlarm(){
  cout << '\n' << "--------------------" << '\n';
  cout << "RedAlarm" << '\n';
  cout << "--------------------" << '\n' << '\n';

  cout << "Since the army are ordered to kill all civilians onsight," << '\n';
  cout << "You decided to ride a bike instead of driving a car." << '\n';
  cout << "You avoided all major highways and take coutry roads." << '\n' << '\n';

  cout << "10 Hours later you stopped at a abandoned barn, seems like the owner has left." << '\n';
  cout << "What do you do?" << '\n' << '\n';

  cout << "Enter \'go inside\' to go inside and loot the place again." << '\n';
  cout << "Enter \'move on\' to walk away." << '\n'<< '\n';

  string choice1 = "go inside";
  string choice2 = "move on";
  string temp;

  bool prep = true;
  bool pass = false;

  // Preparation loop
  while (prep) {
    getline(cin, temp);

    if (temp == choice1) {
      playerChoices.push_back(100);
      pass = true;
      prep = false;
    }else if (temp == choice2) {
      playerChoices.push_back(200);
      pass = true;
      prep = false;
    }else{
      cout << "Please choose from above!" << '\n';
    }
  }

  if (getLastChoice(playerChoices)==100) {
    Barn();
  }else if (getLastChoice(playerChoices)==200) {
    Supermarket();
  }


}


// Open the door *
// Leave
void Game::Barn() {
  cout << '\n' << "--------------------" << '\n';
  cout << "Barn" << '\n';
  cout << "--------------------" << '\n' << '\n';

  cout << "There is nobody here, you looted food and gas." << '\n';
  cout << "When You try to leave the barn, you hear something scratching the bathroom door from inside." << '\n';
  cout << "What are you gona do?" << '\n' << '\n';

  cout << "Enter \'open the door\' to go inside and loot the place again." << '\n';
  cout << "Enter \'leave the barn\' to walk away." << '\n'<< '\n';


  string choice1 = "open the door";
  string choice2 = "leave the barn";
  string temp;

  bool prep = true;
  bool pass = false;

  // Preparation loop
  while (prep) {
    getline(cin, temp);

    if (temp == choice1) {
      playerChoices.push_back(100);
      pass = true;
      prep = false;
    }else if (temp == choice2) {
      playerChoices.push_back(200);
      pass = true;
      prep = false;
    }else{
      cout << "Please choose from above!" << '\n';
    }
  }

  if (getLastChoice(playerChoices)==100) {
    cout << '\n' << "--------------------" << '\n';
    cout << "You dead!" << '\n';
    cout << "--------------------" << '\n' << '\n';

    cout << "You open the door, 3 zombie came out." << '\n';
    cout << "They split you into 3 pieces." << '\n';
    cout << "You got eaten by zombies." << '\n';

  }else if (getLastChoice(playerChoices)==200) {
    Supermarket();
  }

}


// Run into grass
// Stay in supermarket *
void Game::Supermarket(){
  cout << '\n' << "--------------------" << '\n';
  cout << "Supermarket" << '\n';
  cout << "--------------------" << '\n' << '\n';

  cout << "You arrived at a abandoned supermarket out at no where." << '\n';
  cout << "It is surrounded by tall grass, and the sun just went down." << '\n' << '\n';

  cout << "You heard heavy military vehicle approaching." << '\n';
  cout << "What are you gona do?" << '\n' << '\n';

  cout << "Enter \'stay inside\' to stay inside the supermarket." << '\n';
  cout << "Enter \'run away\' to run into the tall grass field." << '\n' << '\n';


  string choice1 = "stay inside";
  string choice2 = "run away";
  string temp;

  bool prep = true;
  bool pass = false;

  // Preparation loop
  while (prep) {
    getline(cin, temp);

    if (temp == choice1) {
      playerChoices.push_back(100);
      pass = true;
      prep = false;
    }else if (temp == choice2) {
      playerChoices.push_back(200);
      pass = true;
      prep = false;
    }else{
      cout << "Please choose from above!" << '\n';
    }
  }

  if (getLastChoice(playerChoices)==100) {
    cout << '\n' << "--------------------" << '\n';
    cout << "You dead!" << '\n';
    cout << "--------------------" << '\n' << '\n';

    cout << "The military passed by, but the noise quickly attracks zombies." << '\n';
    cout << "You loot too much, its hard for you to run fast." << '\n';
    cout << "You got eaten by zombies." << '\n';

  }else if (getLastChoice(playerChoices)==200) {
    cout << "Military rolled by, they didn't find you." << '\n';
    cout << "You found a truck by a abandoned campsite." << '\n' << '\n';
    cout << "You started the truck by wiring and drove away." << '\n' << '\n';

    Arrival();
  }

}
