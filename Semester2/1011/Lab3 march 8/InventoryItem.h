#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class InventoryItem {
private:
  string ItemName = "Example";
  string ItemDesc = "Example";
  int ItemWeight; // 1-100 random number


public:
  InventoryItem (){
    ItemWeight = rand() % 100 + 1;
  }
  ~InventoryItem ();



};
