#include <iostream>
#include <string>
#include "Armour.h"
#include "Weapon.h"
using namespace std;

// Pyro HP = 100
Weapon PyroW[5] = {
  Weapon("Flamethrower", "Gasoline gel powered flamethrower", 40),
  Weapon("Grenade launcher", "Home-Made Grenade launcher", 80),
  Weapon("Pistol", "9mm Simi-auto pistol", 20),
  Weapon("Crowbar", "Just a Crowbar", 10)
};

Armour PyroA[3] = {
  Armour("Bullet proof vest", "Prevents bullet up to 7.62mm", 100),
  Armour("Fire proof suit", "Prevents Fire", 10)
};




// Soldier HP = 100
Weapon SoldierW[5] = {
  Weapon("RPG-7", "American made RPG, not accurate but reliable", 80),
  Weapon("Shotgun", "Just a shotgun", 40),
  Weapon("Shotgun", "Just another shotgun", 40)
};

Armour SoldierA[3] = {
  Armour("Bullet proof vest", "Prevents bullet up to 7.62mm", 100),
  Armour("Bullet proof Helmet", "Prevents bullet up to 5.56mm", 30)
};




// HW guy HP = 200
Weapon HeavyW[5] = {
  Weapon("M-134", "American made minigun, war machine", 120),
  Weapon("Shotgun", "Just a shotgun", 40),
  Weapon("Crowbar", "Just a Crowbar", 10)
};

Armour HeavyA[3] = {
  Armour("Jaggernaut suit", "Prevents bullet up to 30cal", 200),
};


// Scout HP = 60
Weapon ScoutW[5] = {
  Weapon("Nailgun", "One interesting fact: Nailgun can kill!", 20),
  Weapon("Shotgun", "Just a shotgun", 40),
  Weapon("Baseball bat", "In TF1 its a Crowbar, in TF2 its a Baseball bat", 5)
};

Armour ScoutA[3] = {
  Armour("Bullet proof vest", "Prevents bullet up to 7.62mm", 100),
};
