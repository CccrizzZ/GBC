#include <iostream>
#include <vector>
using namespace std;

class Classy
{
private:
	int foo;
public:
	Classy() { foo = 0; }
	Classy(int f):foo(f) { } // Non-default constructor.
	int GetFoo() { return foo; }
};

int main()
{
	vector<int> iVec;
	iVec.reserve(10); // Try to reserve if you know the max number of elements you need.
	cout << "iVec capacity: " << iVec.capacity() << endl; // It's current allocated capacity.
	cout << "iVec actual size: " << iVec.size() << endl;  // The number of initialized elements in the vector.
	cout << "iVec max size: " << iVec.max_size() << endl; // How many elements the vector COULD potentially hold.
	iVec.push_back(7);
	iVec.push_back(23);
	iVec.push_back(69);
	iVec.back() = 42; // Accesses last element and also can set with =.
	iVec.push_back(79);
	iVec.push_back(117);
	iVec.push_back(33);
	iVec.push_back(-50);
	iVec.pop_back(); // Removes last element.
	for (int i = 0; i < iVec.size(); i++)
		cout << iVec[i] << ' ';
	cout << endl;
	iVec.shrink_to_fit(); // Removes empty elements.
	cout << "iVec capacity: " << iVec.capacity() << endl << endl;

	// And now for something a little classier.

	vector<Classy*> cVec; // A vector that holds pointers to a class object. We'll do this the most.
	cVec.reserve(3);
	cout << "cVec actual size: " << cVec.size() << endl; // Still an empty vector.
	cVec.push_back(new Classy(42)); // Creating dynamic Classy object and invoking non-default.
	cVec.push_back(new Classy()); // Same but invoking default constructor.
	cVec.push_back(new Classy(99));
	// Vector now full, and any subsequent calls will reallocate storage. But we don't notice it.
	cVec.push_back(new Classy(-9001));
	for (int i = 0; i < cVec.size(); i++)
		cout << cVec[i]->GetFoo() << ' '; // Remember this vector holds POINTERS to Classy objects.
	cout << endl;
	for (int i = 0; i < cVec.size(); i++)
	{
		delete cVec[i];    // De-allocating classy objects.
		cVec[i] = nullptr; // Do we really need to do this? No. But I don't like my pointers to dangle.
	}
	cVec.clear(); // Clearing out null pointers.
	cout << "cVec capacity: " << cVec.capacity() << endl; // Still have 4 elements allocated.
	cout << "cVec actual size: " << cVec.size() << endl;  // But they're empty.
	cVec.resize(10, nullptr); // Resizes the vector and initializes all pointers to null.
	cout << "cVec capacity: " << cVec.capacity() << endl; 
	cout << "cVec actual size: " << cVec.size() << endl; 
	for (int i = 0; i < cVec.size(); i++)
		cVec[i] = new Classy(9+i*10); // This vector is now dressed to the nines. Well... to the ninety-nines.
	for (int i = 0; i < cVec.size(); i++)
		cout << cVec[i]->GetFoo() << ' '; // See?
	cout << endl;
	// One final clean-up.
	for (int i = 0; i < cVec.size(); i++)
	{
		delete cVec[i];    
		cVec[i] = nullptr;
	}
	// Classy dismissed!
	system("pause");
	return 0;
}