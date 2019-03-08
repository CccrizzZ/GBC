// #include <iostream>
// #include <cstdlib>
// using namespace std;
//
// // Absract class
// template <class T>
// class Array {
// private:
// 
// public:
//   T *aptr;
//   // Constructor
//   Array(int s){
//     // Set size
//     arraySize = s;
//
//     // point the T pointer to a new T type array
//     aptr = new T [s];
//
//     for (int i = 0; i < arraySize; i++) {
//       aptr[i] = rand() % 100 + 1;
//     }
//
//
//   }
//
//   // Return size
//   int getSize(){
//     return arraySize;
//   }
//
//   void printArr() {
//     for (int i = 0; i < arraySize; i++) {
//       cout << aptr[i] << ' ';
//     }
//   }
// };
//
//
//
//
// // Child class
// template <class T>
// class SortableArray : public Array<T>{
// public:
//   // Constructor
//   SortableArray(int s) : Array<T>(s){};
//
//   int Btemp;
//
//   // Bubble Sorting ASC
//   void BubbleSort(T arr[]){
//     for (int i = 0; i <= Array::arraySize; i++) {
//       for (int j = 0; j < Array::arraySize; j++) {
//         if (aptr[j]>aptr[j+1]) {
//           // Swap arr[j] and arr[j+1]
//           Btemp = aptr[j];
//           aptr[j] = aptr[j+1];
//           aptr[j+1] = Btemp;
//         }
//       }
//     }
//   }
//
// };
