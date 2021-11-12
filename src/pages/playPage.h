#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "../draw/index.h"

using namespace std;

void playPage(int width, int height) {
   int board[9][9] = {0};
   int choosingX = width / 2;
   int choosingY = height / 2;
   bool winningState = false;

   char inputChar;

   while (!winningState) {
      system("cls");

      choosingX += width;
      choosingX %= width;
      choosingY += height;
      choosingY %= height;

      drawBoard(width, height, board, choosingX, choosingY);
      inputChar = _getch();
      // cout << (int) inputChar;

      switch (int(inputChar)) {
         case 27: 
            winningState = true;
            break;
         case 72:
            choosingY -= 1;
            break;
         case 80: 
            choosingY += 1;
            break;
         case 77: 
            choosingX += 1;
            break;
         case 75: 
            choosingX -= 1;
            break;
      }

      // Sleep(1);
   }
}