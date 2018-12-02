#pragma once
#include <iostream>
using namespace std;

class Fruit {
private:
	int fprice;
	string ftaste;
	string fname;
public:
	int amount=1;
	// Setters
	Fruit(){}
	Fruit(string name, int price, string taste){
		setName(name);
		setPrice(price);
		setTaste(taste);
	}

	void setName(string name){
		fname = name;
	}
	void setPrice(int price){
		fprice = price;
	}
	void setTaste(string taste){
		ftaste = taste;
	}



	// Getters
	string use(){
		if (amount-1>=0) {
			amount--;
			cout << '\n' << "There is " << amount << " " << fname << " in the backpack" << '\n';
			return this -> ftaste;
		}else{
			cout << '\n' << "You ran out of " << fname << " !" << '\n';
			return "OMG You need a refill !";
		}
	}



	int getAmount(){
		return amount;
	}
	string getName(){
		return fname;
	}
	int getPrice(){
		return fprice;
	}
};
