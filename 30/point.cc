#include "point.hh"

#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, const Point& p) {
	out << '(' << p.get_x() << ',' << p.get_y() << ')';
	return out;
}
