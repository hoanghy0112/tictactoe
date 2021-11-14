#include "ai.hpp"

const int LENGTH = 100000;
int boardListLength = 0;
Board boardList[LENGTH];

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

int minInt(int first, int second) {
   if (first < second) return first;
   else return second;
}

int maxInt(int first, int second) {
   if (first > second) return first;
   else return second;
}

bool wouldBeChecked(Board board, int x, int y, int radius = 2) {
   const int width = board.width;
   const int height = board.height;

   int minX = maxInt(x - radius, 0);
   int minY = maxInt(y - radius, 0);
   int maxX = minInt(x + radius + 1, width);
   int maxY = minInt(y + radius + 1, height);

   for (int iterX = minX; iterX < maxX; iterX++)
      for (int iterY = minY; iterY < maxY; iterY++) {
         if (board.data[iterX][iterY] != NONE) return true;
      }

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

int times = 0;

Node minimap(
    Board board,
    PointType currentPlayer,
    int depth,
    int alpha,
    int beta,
    bool isMax,
    int winPoint)
{
   Node currentNode;
   bool isFull = true;

   if (isMax) currentNode.value = -9999;
   else currentNode.value = 9999;

   if (depth > 4) {
      Node returnNode;
      returnNode.value = +0;
      return returnNode;
   }

   if (assess(board, currentPlayer, winPoint))
   {
      Node returnNode;
      returnNode.point.x = -1;
      returnNode.point.y = -1;
      int score = PRIMARY_POINT - depth;
      if (depth % 2 == 0) returnNode.value = -score;
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

         if (!wouldBeChecked(board, x, y, 1)) continue;
         times++;

         Board newBoard = copyBoard(board);
         PointType nextTurn;

         if (currentPlayer == X) nextTurn = O;
         else nextTurn = X;
         newBoard.data[x][y] = nextTurn;

         Node childNode = minimap(newBoard, nextTurn, depth + 1, beta, alpha, !isMax, winPoint); 
         childNode.point.x = x;
         childNode.point.y = y;
         childNode.value = childNode.value;

         if (isMax) {
            currentNode = max(currentNode, childNode);
            alpha = maxInt(alpha, currentNode.value);
         } else {
            currentNode = min(currentNode, childNode);
            alpha = minInt(alpha, currentNode.value);
         }
         if (depth == 1) {
            // drawBoard(newBoard);
            // cout << "currentNode value: " << currentNode.value << "\n";
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
   Node nextMove = minimap(boardData, currentMove.type, 0, 0, 0, true, winPoint);
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