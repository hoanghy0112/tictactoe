#pragma once

#include "Point.hpp"

class Board {
   private: 
      // Width of the board
      int width;

      // Height of the board
      int height;

      // If have <winPoint> point with the same type in a straight line,
      // current player will be the winner.
      int winPoint;

      // Heuristic score of current move. The higher the point is, the more 
      // effective the move is.
      // It is a cache value of getHeuristicScore() 
      float heuristicScore;

      // CurrentMove contains information about where the last move is 
      // and who has played it.
      Point currentMove;

      // Map of the board
      PointType** data;

      // Set type of an item of board
      bool setDataOf(int x, int y);

      float calculateHeuristicScore();

   public: 
      Board();
      Board(
         int width, 
         int height, 
         PointType** board, 
         Point currentMove, 
         int winPoint,
         float heuristicScore = 0.0
      ); 
      Board(
         int width, 
         int height, 
         Point currentMove, 
         int winPoint,
         float heuristicScore = 0.0
      ); 
      Board(
         int width, 
         int height, 
         int winPoint
      ); 

      // Get basic information about the board.
      int getWidth();
      int getHeight();
      int getWinPoint();
      Point getCurrentMove();

      // get heuristic mark of current move
      // depth is max depth of minimax algorithm, if a node isn't terminal after
      // <depth> times, we use <heuristicMark> which obtained by this function to 
      // assess currentBoard and return it. 
      // Beside that, it will assign this->heuristicScore 
      // to the return value if depth == 0.
      float getHeuristicScore();

      // Get whole map of board
      PointType** getData();

      // Get type of an item in board
      PointType getDataOf(int x, int y);
      
      // check whether a cell should be checked or not
      // if its position exceed the border, it'll return false
      // or if the distance between it and currentMove is too far,
      // in this case, if its distance is greater than <radius>, 
      // the function will return false.
      bool shouldBeChecked(
         int x, 
         int y, 
         int radius = 2
      );

      // Check whether the coordiates is valid or not by compare it with 0, height
      // and with, if it exceed the border of the box, returns OUT_OF_SCOPE 
      bool isValid(int x, int y);

      // Check whether a board is terminal or not (one of two player win)
      bool isTerminal();

      Board& operator=(Board other);

      //! Quick draw the board for debugging
      //! Delete this in production app
      void drawBoard();

      Board makeNewMove(Point newMove);

      //! Add destructor function
      ~Board();
};

class A {
   public:
      int a;
      A() = default;
      A& operator=(A other) {
         this->a = other.a;
         return *this;
      }
};