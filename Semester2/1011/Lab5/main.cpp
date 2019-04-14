#include <iostream>
#include "DynStack.h"
#include "DynQueue.h"
using namespace std;



int main() {
  // Stake for Pancake
  DynStack<int> HeatLamp;

  // Queue for Customers
  DynQueue<int> Customers;

  // Add 30 Customers to the queue
  Customers.Add30();

  HeatLamp.Gimme5();


  int served;
  int SharedHand = 0;
  for (int i = 0; i < 30; i++) {

    // Each customer grab 3 pancake
    HeatLamp.take3();

  }

  // Customer leaves
  Customers.clear();






  system("pause");
  return 0;
}
