#include <iostream>
#include <cstdlib>
#include "InventoryItem.h"
using namespace std;


template <class T>
class Sort {
public:
  int size;
  // Array populated with random numbers
  T *aptr;
  // BubbleSort temp
  int Btemp;

  // Constructor
  Sort();
  Sort(T a[]){
    if (is_same<T,int>::value) {
      size = sizeof(a)/sizeof(a[0]);

      aptr = new T [size];

      for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        aptr[i] = a[i];
      }
      // Automatically populate the array with random numbers between 1-1000
      for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        aptr[i] = rand() % 1000 + 1;
      }
    }else if (is_same<T,InventoryItem>::value) {
      size = sizeof(a)/sizeof(a[0]);

    }
  }
  ~Sort(){};


  // Print out the array
  void getArray(){
    if (is_same<T,int>::value) {
      cout << '\n' << "Array generated: { ";
      for (int i = 0; i < sizeof(aptr)/sizeof(aptr[0]); i++) {
        cout << aptr[i] << " ";
      }
      cout << "}" << '\n' << '\n';
    }else if (is_same<T,InventoryItem>::value) {
      std::cout << "Inventory" << '\n';
    }
  }


  // Bubble Sorting ASC
  void BubbleSort(){
    for (int i = 0; i <= size; i++) {
      for (int j = 0; j < size; j++) {
        if (aptr[j]>aptr[j+1]) {
          // Swap aptr[j] and aptr[j+1]
          Btemp = aptr[j];
          aptr[j] = aptr[j+1];
          aptr[j+1] = Btemp;
        }
      }
    }
  }











  // Merging two arrays
  void Merge(int a[], int low, int high, int mid) {
    int i, j, k;
    int temp[1000];
    i = low;
    j = mid + 1;
    k = 0;

    // Merge into temporary array
    while (i <= mid && j <= high) {
      if (a[i] < a[j]) {
        temp[k] = a[i];
        k++;
        i++;
      }else{
        temp[k] = a[j];
        k++;
        i++;
      }
    }

    while (i <= mid) {
      temp[k] = a[i];
      k++;
      i++;
    }

    while (j <= high) {
       temp[k] = a[j];
      k++;
      j++;
    }

    for (int i = low; i < high; i++) {
      a[i] = temp[i-low];
    }
  }


  void MergeSort(int a[], int low, int high) {
    if (low < high) {
      int mid = (low + high)/2;

      // Split array into half
      MergeSort(a, low, mid);
      MergeSort(a, mid+1, high);

      // Merge arrays into one
      Merge(a, low, high, mid);
    }
  }


  // MergeSort the auto populated array in one parameterless function
  void Msort() {
    MergeSort(aptr, 0, size-1);
  }

};
