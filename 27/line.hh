#ifndef LINE_HH__
#define LINE_HH__

#include "base.hh"
#include "point.hh"

class Line: public Shape {
	Point a_, b_;
public:
	Line(const Point& p1, const Point& p2)
	: a_(p1), b_(p2)
	{}
	
	void draw();
};

#endif

