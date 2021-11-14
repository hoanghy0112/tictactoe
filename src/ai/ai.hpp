#pragma once
#include "utils.hpp"


const int WIDTH = 8;
const int HEIGHT = 8;
const int PRIMARY_POINT = 20;

void drawPoint(PointType** board);
void drawBoard(Board boardData);

bool assess(Board board, PointType currentPlayer, int winPoint = 3);
Node negamax(Board board, PointType currentPlayer, int score, Node parentAlphaBeta, int depth, int alpha = 0, int beta = 0, int winPoint = 3);
Point generateMove(int width, int height, PointType** board, Point currentMove, int winPoint = 3);