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
void sortEmployeesAZ(Employee list[], int size);
string all(Employee list[], int size);

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


  cout << "Employee with the highest wage: " << findHigh(list, EMPNUM-1).getName() << '\n';
  cout << "Employee with the lowest wage: " << findLow(list, EMPNUM).getName() << '\n';
  cout << "Employee name in wage order:" << '\n';
  sortEmployeesAZ(list,EMPNUM);
  all(list, EMPNUM);
  return 0;
}


// Return the Employee with the highest wage
Employee findHigh(Employee list[], int size){
  Employee high = list[0];
  for (int i = 0; i < size; i++) {
    if (list[i].getWage()>high.getWage()) {
      high=list[i];
    }
  }
  return high;
}


// Return the Employee with the lowest wage
Employee findLow(Employee list[], int size){
  Employee low = list[0];
  for (int i = 0; i < size; i++) {
    if (list[i].getWage()<low.getWage()) {
      low=list[i];
    }
  }
  return low;
}


// Sort employees by wage
void sortEmployeesAZ(Employee list[], int size){
Employee emp;
for (int i = 0; i < size - 1; i++)
  for (int j = i + 1; j < size; j++)
	 if (list[i].getWage() > list[j].getWage()){
		emp = list[i];
		list[i] = list[j];
    list[j] = emp;
  }
}

// Outputs all employees's info
string all(Employee list[], int size){
  for (int i = 0; i < size; i++) {
    cout << "ID: " << list[i].getId() << '\n';
    cout << "Name: " << list[i].getName() << '\n';
    cout << "WORK HOUR: " << list[i].getHour() << '\n';
    cout << "HOUR RATE: " << list[i].getRate() << '\n';
    cout << "TOTAL WAGE: " << list[i].getWage() << '\n' << '\n';
  }
}
