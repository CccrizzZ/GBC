#include "pch.h"
#include "Sort.h"
#include "Search.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <array>
#include <ctime>
#include <chrono>
using namespace std;


int main() {
  // Roll the dice
  srand(time(NULL));


  // Flag for user input
  bool input = true;

  // Size of array
  int aSize;

  while (input) {
    cout << "1.Create a number array" << '\n';
    cout << "2.Create a Inventory item array" << '\n';
    cout << "Press \'E\' to quit" << '\n' << '\n';
    int x = _getch();

    switch (x) {
      case '1':
        cout << "Please enter the size for the new number array:" << '\n';
        cin >> aSize;
        if (aSize>1000) {
          aSize=0;
          cout << "Array size should below 1000" << '\n';
          break;
        }else{
          Sort<int> s(aSize);


          // Bubble sort Timer starts
          auto start = std::chrono::steady_clock::now();
          s.BubbleSort();
          // Timer ends
          auto end = std::chrono::steady_clock::now();
          // Get delta
          double delta = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
          // Convert to milliseconds
          cout << '\n' <<"Bubble sort time taken = "<< delta/1000000 <<" milliseconds" << '\n';


          // MergeSort
          start = std::chrono::steady_clock::now();
          s.Msort();
          end = std::chrono::steady_clock::now();
          delta = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
          cout <<"Mergesort sort time taken = "<< delta/1000000 <<" milliseconds" << '\n';
          s.getArray();

          cout << '\n' << "Press \'Q\' to search for a specific element" << '\n';
          cout << "Press any key to go back" << '\n';
          int x = _getch();
          if (x == 'Q' || x== 'q') {
            // Ill just pass the array we sorted above to the search class
            // to search you have to sort first
            Search<int> search(s.arr, aSize);
            cout << "Please enter querying content" << '\n';
            int q;
            cin >> q;
            // Linear Search
            start = std::chrono::steady_clock::now();
            search.LinearSearch(q);
            end = std::chrono::steady_clock::now();
            delta = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            cout << "Linear search time taken = "<< delta/1000000 <<" milliseconds" << '\n' << '\n';

            // Binary Search
            start = std::chrono::steady_clock::now();
            search.BinarySearch(q);
            end = std::chrono::steady_clock::now();
            delta = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
            cout << "Binary search time taken = "<< delta/1000000 <<" milliseconds" << '\n' << '\n';

          }
          break;
        }
      break;
      case '2':
        cout << "Please enter the size for the new inventory item array:" << '\n';
        cin >> aSize;

      break;
      case 'E':
      case 'e':
        input = false;
      break;
      default:
        cout << "Please choose from above" << '\n';
      break;
    }
  }

  return 0;
 }
