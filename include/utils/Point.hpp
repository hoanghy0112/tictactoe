#pragma once

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
};


struct Node {
   float value;
   Point point;
   NodeState state;
};

Node maxNode(Node first, Node second);
Node minNode(Node first, Node second);