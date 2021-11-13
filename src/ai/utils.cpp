#include "utils.hpp"



Node max(Node first,Node second) {
   if (first.value > second.value) {
      return first;
   } else {
      return second;
   }
}

bool winningCheck(int width, int height, PointType **board, PointType type, int winPoint)
{
   //* Vertical check
   for (int x = 0; x < width; x++)
   {
      int point = 0;
      for (int y = 0; y < height; y++)
      {
         if (board[x][y] == type)
            point++;
         else
            point = 0;
         if (point >= winPoint)
            return true;
      }
   }

   //* Horizontal check
   for (int y = 0; y < height; y++)
   {
      int point = 0;
      for (int x = 0; x < width; x++)
      {
         if (board[x][y] == type)
            point++;
         else
            point = 0;
         if (point >= winPoint)
            return true;
      }
   }

   //* Diagonal check
   for (int x = -height; x < width; x++)
   {
      int point = 0;
      for (int y = 0; y < height; y++)
      {
         int newX = x + y;
         if (newX < 0 || newX > width)
         {
            continue;
         }
         if (board[newX][y] == type)
            point++;
         else
            point = 0;
         if (point >= winPoint)
            return true;
      }
   }

   for (int x = 0; x < width + height; x++)
   {
      int point = 0;
      for (int y = 0; y < height; y++)
      {
         int newX = x - y;
         if (newX < 0 || newX > width)
         {
            continue;
         }
         if (board[newX][y] == type)
            point++;
         else
            point = 0;
         if (point >= winPoint)
            return true;
      }
   }

   return false;
}