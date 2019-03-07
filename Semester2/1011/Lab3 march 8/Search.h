#include <iostream>
using namespace std;

template <class T>
class Search {
public:
  int arraySize;
  T *aptr;

  int max;
  int min;

  Search (T a[]){
    arraySize = sizeof(a)/sizeof(a[0]);

    aptr = new T [arraySize];

    for (int i = 0; i < arraySize; i++) {
      aptr[i] = a[i];
    }
  }
  ~Search (){};


  // Linear Search
  void LinearSearch(int l){
    bool found = false;
    bool notfound = true;
    while (found == false) {
      for (int i = 0; i < arraySize; i++) {
        if (aptr[i] == l) {
          cout << "Element " << l << " is the " << i+1 << "th element in this aray" << '\n' << '\n';
          found = true;
          notfound = false;
        }else if (notfound) {
          found = true;
        }
      }
    }
    if(notfound){
      cout << "Element not found" << '\n' << '\n';
    }
  }


  // Binary Search
  void BinarySearch(int b){
    min = 0;
    max = arraySize - 1;
    int mid;
    bool flag = true;
    bool found = false;

    while (min <= max && flag) {
      mid = (max + min)/2;
      if (b == aptr[mid]) {
        cout << "Element " << b << " is the " << mid+1 << "th element in this aray" << '\n' << '\n';
        flag = false;
        found = true;
      }else if (aptr[mid] > b) {
        max = mid - 1;
      }else{
        min = min + 1;
      }
    }
    if (!found) {
      cout << "Element not found" << '\n' << '\n';
    }
  }


};
