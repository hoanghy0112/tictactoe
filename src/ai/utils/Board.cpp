#include <iostream>

#include <ai/utils/Board.hpp>
#include <ai/utils/Math.hpp>
#include <ai/utils/Constants.hpp>

using namespace std;


Board::Board(
   int width, 
   int height, 
   PointType** data, 
   Point currentMove, 
   int winPoint, 
   float heuristicScore
) {
   this->width = width;
   this->height = height;
   this->winPoint = winPoint;
   this->data = data;
   this->winPoint = winPoint;

   this->currentMove = currentMove;
   if (this->getDataOf(currentMove.x, currentMove.y) == NONE) {
      this->setDataOf(currentMove.x, currentMove.y);
   }

   if (heuristicScore != 0) this->heuristicScore = heuristicScore; 
   else this->heuristicScore = this->calculateHeuristicScore();
}

Board::Board(
   int width, 
   int height, 
   Point currentMove, 
   int winPoint, 
   float heuristicScore
) {
   PointType** data;
   data = new PointType*[width];
   for (int i = 0; i < width; i++) {
      data[i] = new PointType[height];
      for (int j = 0; j < height; j++) {
         data[i][j] = NONE;
      }
   }

   this->width = width;
   this->height = height;
   this->winPoint = winPoint;
   this->data = data;
   this->winPoint = winPoint;

   this->currentMove = currentMove;
   if (this->getDataOf(currentMove.x, currentMove.y) == NONE) {
      this->setDataOf(currentMove.x, currentMove.y);
   }

   if (heuristicScore != 0) this->heuristicScore = heuristicScore; 
   else this->heuristicScore = this->calculateHeuristicScore();
}

bool Board::isValid(int x, int y) {
   if (
      x < 0 ||
      x >= width ||
      y < 0 ||
      y >= height
   ) return false;
   else return true;
}

int Board::getWidth() {
   return this->width;
}

int Board::getHeight() {
   return this->height;
}

int Board::getWinPoint() {
   return this->winPoint;
}

Point Board::getCurrentMove() {
   return this->currentMove;
}

float Board::getHeuristicScore() {
   if (this->heuristicScore == 0) 
      this->heuristicScore = this->calculateHeuristicScore();
   return this->heuristicScore;
}

PointType** Board::getData() {
   return this->data;
}

PointType Board::getDataOf(int x, int y) {
   if (isValid(x, y)) return OUT_OF_SCOPE;
   else return this->data[x][y];
}

bool Board::setDataOf(int x, int y) {
   if (isValid(x, y)) {
      this->data[x][y] = this->currentMove.type;
      return true;
   } 
   else return false;
}

bool Board::shouldBeChecked( int x, int y, int radius) {
   int currentX = this->getCurrentMove().x;
   int currentY = this->getCurrentMove().y;

   if (!this->isValid(x, y)) return false;
   if (this->getDataOf(x, y) != NONE) return false;
   if (abs(currentX - x) > radius || abs(currentY - y) > radius)
      return false;

   return true;
}

bool Board::isTerminal() {
   return (this->heuristicScore >= AIConstant::MAX_SCORE);
}

float Board::calculateHeuristicScore() {
   if (this->heuristicScore != 0) return this->heuristicScore;

   PointType currentType = this->currentMove.type;
   int currentX = this->currentMove.x;
   int currentY = this->currentMove.y;

   int directions[4][2] = {
      {0, 1}, {1, 0}, {1, 1}, {1, -1}
   };
   
   float maxScore = 0;

   for (int* direction : directions) {
      int reverses[2] = {-1, 1};

      // point is the number of cell with same type in a straight line.
      // point is initialized with 1 because it is current node.
      float point = 1;

      for (int reverse : reverses) {
         int newX = currentX;
         int newY = currentY;

         while (this->getDataOf(newX, newY) == currentType) {
            newX += reverse * direction[0];
            newY += reverse * direction[1];

            point++;
         }
      }

      maxScore = max(maxScore, point);
   }

   const int heuristicScore =  maxScore / this->winPoint * AIConstant::MAX_SCORE;
   this->heuristicScore = heuristicScore;

   return heuristicScore;
}

// Board Board::operator=(Board board) {
//    const int width = board.getWidth();
//    const int height = board.getHeight();

//    PointType** newData;
//    newData = new PointType*[width];

//    for (int x = 0; x < width; x++) {
//       newData[x] = new PointType[height];
//       for (int y = 0; y < height; y++) {
//          newData[x][y] = board.getDataOf(x, y);
//       }
//    }

//    return Board(
//       board.getWidth(), 
//       board.getHeight(), 
//       newData, 
//       board.getCurrentMove(),
//       board.getWinPoint()
//    );
// }

void Board::drawBoard() {
   PointType** board = this->getData();
   cout << "\n";
   for (int x = 0; x < this->getWidth(); x++) {
      for (int y = 0; y < this->getHeight(); y++) {
         if (this->getDataOf(x, y) == NONE) cout << " ";
         else if (this->getDataOf(x, y) == X) cout << "X";
         else cout << "O";
      }
      cout << "\n";
   }
}

Board Board::makeNewMove(Point newMove) {
   const int width = this->getWidth();
   const int height = this->getHeight();

   PointType** newData;
   newData = new PointType*[width];

   for (int x = 0; x < width; x++) {
      newData[x] = new PointType[height];
      for (int y = 0; y < height; y++) {
         newData[x][y] = this->getDataOf(x, y);
      }
   }

   return Board(
      this->getWidth(),
      this->getHeight(),
      newData,
      newMove,
      this->getWinPoint()
   );
}
