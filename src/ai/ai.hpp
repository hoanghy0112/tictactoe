#pragma once
#include "utils.hpp"

bool assess(Board board, PointType currentPlayer, int winPoint = 3);
Node negamax(Board board, PointType currentPlayer, int score, Node parentAlphaBeta, int depth, int winPoint = 3);
Point generateMove(int width, int height, PointType** board, Point currentMove);