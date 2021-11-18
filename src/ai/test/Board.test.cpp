#include <iostream>
#include <string>

#include <ai/test/utils.hpp>
#include <ai/utils/Board.hpp>

using namespace std;

void test_with_board_3x3() {
   Test::TestClass test;

   Board board(3, 5, Point(2, 2, X), 3);
   test.run<int>(board.getWidth(), 3);
   test.run<int>(board.getHeight(), 5);
   test.run<int>(board.getWinPoint(), 3);
   string msg = "" + board.getCurrentMove().x;
   test.run<Point>(board.getCurrentMove(), Point(3, 2, X), msg);
}

int main() {
   test_with_board_3x3();

   return 0;
}