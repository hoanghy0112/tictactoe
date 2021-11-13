#pragma once
#include "utils.hpp"


const int WIDTH = 3;
const int HEIGHT = 3;
const int PRIMARY_POINT = 20;

void drawPoint(PointType** board);
void drawBoard(Board boardData);

bool assess(Board board, PointType currentPlayer, int winPoint = 3);
Node negamax(Board board, PointType currentPlayer, int score, Node parentAlphaBeta, int depth, int winPoint = 3);
Point generateMove(int width, int height, PointType** board, Point currentMove);