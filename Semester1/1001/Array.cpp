#include <iostream>
using namespace std;

int main() {
  const int NUM_STUDENTS = 6;
  int grade[NUM_STUDENTS];
  int count;
  int sum=0;
  int high;
  int low;
  int acount;
  cout << "Enter the grades scored by " << NUM_STUDENTS << " students: " << '\n';

  for (count = 0; count < NUM_STUDENTS; count++) {
    cin >> grade[count];
  }

  for (count = 0; count < NUM_STUDENTS; count++) {
    sum+=grade[count];
  }

  cout << "The avrage grade of input students is: " << sum/count << '\n';



  // Compare array elements and swap them
  for (count = 0; count < NUM_STUDENTS; count++) {
    if (grade[count]>grade[count+1]) {
      grade[count]=grade[count+1];
    }
  }
  low = grade[0];
  high = grade[(sizeof(grade)/sizeof(grade[0]))-1]; // Length-1 = last element

  for (count = 0; count < NUM_STUDENTS; count++) {
    if (grade[count]<(sum/NUM_STUDENTS)){
      acount++;
    }
  }

  cout << "The highest grade is: " << high << '\n';
  cout << "The lowest grade is: " << low << '\n';
  cout << acount << " Students are below the average" << '\n';

  return 0;
}
