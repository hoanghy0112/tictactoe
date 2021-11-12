#include <iostream>

using namespace std;


//* code for board item: 
//* 0: an empty cell
//* 1: X cell
//* 2: O cell


//! CELL_WIDTH and CELL_HEIGHT must be an odd number
const int CELL_WIDTH = 9;
const int CELL_HEIGHT = 5;

const char CHOOSING_CHAR = '?';
const char X_CHAR = 'X';
const char O_CHAR = 'O';

const char CHAR_CODE[3] = {' ', 'X', 'O'};

// TODO - Draw board function
void drawBoard(
      int columnNum, 
      int rowNum, 
      int board[9][9], 
      int choosingX = 0, 
      int choosingY = 0
) {
   for (int i = 0; i < columnNum; i++) {
      cout << " ";
      for (int j = 0; j < CELL_WIDTH; j++) {
         cout << "_";
      }
   }
   cout << "\n";

   for (int y = 0; y < rowNum; y++) {
      for (int cellHeightIter = 0; cellHeightIter < CELL_HEIGHT - 1; cellHeightIter++) {
         cout << "|";
         for (int x = 0; x < columnNum; x++) {
            if (x == choosingX && y == choosingY && cellHeightIter == CELL_HEIGHT / 2) {
                  for (int cellWidthIter = 0; cellWidthIter < CELL_WIDTH - 2; cellWidthIter++) {
                     if (cellWidthIter == CELL_WIDTH / 2 - 1) {
                        cout << ">" << CHAR_CODE[board[x][y]] << "<";
                     } else {
                        cout << " ";
                     }
                  }
            } else
            for (int cellWidthIter = 0; cellWidthIter < CELL_WIDTH; cellWidthIter++) {
               if (cellHeightIter == CELL_HEIGHT / 2 && cellWidthIter == CELL_WIDTH / 2) {
                  // if (x == choosingX && y == choosingY) cout << CHOOSING_CHAR;
                  cout << CHAR_CODE[board[x][y]];
               } else cout << " ";
            }
            cout << "|";
         }
         cout << "\n";
      }
      cout << "|";
      for (int i = 0; i < columnNum; i++) {
         for (int j = 0; j < CELL_WIDTH; j++) {
            cout << "_";
         }
         cout << "|";
      }
      cout << "\n";
   }
}