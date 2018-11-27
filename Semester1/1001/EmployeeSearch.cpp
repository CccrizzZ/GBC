#include <iostream>
#include <string>
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

// Prototypes
Employee searchEmployee(Employee x[],int size, int eid);
void printEmp(Employee x[], int size);


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

  // All Employee information
  cout << "All Employee information: " << '\n';
  printEmp(list, EMPNUM);

  // Querying all Employee by ID
  int userinput;
  while (true) {
    cout << "Search Employee by ID: " << '\n';
    cin >> userinput;
    searchEmployee(list, EMPNUM, userinput);
  }

  return 0;
}


// Function for querying Employees by ID
Employee searchEmployee(Employee x[],int size, int eid){
  // Flag for finding the target
  bool found = false;

  for (int i = 0; i < size; i++) {
    if (x[i].getId()==eid) {
      cout << '\n' << "Search Result: " << '\n';
      cout << "---------------------------------------" << '\n';
      cout << "ID: " << x[i].getId() << '\n';
      cout << "Name: " << x[i].getName() << '\n';
      cout << "Working Hour: " << x[i].getHour() << '\n';
      cout << "Horly Rate: " << x[i].getRate() << '\n';
      cout << "Total Wage: " << x[i].getWage() << '\n' << '\n';
      found=true;
    }
  }
  if(found==false){
    cout << "---------------------------" << '\n';
    cout << "No Result Found!" << '\n';
    cout << "---------------------------" << '\n';
  }
}


// Function for printing all Employees
void printEmp(Employee x[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "ID: " << x[i].getId() << '\n';
    cout << "Name: " << x[i].getName() << '\n';
    cout << "Working Hour: " << x[i].getHour() << '\n';
    cout << "Horly Rate: " << x[i].getRate() << '\n';
    cout << "Total Wage: " << x[i].getWage() << '\n' << '\n';
    cout << "---------------------------------------" << '\n' << '\n';

  }
}
