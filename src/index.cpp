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
   playPage(5, 5);

   cout << "\n";
   // system("pause");
   return 0;
}
