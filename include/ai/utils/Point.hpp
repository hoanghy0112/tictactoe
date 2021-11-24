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
   INITIAL,
   PENDING,
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


class Node {
   public: 
      float value;
      Point point;
      NodeState state;

      Node();
      Node(float, Point, NodeState);
      Node(Node &);
      
};

Node maxNode(Node first, Node second);
Node minNode(Node first, Node second);

