#pragma once

#include <ai/utils/Point.hpp>
#include <ai/utils/Board.hpp>
#include <ai/utils/Math.hpp>
#include <ai/utils/Constants.hpp>

Node minimax(Board board, int depth, float alpha, float beta, bool isMax, int maxDepth);
Point generateMove(Board board, int maxDepth);