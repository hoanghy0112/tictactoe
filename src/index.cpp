#include <iostream>
#include "pages/index.h"
// #include "draw/index.h"

using namespace std;

void printHorizontalLine(int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << " -------";
   }
   cout << endl;
}

void printVerticalLine(int size)
{
   for (int i = 0; i < size + 1; i++)
   {
      cout << "|      ";
   }
   cout << endl;
}

void printBoard(int size)
{
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size; j++)
      {
      }
   }
}

int main()
{
   // int board[9][9] = {0};
   // board[1][1] = 1;
   // board[2][3] = 2;
   // int width = 4, height = 4;

   // drawBoard(width, height, board, 1, 1);
   playPage(5, 5);

   cout << "\n";
   // system("pause");
   return 0;
}
