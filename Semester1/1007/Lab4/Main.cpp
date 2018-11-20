#include <iostream>
#include "Fruit.h"
using namespace std;

int main() {
  Fruit Guava("Guava", 2.99, "like pear-mango and strawberry combined");
  Guava.setOwned(true);
  cout << "You are Eating a ";
  Guava.use();
  system("pause");
  return 0;
}
