#pragma once
#define ROWS 24
#define COLS 32

class Player{
public:
	int m_x;
	int m_y;
	Player(int x, int y) : m_x(x), m_y(y){

	}
};


class BGTile{
public:
  char m_cOutput;
  bool m_bisObstacle;
  bool m_bisHazard;
  char tiles[ROWS][COLS];

	// Build the Map from Level.txt and Output
  bool BuildMap(){
    ifstream inFile("Level.txt");
    if (inFile.is_open()) {
			// Traverse 2d array of this object
      for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
          inFile >> tiles[row][col]; // Putting all text character into the 2d array of this object
        }
      }
      inFile.close();
      return 0; // If complete return 0
    }
    return 1; // If no file return 1
  }

  void PrintMap(const Player& p){
		// Traverse 2d array of this object
		for (int row = 0; row < ROWS; row++) {
      for (int col = 0; col < COLS; col++) {
				// If tile's X and Y equals player's X and Y cout "@"
        if (row == p.m_y && col == p.m_x) {
          cout << "@";
        }else{
          cout << tiles[row][col];
        }
      }
      cout << "\n";
    }
  }

};
