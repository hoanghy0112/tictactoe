#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "../draw/index.h"

using namespace std;

void playPage(int width, int height) {
   int board[9][9] = {0};
   int choosingX = width / 2;
   int choosingY = height / 2;

   int currentPlayer = 1;
   bool winningState = false;

   char inputChar;

   while (!winningState) {
      system("cls");

      choosingX += width;
      choosingX %= width;
      choosingY += height;
      choosingY %= height;

      drawBoard(width, height, board, choosingX, choosingY);
      cout << "Press up, down, left, right arrow to move\n";
      cout << "Press Enter to play\n";
      cout << "Press ESC to escape\n";
      inputChar = _getch();
      // cout << (int) inputChar = _getch();

      switch (int(inputChar)) {
         case 27: 
            winningState = true;
            break;
         case 13: 
            if (board[choosingX][choosingY] == 0) board[choosingX][choosingY] = currentPlayer;
            if (currentPlayer == 1) currentPlayer = 2;
            else currentPlayer = 1;
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
   }
}