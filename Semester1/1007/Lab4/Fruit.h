#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Fruit{
private:
  bool owned;
  float fcost;
  string fname;
  string ftaste;
public:
  // Default Constructor
  Fruit(string name, float cost, string taste){
    fname=name;
    fcost=cost;
    ftaste=taste;
  }

  // Destructor
  ~Fruit(){}

  string getName(){
    return fname;
  }
  void setOwned(bool x){
    owned=x;
    cout << "Bought " << fname << " for " << fcost << "\n";
  }
  void use() {
    cout << fname << " That Taste " << ftaste << "\n";
  }
};
