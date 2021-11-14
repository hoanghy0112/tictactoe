#include <iostream>
#include "ai.hpp"

using namespace std;

int main() {
   PointType** board;
   board = new PointType*[WIDTH];

   for (int i = 0; i < WIDTH; i++) {
      board[i] = new PointType[HEIGHT];
   }

   for (int x = 0; x < WIDTH; x++) {
      for (int y = 0; y < HEIGHT; y++) {
         board[x][y] = NONE;
      }
   }

   Point currentMove;
   currentMove.x = 1;
   currentMove.y = 1;
   currentMove.type = X;
   board[0][1] = X;
   // board[0][1] = X;
   // board[1][0] = O;


   for (int i = 0; i < 9; i++) {
      Point newMove = generateMove(WIDTH, HEIGHT, board, currentMove, 3);
      if (newMove.x == -1 || newMove.y == -1) {
         cout << "\n" << currentMove.type << " is the winner\n";
         break;
      }
      board[newMove.x][newMove.y] = newMove.type;
      currentMove = newMove;
      drawPoint(board);
   }
   
   cout << "\nFinish\n";

   return 0;
}