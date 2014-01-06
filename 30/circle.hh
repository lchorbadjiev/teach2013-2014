#ifndef CIRCLE_HH__
#define CIRCLE_HH__

#include "shape.hh"
#include "point.hh"

class Circle: public Shape {
	Point c_;
	double r_;
public:
	Circle(const Point& c, double r)
	: c_(c), r_(r)
	{}
	
	virtual void draw();
};

#endif
