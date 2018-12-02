#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include "windows.h"
#include "Fruit.h"
using namespace std;

int purchase(Fruit x, int &bal);

int main(){
	bool run = true; // Flag for buying process
	bool eat = true; // Flag for eating process
	char input;	// User input
	char input2; // User input 2
	int balance = 20; // User balance
	Fruit backPack[8]={}; // User backpack

	Fruit menu[8] = {	// Store menu
		Fruit("Pineapple", 3, "Yum!.....Sweet and slightly tart"),
		Fruit("Cherry", 5, "Yum!.....Dark and sweet"),
		Fruit("Banana", 2, "Yum!.....Sweet and creamy"),
		Fruit("Lime", 2, "Ohaaa......WHA?@^A*$!!!!"),
		Fruit("Coconut", 8, "Yum!.....Mildly oily and sweet"),
		Fruit("Kiwifruit", 3, "Yum!...Mix of strawberry, banana and pineapple"),
		Fruit("Cantaloupe", 8, "Yum!...Juicy, unctuous and sweet"),
		Fruit("Mangosteen", 5, "Yum!...Combination of strawberry, peach, vanilla ice cream"),
	};

	Fruit *m = menu;
	cout << "Welcome to the Fruit Shop!" << '\n' << '\n';
	while(run){
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << '\n' << '\n' << "-----------------------" << '\n';
		cout << "Your balance is: " << balance << '\n';
		cout << "Press \'Z\' to quit" << '\n';
		cout << "-----------------------" << '\n';
		cout << "Shop inventory (keyboard 1~8): " << '\n';
		for(int i = 0; i < sizeof(menu)/sizeof(menu[0]); i++){
			cout << i+1 << ". " << menu[i].getName() << " Price: $" << menu[i].getPrice() << '\n';
		}

		cin >> input;

		switch (input){
			case '1':
				if (purchase(menu[0],balance)==1) {
					backPack[0]=*(m);
				}
				break;
			case '2':
				if (purchase(menu[1],balance)==1) {
					backPack[1]=*(m+1);
				}
				break;
			case '3':
				if (purchase(menu[2],balance)==1) {
					backPack[2]=*(m+2);
				}
				break;
			case '4':
				if (purchase(menu[3],balance)==1) {
					backPack[3]=*(m+3);
				}
				break;
			case '5':
				if (purchase(menu[4],balance)==1) {
					backPack[4]=*(m+4);
				}
				break;
			case '6':
				if (purchase(menu[5],balance)==1) {
					backPack[5]=*(m+5);
				}
				break;
			case '7':
				if (purchase(menu[6],balance)==1) {
					backPack[6]=*(m+6);
				}
				break;
			case '8':
				if (purchase(menu[7],balance)==1) {
					backPack[7]=*(m+7);
				}
				break;
			case 'z':
			case 'Z':
				run=false;
				break;
			default:
				cout << '\n' << "Please select a valid number!" << '\n';
				continue;
		}
	}

	while(eat){
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		cout << '\n' << '\n'<< "Time to eat the fruits !!" << '\n';
		cout << "Press Z to quit" << '\n';
		cout << "My backPack: " << '\n';

		for (int i = 0; i < sizeof(backPack)/sizeof(backPack[0]); i++) {
			if (backPack[i].getName()!="") {
				cout << i+1 << ". " << backPack[i].getName() << " X " << backPack[i].getAmount() << '\n';
			}
		}

		cin >> input2;

		switch (input2){
			case '1':
	      cout << backPack[0].use() << '\n';
				break;
			case '2':
				cout << backPack[1].use() << '\n';
				break;
			case '3':
				cout << backPack[2].use() << '\n';
				break;
			case '4':
				cout << backPack[3].use() << '\n';
				break;
			case '5':
				cout << backPack[4].use() << '\n';
				break;
			case '6':
				cout << backPack[5].use() << '\n';
				break;
			case '7':
				cout << backPack[6].use() << '\n';
				break;
			case '8':
				cout << backPack[7].use() << '\n';
				break;
			case 'z':
			case 'Z':
				eat=false;
				break;
			default:
				cout << '\n' << "Please select a valid number!" << '\n';
				break;
		}
	}


	system("pause" );
	return 0;
}


// Purchase function takes a fruit object and user balance
int purchase(Fruit x, int &bal){
	if (bal-x.getPrice()>=0){
		bal -= x.getPrice();
		cout << '\n' << "Purchased " << x.getName() << " For " << x.getPrice() << " Bucks"  << '\n'; // If user can afford
		return 1;
	}else{
		cout <<	'\n' << "InsufficientFund!!!!!!!" << '\n'; // If user can't afford
		return 0;
	}
}
