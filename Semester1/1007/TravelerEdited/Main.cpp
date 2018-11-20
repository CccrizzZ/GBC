#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
#include "BGTile.h"




int main() {
  // Variables
  bool quit = false;
  BGTile map;
  char input;
  Player player(COLS/2, ROWS/2);

  // Build Map
  if (map.BuildMap()==1) {
    cout << "Failed to Build Map" << '\n';
    return 1;
  }

  // Print Map
  while (!quit){
		map.PrintMap(player);
		input = _getch();
		switch (input){
			case 'w':
			case 'W':
				if (player.m_y > 0 && map.tiles[player.m_y -1][player.m_x] != '+')
					player.m_y--;
				break;
			case 's':
			case 'S':
				if (player.m_y < ROWS-1 && map.tiles[player.m_y + 1][player.m_x] != '+')
					player.m_y++;
				break;
			case 'a':
			case 'A':
				if (player.m_x > 0 && map.tiles[player.m_y][player.m_x - 1] != '+')
					player.m_x--;
				break;
			case 'd':
			case 'D':
				if (player.m_x < COLS-1 && map.tiles[player.m_y][player.m_x + 1] != '+')
					player.m_x++;
				break;
			case 'q':
			case 'Q':
				quit = true;
				break;
		}
		system("cls");
	}
  return 0;
}
