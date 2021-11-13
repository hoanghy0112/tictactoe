#include "ai.hpp"

const int PRIMARY_POINT = 20;

bool assess(Board board, PointType currentPlayer, int winPoint = 3)
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
    int winPoint = 3)
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

      if (board.data[x][y] == NONE)
      {
         Board newBoard = board;
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
}


Point generateMove(int width, int height, PointType** board, Point currentMove) {
   Board boardData = {
      width: width,
      height: height,
      data: board
   };

   Node parentNode = {
      value: 0
   };

   Node nextMove = negamax(boardData, currentMove.type, PRIMARY_POINT, parentNode, 0);

   return Point{
      x: nextMove.point.x,
      y: nextMove.point.y
   };
}