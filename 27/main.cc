#include "point.hh"
#include "circle.hh"
#include "line.hh"

#include <iostream>
using namespace std;

int main() {

	Point p1(0,0), p2(10,10);
	cout << p1 << p2 << endl;


	Circle c1(Point(0,0), 10.0);
	Circle c2(Point(10,10), 20.0);
	c1.draw();
	c2.draw();
	
	Line l1(Point(0,0), Point(10,10));
	l1.draw();
}

