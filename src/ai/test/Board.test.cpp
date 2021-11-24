#include <iostream>
#include <stdexcept>

#include <ai/test/utils.hpp>
#include <ai/utils/Board.hpp>

using namespace std;

void test_with_board_3x3() {
   Board board(3, 3, Point(2, 2, X), 3);

   ASSERT_EQUAL_NUMBER(board.getWidth(), 3);
   ASSERT_EQUAL_NUMBER(board.getHeight(), 3);
   ASSERT_EQUAL_NUMBER(board.getWinPoint(), 3);
   ASSERT_EQUAL_STRING(board.getCurrentMove().to_string(), Point(2,2,X).to_string());

   ASSERT_EQUAL_BOOLEAN(board.shouldBeChecked(2, 2), false);

   ASSERT_EQUAL_NUMBER(board.getHeuristicScore(), 1.0);

   ASSERT_EQUAL_NUMBER(board.getDataOf(0, 0), NONE);
   ASSERT_EQUAL_NUMBER(board.getDataOf(1, 1), NONE);
   ASSERT_EQUAL_NUMBER(board.getDataOf(3, 3), OUT_OF_SCOPE);
   ASSERT_EQUAL_NUMBER(board.getDataOf(2, 2), X);

   Board newBoard = board.makeNewMove(Point(2, 1, X));

   ASSERT_EQUAL_NUMBER(newBoard.getHeuristicScore(), 2.0);
   ASSERT_EQUAL_NUMBER(newBoard.getDataOf(0, 0), NONE);
   ASSERT_EQUAL_NUMBER(newBoard.getDataOf(1, 1), NONE);
   ASSERT_EQUAL_NUMBER(newBoard.getDataOf(3, 3), OUT_OF_SCOPE);
   ASSERT_EQUAL_NUMBER(newBoard.getDataOf(2, 1), X);
   ASSERT_EQUAL_NUMBER(newBoard.getDataOf(2, 2), X);
}

void test_with_board_5x5() {
   Board board(5, 5, 5);

   ASSERT_EQUAL_NUMBER(board.getWidth(), 5);
   ASSERT_EQUAL_NUMBER(board.getHeight(), 5);
   ASSERT_EQUAL_NUMBER(board.getWinPoint(), 5);
   ASSERT_EQUAL_NUMBER(board.getDataOf(3, 3), NONE);

   Board newBoard(3, 3, 3);
   newBoard = board;

   // A a;
   // a.a = 5;
   // A b;
   // b.a = 3;
   // b = a;
   // cout << b.a;

   // ASSERT_EQUAL_NUMBER(newBoard.getWidth(), 5);
   // ASSERT_EQUAL_NUMBER(newBoard.getHeight(), 5);
   // ASSERT_EQUAL_NUMBER(newBoard.getWinPoint(), 5);
   // ASSERT_EQUAL_NUMBER(newBoard.getDataOf(3, 3), NONE);
}

void test_with_board_10x10() {
   Board board(10, 10, Point(5, 5, X), 3);

   ASSERT_EQUAL_BOOLEAN(board.shouldBeChecked(2, 2), false);
   ASSERT_EQUAL_BOOLEAN(board.isValid(10, 10), false);
   ASSERT_EQUAL_BOOLEAN(board.isValid(0, 0), true);
   ASSERT_EQUAL_BOOLEAN(board.isValid(5, 5), true);
}

int main() {
   test_with_board_3x3();
   test_with_board_5x5();
   test_with_board_10x10();

   return 0;
}