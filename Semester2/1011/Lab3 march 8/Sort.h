#include <iostream>
#include <cstdlib>
using namespace std;


template <class T>
class Sort {
public:
  int size;
  // Array populated with random numbers
  int arr[1000];
  // BubbleSort temp
  int Btemp;

  // Constructor
  Sort();
  Sort(int x){
    size = x;
    // Automatically populate the array with random numbers between 1-1000
    for (int i = 0; i <= x; i++) {
      arr[i] = rand() % 1000 + 1;
    }
  }
  ~Sort(){};


  // Print out the array
  void getArray(){
    cout << '\n' << "Number array generated: { ";
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << "}" << '\n' << '\n';
  }


  // Bubble Sorting ASC
  void BubbleSort(){
    for (int i = 0; i <= size; i++) {
      for (int j = 0; j < size; j++) {
        if (arr[j]>arr[j+1]) {
          // Swap arr[j] and arr[j+1]
          Btemp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = Btemp;
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
    MergeSort(arr, 0, size-1);
  }

};
