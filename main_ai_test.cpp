// #include <iostream>
// #include "src/ai/ai.hpp"

// using namespace std;

// const int WIDTH = 3;
// const int HEIGHT = 3;

// void drawPoint(PointType** board) {
//    cout << "\n";
//    for (int x = 0; x < WIDTH; x++) {
//       for (int y = 0; y < WIDTH; y++) {
//          if (board[x][y] == NONE) cout << " ";
//          else if (board[x][y] == X) cout << "X";
//          else cout << "O";
//       }
//       cout << "\n";
//    }
// }

// int main() {
//    PointType** board;
//    board = new PointType*[9];

//    for (int i = 0; i < 9; i++) {
//       board[i] = new PointType[9];
//    }

//    for (int x = 0; x < WIDTH; x++) {
//       for (int y = 0; y < WIDTH; y++) {
//          board[x][y] = NONE;
//       }
//    }

//    drawPoint(board);
//    Point currentMove = {
//       x: 1,
//       y: 1,
//       type: X,
//    };
//    for (int i = 0; i < 9; i++) {
//       Point newMove = generateMove(WIDTH, HEIGHT, board, currentMove);
//       board[newMove.x][newMove.y] = O;
//       currentMove = newMove;
//    }

//    return 0;
// }