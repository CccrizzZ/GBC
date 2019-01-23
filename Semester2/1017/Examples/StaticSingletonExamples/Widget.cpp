#include <iostream>
using namespace std;

class Widget{
private:
	static double price;
	int quantity;
public:
	void SetPrice(double p) { price = p; }
	void SetQuantity(int q) { quantity = q; }
	double GetPrice() const { return price; }
	int GetQuantity() const { return quantity; }
};

double Widget::price; // Is a must.

int main(void){
	Widget w1, w2, w3, w4;
	w1.SetPrice(99.99);
	w1.SetQuantity(5);
	w2.SetQuantity(10);
	cout << "w1: " << w1.GetPrice() << " " << w1.GetQuantity() << endl;
	cout << "w2: " << w2.GetPrice() << " " << w2.GetQuantity() << endl;
	//Widget::price = 42.99;
	w2.SetPrice(42.99);
	cout << "w1: " << w1.GetPrice() << " " << w1.GetQuantity() << endl;
	cout << "w2: " << w2.GetPrice() << " " << w2.GetQuantity() << endl;
	//Widget::SetPrice(69.99); // How can we make this valid?
	cout << w4.GetPrice() << endl;
	system("pause");
	return 0;
}
