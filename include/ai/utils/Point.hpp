#pragma once

#include <string>

enum PointType
{
   UNDEFINED,
   NONE,
   X,
   O,
   OUT_OF_SCOPE,
};

enum NodeState {
   PROCESSING,
   DONE,
   TERMINAL,
   ERROR,
};

class Point
{
   public:
      int x;
      int y;
      PointType type;

      Point();
      Point(int x, int y, PointType type);
      Point(Point& );

      Point operator!();
      bool operator==(Point other);

      std::string to_string();
};


struct Node {
   float value;
   Point point;
   NodeState state;
};

Node maxNode(Node first, Node second);
Node minNode(Node first, Node second);
