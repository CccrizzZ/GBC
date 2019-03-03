#include <iostream>
#include <cstdlib>
using namespace std;


template <class T>
class Array {
private:
  T *aptr;
  int arraySize;

public:
  Array(int s){
    arraySize = s;
    aptr = new T [s];
    for (int i = 0; i < arraySize; i++) {
      aptr[arraySize] = T();
    }
  }
  int getSize(){
    return arraySize;
  }
};



template <class T>
class SortableArray : public Array<T>{
public:
  SortableArray(int s) : Array<T>(s){};


};
