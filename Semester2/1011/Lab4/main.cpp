#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <time.h>
using namespace std;

// Prototypes
bool isPa(char c[]);
bool palindrome(char x[], int s, int e);
void quickSort(int size);
void strReverse(char* x);


int main() {
  srand(time(NULL));

  char input;


  char in[1024];
  int arrSize;

  while (true) {


    cout << '\n' << "Please choose from below" << '\n';
    cout << "1. Determine palindrome" << '\n';
    cout << "2. Quick sort" << '\n';
    cout << "3. Reverse string" << '\n';
    cout << "Press \'E\' to exit" << '\n';


    input = _getch();
    switch (input) {
      case 'e':
      case 'E':
        return 0;
      break;
      case '1':
        cout << '\n' << "Please enter a string" << '\n';
        cin >> in;
        if (isPa(in) == true) {
          cout << in << " is palindrome" << '\n';
        }else{
          cout << in << " is not palindrome" << '\n';
        }
      break;
      case '2':
        cout << '\n' << "Please enter array size" << '\n';
        cin >> arrSize;
        quickSort(arrSize);
      break;
      case '3':
        cout << '\n' << "Please enter a string" << '\n';
        cin >> in;
        strReverse(in);
        cout << '\n';
      break;
      default:
        cout << '\n' << "Please choose from above!" << '\n';
      break;
    }
    break;
  }


  system("pause");
  return 0;
}


bool isPa(char c[]){
  int len = strlen(c);
  if (len == 0) {
    return true;
  }
  return palindrome(c, 0, len - 1);
}


bool palindrome(char x[], int s, int e){
  if (s == e){
    return true;
  }
  if (x[s] != x[e]){
    return false;
  }
  if (s < e + 1){
    return palindrome(x, s + 1, e - 1);
  }

  return true;
}




void recSort(int arr[], int n){
  if (n == 1){
    return;
  }

  for (int i=0; i<n-1; i++){
    if (arr[i] > arr[i+1]){
      swap(arr[i], arr[i+1]);
    }
  }
  recSort(arr, n-1);
}




void quickSort(int size){
  int* randArr = new int[size];

  for (int i = 0; i < size; i++) {
    randArr[i] = rand() % 100 + 1;
  }

  recSort(randArr, size);

  cout << "{ ";
  for (int i = 0; i < size; i++) {
    cout << randArr[i] << " ";
  }
  cout << " }" << '\n';

  delete [] randArr;
}


void strReverse(char* x) {
  if (*x == NULL) {
    return;
  }else{
    strReverse(x+1);
    cout << *x;
  }
}
