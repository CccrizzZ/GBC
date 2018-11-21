#include <iostream>
#include "Classes.h"
using namespace std;

// How to pass parameter into a function
void PassByValue(Door d) {
  d.m_x = 30;
}

void PassByReference(Door& d){
  d.m_x = 30;
}

void PassByPointer(Door* d){
  // (*d).m_x = 30;
  d -> m_x = 30;
}

void PassArray(Door d[], const int size) {
  for (int i = 0; i < size; i++) {
    d[i].m_x = 30*(i+1);
  }
}

int main() {
  LOTile test(6,2);
  Door doors[3];
  PassArray(doors, 3);
  cout << doors[0].m_x << '\n';
  system("pause");
  return 0;
}
