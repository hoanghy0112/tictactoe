#include <ai/utils/Point.hpp>

Node maxNode(Node first, Node second) {
   if (first.value > second.value) return first;
   else return second;
}

Node minNode(Node first, Node second) {
   if (first.value < second.value) return first;
   else return second;
}


Point::Point() {
   this->x = 0;
   this->y = 0;
   this->type = UNDEFINED;
}

Point::Point(int x, int y, PointType type) {
   this->x = x;
   this->y = y;
   this->type = type;
}

Point::Point(Point& other) {
   this->x = other.x;
   this->y = other.y;
   this->type = other.type;
}

Point Point::operator!() {
   PointType newType;
   if (this->type == O) newType = X;
   else newType = O;
   return Point(this->x, this->y, newType);
}

bool Point::operator==(Point other) {
   if (other.type != this->type) return false;
   if (other.x != this->x) return false;
   if (other.y != this->y) return false;
   
   return true;
}