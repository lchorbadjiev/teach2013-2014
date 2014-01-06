#ifndef RECTANGLE_HH__
#define RECTANGLE_HH__

#include "shape.hh"
#include "point.hh"

class Rectangle: public Shape {
	Point bl_;
	Point tr_;
public:
	Rectangle(const Point& bl, const Point& tr)
	: bl_(bl), tr_(tr)
	{}
	
	virtual void draw();
};


#endif
