#include <iostream>

#include <ai/core/Algorithm.hpp>

using namespace std;


float returnScore(bool isMax, float score) {
   if (isMax) return -score;
   else return score;
}

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

   currentNode.value = returnScore(isMax, 9999);

   if (board.isTerminal())
   {
      Node returnNode;
      returnNode.state = TERMINAL;
      returnNode.point = currentMove;

      float score = board.getWinPoint() - depth;

      returnNode.value = returnScore(isMax, score);

      return returnNode;

   } else if (depth >= maxDepth) {
      Node returnNode;
      returnNode.point = currentMove;

      const float score = board.getHeuristicScore() - depth;

      returnNode.value = returnScore(isMax, score);

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
            beta = min(beta, currentNode.value);
         }

         currentNode.point.type = nextMove.type;

         if (depth == 1) {
            cout << currentNode.value << endl;
         }

         if (alpha != 0 && beta != 0 && alpha > beta) break;
      }
   }

   if (isFull) {
      currentNode.point.x = -1; 
      currentNode.point.y = -1; 
      currentNode.value = 0;
      currentNode.point.type = UNDEFINED;
   }

   return currentNode;
}

Point generateMove(Board board, int maxDepth) {
   Node nextMove = minimap(board, 0, 0, 0, true, maxDepth);

   PointType newType;
   // if (board.getCurrentMove().type == X) newType = O;
   // else newType = X;

   Point returnPoint = nextMove.point;
   // returnPoint.x = nextMove.point.x;
   // returnPoint.y = nextMove.point.y;
   return returnPoint;
}
