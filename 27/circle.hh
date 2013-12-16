#ifndef CIRCLE_HH__
#define CIRCLE_HH__

#include "base.hh"
#include "point.hh"

class Circle: public Shape {
	double r_;
	Point o_;
public:
	Circle(const Point& o, double r)
	: o_(o), r_(r)
	{}
	
	void draw();
};

#endif

