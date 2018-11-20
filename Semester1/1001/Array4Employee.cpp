#include <iostream>
#include <string.h>
using namespace std;

class Employee{
private:
  int id;
  string name;
  int hour;
  double rate;

public:
  // Inputs
  void setId(int id) {
    this -> id = id;
  }
  void setName(string name) {
    this -> name = name;
  }
  void setHour(int hour) {
    this -> hour = hour;
  }
  void setRate(double rate) {
    this -> rate = rate;
  }
  void setEmployee(int id, string name, int hour, double rate) {
    setId(id);
    setName(name);
    setHour(hour);
    setRate(rate);
  }

  // Outputs
  int getId(){
    return id;
  }
  string getName(){
    return name;
  }
  int getHour(){
    return hour;
  }
  double getRate(){
    return rate;
  }
  double getWage(){
    return hour*rate;
  }
};


Employee findHigh(Employee list[], int size);
Employee findLow(Employee list[], int size);


int main() {
  const int EMPNUM = 8;
  Employee list[EMPNUM];
  list[0].setEmployee(10,"Chris",40,20);
  list[1].setEmployee(20,"Owen",30,25);
  list[2].setEmployee(30,"Tim",20,28);
  list[3].setEmployee(40,"Romeo",40,22);
  list[4].setEmployee(50,"Tom",20,28);
  list[5].setEmployee(60,"Lucas",20,28);
  list[6].setEmployee(70,"Alex",20,750);
  list[7].setEmployee(80,"Leo",10,10);
  findHigh(list, EMPNUM);
  return 0;
}

Employee findHigh(Employee list[], int size){
  for (int i = 0; i < size; i++) {
    if (list[i].getWage()>list[i+1].getWage()) {
      list[i]=list[i+1];
    }
    return list[0];
    std::cout << list[0] << '\n';
  }
}

Employee findLow(Employee list[], int size){
  for (int i = 0; i < size; i++) {
    if (list[i].getWage()>list[i+1].getWage()) {
      list[i]=list[i+1];
    }
    return list[0];
  }
}

// void sortEmployeesAZ(Employee list[], int size){
//   Employee emp;
//   for (int i = 0; i < size; i++) {
//     for (int j = 0; j < size; j++) {
//       if (strcmp(list[i].getName(),list[i+1].getName())!=0) {
//         continue;
//       }else if (strcmp(list[i].getName(),list[i+1].getName())>0) {
//         list[i]=list[i+1];
//       }
//     }
//   }
// }
