#pragma once

enum PointType
{
   NONE,
   X,
   O,
};

struct Point
{
   int x;
   int y;
   PointType type = NONE;
};

Point generateMove(int width, int height, Point board[9][9], Point currentMove);