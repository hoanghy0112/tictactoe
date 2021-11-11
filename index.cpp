#include <iostream>

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
   cout << "Hello world\n";

   cout << "New line\n";

   return 0;
}
