#include <iostream>
#include <string>
#include <cstring>

#include <conio.h>
using namespace std;

void palindrome(string str);
void quickSort();
void strReverse();


int main() {

  char input;
  string in;

  cout << "Please choose from below" << '\n';
  cout << "1. Determine palindrome" << '\n';
  cout << "2. Quick sort" << '\n';
  cout << "3. Reverse string" << '\n';

  input = _getch();
  switch (input) {
    case '1':
      cout << '\n' << "Please enter a string" << '\n';
      cin >> in;
      palindrome(in);
    break;
    case '2':
      quickSort();
    break;
    case '3':
      strReverse();
    break;
    default:
      cout << "Please choose from above!" << '\n';
    break;
  }


  system("pause");
  return 0;
}


// Determine palindrome
void palindrome(string str[]){



}



// Quick sort on random list of int
void quickSort(){





}



// Reverse a given string
void strReverse(){




}
