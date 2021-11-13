#include "ai.hpp"


void drawPoint(PointType** board) {
   cout << "\n";
   for (int x = 0; x < WIDTH; x++) {
      for (int y = 0; y < WIDTH; y++) {
         if (board[x][y] == NONE) cout << " ";
         else if (board[x][y] == X) cout << "X";
         else cout << "O";
      }
      cout << "\n";
   }
}

void drawBoard(Board boardData) {
   PointType** board = boardData.data;
   cout << "\n";
   for (int x = 0; x < boardData.width; x++) {
      for (int y = 0; y < boardData.height; y++) {
         if (board[x][y] == NONE) cout << " ";
         else if (board[x][y] == X) cout << "X";
         else cout << "O";
      }
      cout << "\n";
   }
}

Board copyBoard(Board board) {
   Board newBoard;
   newBoard.width = board.width;
   newBoard.height = board.height;
   cout << "fasfd";
   newBoard.data = new PointType*[board.width];
   for (int x = 0; x < board.width; x++) {
      newBoard.data[x] = new PointType[board.height];
      for (int y = 0; y < board.height; y++) {
         newBoard.data[x][y] = board.data[x][y];
      }
   }
   return newBoard;
}


bool assess(Board board, PointType currentPlayer, int winPoint)
{
   bool isWin = winningCheck(
       board.width,
       board.height,
       board.data,
       currentPlayer);
   return isWin;
}

Node negamax(
    Board board,
    PointType currentPlayer,
    int score,
    Node parentNode,
    int depth,
    int winPoint)
{
   Node currentNode;
   int alpha, beta;

   if (parentNode.value <= 0) { // current node is max node
      currentNode.value = -9999;
      beta = parentNode.value;
   } else {
      currentNode.value = 9999;
      alpha = parentNode.value;
   } 

   if (assess(board, currentPlayer, winPoint))
   {
      Node returnNode;
      if (parentNode.value <= 0) returnNode.value = score;
      else returnNode.value = -score;
      return returnNode;
   }

   for (int i = 0; i < board.width * board.height; i++)
   {
      const int x = i / board.height;
      const int y = i % board.height;

      cout << "before if";
      if (board.data[x][y] == NONE)
      {
         cout << "\nbefore draw board";
         drawBoard(board);
         cout << depth << "\n";
         cout << "before copyBoard";
         Board newBoard = copyBoard(board);
         cout << "after copyBoard";
         PointType nextTurn;

         if (currentPlayer == X) nextTurn = O;
         else nextTurn = X;
         newBoard.data[x][y] = nextTurn;

         Node childNode = negamax(newBoard, nextTurn, score - 1, currentNode, depth + 1); 
         childNode.point.x = x;
         childNode.point.y = y;
         childNode.value = -childNode.value;

         currentNode = max(currentNode, childNode);
         
         if (parentNode.value <= 0) { // current node is max node
            alpha = currentNode.value;
         } else {
            beta = currentNode.value;
         }

         if (alpha > beta) break;
      }
   }

   return currentNode;
}


Point generateMove(int width, int height, PointType** board, Point currentMove) {
   Board boardData = {
      width: width,
      height: height,
      data: board
   };

   Node parentNode = {
      value: 0,
      point: currentMove
   };

   Node nextMove = negamax(boardData, currentMove.type, PRIMARY_POINT, parentNode, 0);

   PointType newType;
   if (currentMove.type == X) newType = O;
   else newType = X;

   Point returnVal = {
      x: nextMove.point.x,
      y: nextMove.point.y,
      type: newType
   };
   return returnVal;
}