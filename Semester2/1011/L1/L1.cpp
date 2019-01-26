#include "pch.h"
#include "conio.h"
#include "Achievement.h"
#include "Platform.h"
#include "Game.h"
#include "Data.cpp"
using namespace std;


int main(){

  char input;
  // Flag for platform loop
  bool running = true;

  // The loop
  while (running) {
    // FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    cout << '\n';
    cout << '\n' << "-----------------" << '\n' << '\n';
    cout << "Choose Your Platform :" << '\n';
    cout << "Name: " << " " << " " << " " << " " << "Manufacturer: "  << '\n';
    cout << "1. " << p[0].getName() << " " << " " << " " << " " << " " << " " << " " << " " << p[0].getManu() << '\n';
    cout << "2. " << p[1].getName() << " " << " " << " " << " " << " "  << " " << p[1].getManu() << '\n';
    cout << "3. " << p[2].getName() << " " << " " << " " << " " << " " << " " << " " << p[2].getManu() << '\n';
    cout << "4. " << p[3].getName() << " " << " " << " " << " " << p[3].getManu() << '\n';
    cout << "5. " << p[4].getName() << " " << " " << " " << " " << " " << " " << " " << p[4].getManu() << '\n';
    cout << "press \'e\' to exit" << '\n';
    cout << '\n' << "-----------------" << '\n' << '\n';

		input = _getch();
    switch (input) {
      case 'e':
      running = false;
      break;
      case '1':
      p[0].render();

      continue;
      case '2':
      p[1].render();

      continue;
      case '3':
      p[2].render();

      continue;
      case '4':
      p[3].render();

      continue;
      case '5':
      p[4].render();

      continue;
			default:
			cout << "Please select choices given above !" << '\n';
			continue;
    }
    running = false;
  }



  return 0;
}
