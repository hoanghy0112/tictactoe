#pragma once
#include <iostream>

using namespace std;

enum PointType
{
   NONE,
   X,
   O
};

struct Point
{
   int x;
   int y;
   PointType type;
};

struct Board
{
   int width;
   int height;
   PointType** data;
};

struct Node {
   int value;
   Point point;
};


//* code for board item:
//* 0: an empty cell
//* 1: X cell
//* 2: O cell

//! CELL_WIDTH and CELL_HEIGHT must be an odd number
const int CELL_WIDTH = 9;
const int CELL_HEIGHT = 5;

const char CHOOSING_CHAR = '?';
const char X_CHAR = 'X';
const char O_CHAR = 'O';

const char CHAR_CODE[3] = {' ', 'X', 'O'};

bool winningCheck(int width, int height, PointType **board, PointType type, int winPoint = 3);
Node max(Node first, Node second);
Node min(Node first, Node second);