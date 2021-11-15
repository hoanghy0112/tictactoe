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
   currentMove.x = 3;
   currentMove.y = 5;
   currentMove.type = X;
   board[4][4] = X;
   board[3][5] = X;
   board[3][4] = O;
   // board[0][2] = X;
   // board[2][2] = O;
   // board[2][1] = X;
   // board[0][0] = O;


   for (int i = 0; i < 99; i++) {
      Point newMove = generateMove(WIDTH, HEIGHT, board, currentMove, 5);
      if (newMove.x == -1 || newMove.y == -1) {
         cout << "\n" << currentMove.type << " is the winner\n";
         break;
      }
      board[newMove.x][newMove.y] = newMove.type;
      currentMove = newMove;
      drawPoint(board);
   }

   Board testBoard;
   testBoard.width = WIDTH;
   testBoard.height = HEIGHT;
   testBoard.data = board;
   drawBoard(testBoard);
   cout << heuristic(testBoard, currentMove, 5);
   
   cout << "\nFinish\n";

   return 0;
}