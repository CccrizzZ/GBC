#include <iostream>
#include <cstdlib>
using namespace std;

// Absract class
template <class T>
class Array {
private:
  T *aptr;
  int arraySize;

public:
  // Constructor
  Array(int s){
    // Set size
    arraySize = s;
    
    // point the T pointer to a new T type array
    aptr = new T [s];

    for (int i = 0; i < arraySize; i++) {
      aprt
    }

    // Copy everything into T pointer
    for (int i = 0; i < arraySize; i++) {
      aptr[arraySize] = T();
    }
  }

  // Return size
  int getSize(){
    return arraySize;
  }
};




// Child class
template <class T>
class SortableArray : public Array<T>{
public:
  // Constructor
  SortableArray(int s) : Array<T>(s){};

  void printArr() {
    for (int i = 0; i < arraySize; i++) {
      cout << aptr[i] << '\n';
    }
  }
};
