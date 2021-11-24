#include <ai/utils/Point.hpp>
#include <string>


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

std::string Point::to_string() {
   std::string res;
   res = std::to_string(this->x) + std::string("; ") + std::to_string(this->y) + std::string("; ") + std::to_string(this->type);
   return res;
}

Node::Node() {
   this->value = 0;
   this->state = INITIAL;
}

Node::Node(float value, Point point, NodeState state) {
   this->value = value; 
   this->point = point;
   this->state = state;
}

Node::Node(Node& other) {
   this->value = other.value;
   this->point = other.point;
   this->state = other.state;
}

// Node maxNode(Node first, Node second) {
//    if (first.value > second.value) return first;
//    else return second;
// }

// Node minNode(Node first, Node second) {
//    if (first.value < second.value) return first;
//    else return second;
// }