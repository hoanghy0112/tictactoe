#pragma once
#include "utils.hpp"

Point negamax(Node node, int depth);
Point generateMove(int width, int height, Point board[9][9], Point currentMove);