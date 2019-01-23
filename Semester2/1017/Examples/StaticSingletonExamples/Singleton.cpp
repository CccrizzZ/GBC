#include <iostream>
using namespace std;


// Singleton Class is a class with a global pointer and lazy initialization
class Singleton{
private:
	static Singleton* instance;
	Singleton(){ // What does this signify?
		cout << "Constructed..." << endl;
	}
public:
	static Singleton* GetInstance(){
		if (instance == nullptr)
			instance = new Singleton();
		return instance;
	}
	void Whatever(){
		cout << "Bruh..." << endl;
	}
};


// Global pointer initialization
Singleton* Singleton::instance = nullptr;


// Main function
int main(void){
	// Singleton mySing
  // Can't do this anymore
  // Because constuctor is private
	Singleton* s = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();
	s->Whatever();
	s2->Whatever();
	// Need proof?
	cout << s << " " << s2 << endl;
	system("pause");
	return 0;
}
