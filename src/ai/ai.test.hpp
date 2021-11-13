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

bool winningCheck(int width, int height, int board[9][9], int type, int winPoint = 3) {
   //* Vertical check
   for (int x = 0; x < width; x++) {
      int point = 0;
      for (int y = 0; y < height; y++) {
         if (board[x][y] == type) point++;
         else point = 0;
         if (point >= winPoint) return true;
      }
   }

   //* Horizontal check 
   for (int y = 0; y < height; y++) {
      int point = 0;
      for (int x = 0; x < width; x++) {
         if (board[x][y] == type) point++;
         else point = 0;
         if (point >= winPoint) return true;
      }
   }

   //* Diagonal check 
   for (int x = -height; x < width; x++) {
      int point = 0;
      for (int y = 0; y < height; y++) {
         int newX = x + y;
         if ( newX < 0 || newX > width) {
            continue;
         } 
         if (board[newX][y] == type) point++;
         else point = 0;
         if (point >= winPoint) return true;
      }
   }

   for (int x = 0; x < width + height; x++) {
      int point = 0;
      for (int y = 0; y < height; y++) {
         int newX = x - y;
         if ( newX < 0 || newX > width) {
            continue;
         } 
         if (board[newX][y] == type) point++;
         else point = 0;
         if (point >= winPoint) return true;
      }
   }

   return false;
}