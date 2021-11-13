#include <iostream>
#include "ai.hpp"

using namespace std;

int main() {
   PointType** board;
   board = new PointType*[9];

   for (int i = 0; i < 9; i++) {
      board[i] = new PointType[9];
   }

   for (int x = 0; x < WIDTH; x++) {
      for (int y = 0; y < WIDTH; y++) {
         board[x][y] = NONE;
      }
   }

   Point currentMove = {
      x: 1,
      y: 1,
      type: X,
   };
   for (int i = 0; i < 9; i++) {
      Point newMove = generateMove(WIDTH, HEIGHT, board, currentMove);
      board[newMove.x][newMove.y] = O;
      currentMove = newMove;
      drawPoint(board);
   }

   return 0;
}