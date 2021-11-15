#include "ai.hpp"

const int LENGTH = 100000;
int boardListLength = 0;
Board boardList[LENGTH];

Point currentPoint;

void drawPoint(PointType** board) {
   cout << "\n";
   for (int x = 0; x < WIDTH; x++) {
      for (int y = 0; y < HEIGHT; y++) {
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
   newBoard.data = new PointType*[board.width];
   for (int x = 0; x < board.width; x++) {
      newBoard.data[x] = new PointType[board.height];
      for (int y = 0; y < board.height; y++) {
         newBoard.data[x][y] = board.data[x][y];
      }
   }
   return newBoard;
}

float minNum(float first, float second) {
   if (first < second) return first;
   else return second;
}

float maxNum(float first, float second) {
   if (first > second) return first;
   else return second;
}

bool wouldBeChecked(Board board, Point currentMove, int x, int y, int radius = 2) {
   const int width = board.width;
   const int height = board.height;

   int minX = maxNum(x - radius, 0);
   int minY = maxNum(y - radius, 0);
   int maxX = minNum(x + radius, width);
   int maxY = minNum(y + radius, height);

   int currentX = currentMove.x;
   int currentY = currentMove.y;

   if (
      currentX <= maxX && 
      currentX >= minX &&
      currentY <= maxY && 
      currentY >= minY) {
         // cout << currentMove.x << "; " << currentMove.y << "\n";
         // cout << minX << "; " << minY << "\n";
         return true;
      } 

   // for (int iterX = minX; iterX < maxX; iterX++)
   //    for (int iterY = minY; iterY < maxY; iterY++) {
   //       if (board.data[iterX][iterY] != NONE) return true;
   //    }

   return false;
}

bool isEqual(Board first, Board second) {
   if (first.width != second.width || first.height != second.height) return false;

   const int width = first.width;
   const int height = first.height;

   for (int x = 0; x < width; x++)
      for (int y = 0; y < width; y++)
      {
         if (first.data[x][y] != second.data[x][y]) return false;
      }
   
   return true;
}

bool isIn(Board item, Board* boardList) {
   for (int i = 0; i < boardListLength; i++) {
      if (isEqual(item, boardList[i])) return true;
   }
   return false;
}


bool assess(Board board, PointType currentPlayer, int winPoint)
{
   bool isWin = winningCheck(
       board.width,
       board.height,
       board.data,
       currentPlayer, 
       winPoint);
   return isWin;
}

float heuristic(Board boardData, Point currentMove, int winPoint) {
   const int width = boardData.width;
   const int height = boardData.height;

   const int type = currentMove.type;
   const int pointX = currentMove.x;
   const int pointY = currentMove.y;

   PointType** board = boardData.data;
   float maxPoint = 0;

   const int direction[4][2] = {
      {1, -1}, {1, 0}, {0, 1}, {1, 1},
   };

   for (int i = 0; i < 4; i++) {
      int newX = pointX;
      int newY = pointY;

      int point = 0;

      do {
         newX += direction[i][0];
         newY += direction[i][1];

         point++;

         if (newX < 0 || newX >= width || newY < 0 || newY >= height) break;
      } while (board[newX][newY] == type);

      newX = pointX;
      newY = pointY;
      do {
         newX -= direction[i][0];
         newY -= direction[i][1];

         point++;

         if (newX < 0 || newX >= width || newY < 0 || newY >= height) break;
      } while (board[newX][newY] == type);
      point--;

      maxPoint = maxNum(maxPoint, point);
   }

   float maxPointOpposite = 0;
   for (int i = 0; i < 4; i++) {
      int newX = pointX;
      int newY = pointY;

      int point = 0;

      do {
         newX += direction[i][0];
         newY += direction[i][1];

         if (newX < 0 || newX >= width || newY < 0 || newY >= height) break;

         point++;
      } while (board[newX][newY] != type && board[newX][newY] != NONE);

      newX = pointX;
      newY = pointY;
      do {
         newX -= direction[i][0];
         newY -= direction[i][1];

         if (newX < 0 || newX >= width || newY < 0 || newY >= height) break;

         point++;
      } while (board[newX][newY] != type && board[newX][newY] != NONE);
      point--;

      maxPointOpposite = maxNum(maxPointOpposite, point);
   }
   maxPointOpposite--;

   // if (maxPoint - maxPointOpposite == 1) {
   //    maxPoint += 0.5;
   // }
   if (maxPointOpposite >= winPoint) maxPoint = winPoint - 0.1;
   maxPoint = maxNum(maxPoint, maxPointOpposite) + 
      minNum(maxPoint, maxPointOpposite) / winPoint;
   cout << "maxPoint: " << maxPoint << "\n";
   return maxPoint;
}

int times = 0;

Node minimap(
    Board board,
    Point currentMove,
    int depth,
    float alpha,
    float beta,
    bool isMax,
    int winPoint)
{
   Node currentNode;
   bool isFull = true;

   if (isMax) currentNode.value = -9999;
   else currentNode.value = 9999;

   if (assess(board, currentMove.type, winPoint))
   {
      Node returnNode;
      returnNode.point.x = -1;
      returnNode.point.y = -1;

      int score = PRIMARY_POINT - depth;

      if (isMax) returnNode.value = -score;
      else returnNode.value = +score;

      return returnNode;
   } else if (depth > 2) {
      Node returnNode;
      const float score = heuristic(board, currentMove, winPoint) * PRIMARY_POINT / winPoint - depth;

      if (isMax) returnNode.value = -score;
      else returnNode.value = +score;

      return returnNode;
   }


   for (int i = 0; i < board.width * board.height; i++)
   {
      const int x = i / board.height;
      const int y = i % board.height;

      if (board.data[x][y] == NONE)
      {
         isFull = false;

         if (!wouldBeChecked(board, currentMove, x, y, 2)) continue;
         times++;

         Board newBoard = copyBoard(board);
         Point nextMove;

         // if (isIn(newBoard, boardList)) continue;
         // else boardListLength++;

         if (currentMove.type == X) nextMove.type = O;
         else nextMove.type = X;
         nextMove.x = x;
         nextMove.y = y;
         newBoard.data[x][y] = nextMove.type;

         Node childNode = minimap(newBoard, nextMove, depth + 1, beta, alpha, !isMax, winPoint); 
         childNode.point.x = x;
         childNode.point.y = y;
         // childNode.value = childNode.value;

         if (isMax) {
            currentNode = max(currentNode, childNode);
            alpha = maxNum(alpha, currentNode.value);
         } else {
            currentNode = min(currentNode, childNode);
            alpha = minNum(alpha, currentNode.value);
         }
         if (depth == 2) {
            drawBoard(newBoard);
            cout << "currentNode: " << currentNode.point.x << "; " << currentNode.point.y << "\n";
            cout << "currentNode value: " << currentNode.value << "\n";
         }

         if (alpha != 0 && beta != 0 && alpha > beta) break;
      }
   }

   if (isFull) {
      currentNode.point.x = -1; 
      currentNode.point.y = -1; 
      currentNode.value = 0;
   }

   if (depth == 0) cout << "Eventually value: " << currentNode.value << "\n";

   return currentNode;
}

Point generateMove(int width, int height, PointType** board, Point currentMove, int winPoint) {
   Board boardData;
   boardData.width = width;
   boardData.height = height;
   boardData.data = board;

   Node currentNode;
   currentNode.value = 0;
   currentNode.point = currentMove;

   times = 0;
   Node nextMove = minimap(boardData, currentMove, 0, 0, 0, true, winPoint);
   cout << "Total loop: " << times << "\n";

   PointType newType;
   if (currentMove.type == X) newType = O;
   else newType = X;

   Point returnVal;
   returnVal.x = nextMove.point.x;
   returnVal.y = nextMove.point.y;
   returnVal.type = newType;
   return returnVal;
}