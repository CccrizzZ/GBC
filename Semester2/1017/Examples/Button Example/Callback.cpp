#include <iostream>
using namespace std;

// A function
void PrintSomething() {
	cout << "Something..." << endl;
}




// Define type void function
typedef void(*FuncPtrVoid)();


// Printing function
void PrintFactory(FuncPtrVoid f) {
	for (int i = 0; i < 5; i++){
    f();
  }
}



// Main
int main()
{
	PrintFactory(PrintSomething);
	system("pause");
	return 0;
}
