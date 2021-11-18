#include <iostream>

#include <ai/core/Algorithm.hpp>
#include <ai/utils/Board.hpp>
#include <ai/utils/Point.hpp>
#include <ai/utils/Constants.hpp>
#include <ai/utils/Math.hpp>

using namespace std;


Node minimap(
    Board board,
    int depth,
    float alpha,
    float beta,
    bool isMax,
    int maxDepth
) {
   const int width = board.getWidth();
   const int height = board.getHeight();
   Point currentMove = board.getCurrentMove();

   Node currentNode;
   bool isFull = true;

   if (isMax) currentNode.value = -9999;
   else currentNode.value = 9999;

   if (board.isTerminal())
   {
      Node returnNode;
      returnNode.state = TERMINAL;

      float score = AIConstant::MAX_SCORE - depth;

      if (isMax) returnNode.value = -score;
      else returnNode.value = +score;

      return returnNode;
   } else if (depth >= maxDepth) {
      Node returnNode;

      const float score = board.getHeuristicScore() * AIConstant::MAX_SCORE / board.getWinPoint() - depth;

      if (isMax) returnNode.value = score;
      else returnNode.value = -score;

      return returnNode;
   }


   for (int i = 0; i < width * height; i++)
   {
      const int x = i / height;
      const int y = i % height;

      if (board.shouldBeChecked(x, y))
      {
         isFull = false;

         Point nextMove(!currentMove);

         Board newBoard = board.makeNewMove(nextMove);

         Node childNode = minimap(newBoard, depth + 1, beta, alpha, !isMax, maxDepth); 
         childNode.point.x = x;
         childNode.point.y = y;

         if (isMax) {
            currentNode = maxNode(currentNode, childNode);
            alpha = max(alpha, currentNode.value);
         } else {
            currentNode = minNode(currentNode, childNode);
            alpha = min(alpha, currentNode.value);
         }

         if (alpha != 0 && beta != 0 && alpha > beta) break;
      }
   }

   if (isFull) {
      currentNode.point.x = -1; 
      currentNode.point.y = -1; 
      currentNode.value = 0;
   }


   return currentNode;
}

Point generateMove(Board board, int maxDepth) {
   Node nextMove = minimap(board, 0, 0, 0, true, maxDepth);

   PointType newType;
   if (board.getCurrentMove().type == X) newType = O;
   else newType = X;

   Point returnVal;
   returnVal.x = nextMove.point.x;
   returnVal.y = nextMove.point.y;
   returnVal.type = newType;
   return returnVal;
}
