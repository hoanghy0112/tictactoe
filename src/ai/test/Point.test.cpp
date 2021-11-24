#include <iostream>

#include <ai/test/utils.hpp>
#include <ai/utils/Point.hpp>

using namespace std;

void test_Point() {
   Point a;
   a.x = 3;
   a.y = 4;
   a.type = X;

   Point b(3, 3, X);
   Point b1(4, 4, X);
   Point b2(3, 4, O);
   
   Point c(b);

   ASSERT_EQUAL_BOOLEAN((a == b), false);
   ASSERT_EQUAL_BOOLEAN((a == b1), false);
   ASSERT_EQUAL_BOOLEAN((a == b2), false);
   ASSERT_EQUAL_BOOLEAN((c == b), true);

   ASSERT_EQUAL_BOOLEAN(((!a) == Point(3, 4, O)), true);

   ASSERT_EQUAL_STRING(c.to_string(), b.to_string());
}

void test_Node() {
   Node a;
   Node b(10, Point(2, 3, O), PENDING);
   Node c(b);

   ASSERT_EQUAL_NUMBER(b.value, 10);
   ASSERT_EQUAL_NUMBER(b.point.x, 2);
   ASSERT_EQUAL_NUMBER(b.point.y, 3);
   ASSERT_EQUAL_NUMBER(b.point.type, O);
   ASSERT_EQUAL_NUMBER(b.state, PENDING);

   ASSERT_EQUAL_NUMBER(10, maxNode(a, b).value);
   ASSERT_EQUAL_NUMBER(0, minNode(a, b).value);
}

int main() {
   test_Point();
   cout << "Point testng\n";

   return 0;
}