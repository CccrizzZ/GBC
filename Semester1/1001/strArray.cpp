#include <iostream>
#include <cstring>
using namespace std;

int main() {
  // NULL pointer
  const char *p = nullptr;
  char content[21];
  // Counters
  int numbers = 0;
  int vowel = 0;
  char rev[]={};

  cout << "Please Enter a Word (<=20 Character)" << '\n';
  cin >> content;
  cout << '\n' << "The length of your input is: " << strlen(content) << '\n';
  for (int i = 0; i < strlen(content); i++) {
    switch (content[i]) {
      case 'a':
      case 'e':
      case 'u':
      case 'i':
      case 'o':
      case 'A':
      case 'E':
      case 'U':
      case 'I':
      case 'O':
        vowel++;
        continue;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
        numbers++;
        continue;
      default:
        break;
    }
  }



  cout << "There are " << vowel << " vowels in your input" << '\n';
  cout << "There are " << numbers << " numbers in your input" << '\n';
  cout << "Reversed input: ";
  for (int i = strlen(content); i >= 0 ; i--) {
    cout << content[i];
  }
  cout  << '\n';


  return 0;
}
