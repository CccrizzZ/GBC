#pragma once
#include <string>
#include <iostream>
using namespace std;



class Achievement {
private:
  string Achititle;
  string descriptions;
  int scores;

public:
  Achievement (){};
  ~Achievement (){};
  Achievement(string t, string d, int s);
  void setTitle(string ti);
  void setDes(string des);
  void setScore(int sc);
  string getTitle();
  string getDes();
  int getScore();
};



Achievement::Achievement(string t, string d, int s){
  setTitle(t);
  setDes(d);
  setScore(s);
};


void Achievement::setTitle(string ti) {
  Achititle=ti;
};

void Achievement::setDes(string des){
  descriptions=des;
};

void Achievement::setScore(int sc) {
  scores=sc;
};

string Achievement::getTitle(){
  return Achititle;
};

string Achievement::getDes(){
  return descriptions;
};

int Achievement::getScore(){
  return scores;
};
