#include <iostream>
#include <vector>
using namespace std;


class Shape {

public:
	virtual void draw() = 0;

};

class Point {
	double x_,y_;
public:
	Point(double x=0.0, double y=0.0)
	: x_(x), y_(y)
	{}
	
	double get_x() const {
		return x_;
	}
	double get_y() const {
		return y_;
	}
};

ostream& operator<<(ostream& out, const Point& p) {
	out << '(' << p.get_x() << ',' << p.get_y() << ')';
	return out;
}

class Circle: public Shape {
	double r_;
	Point o_;
public:
	Circle(const Point& o, double r)
	: o_(o), r_(r)
	{}
	
	void draw() {
		cout << "Circle(" << o_ << "," << r_ << ")" << endl;
	}
};

class Line: public Shape {
	Point a_, b_;
public:
	Line(const Point& p1, const Point& p2)
	: a_(p1), b_(p2)
	{}
	
	void draw() {
		cout << "Line(" << a_ << ',' << b_ << ')' << endl;
	}
};

class Composite: public Shape {
	vector<Shape*> shapes_;
public:
	
	void add(Shape* sh) {
		shapes_.push_back(sh);
	}
	
	void draw() {
		cout << "C{" << endl;
		for(vector<Shape*>::iterator it = shapes_.begin();
			it!=shapes_.end(); ++it) {
		
			(*it) -> draw();	
		}
		cout << "}" << endl;
	}
	
};


int main() {
	Shape* psh;
	//Shape sh;
	Circle c1(Point(0,0), 10.0);
	Circle c2(Point(10,10), 20.0);
	c1.draw();
	c2.draw();
	
	Line l1(Point(0,0), Point(10,10));
	l1.draw();
	
	Composite comp;
	comp.add(new Circle(Point(0,0), 10));
	comp.add(new Circle(Point(10,10),10));
	comp.add(new Line(Point(0,0), Point(10,10)));
	
	comp.draw();
	
	
	
	
	return 0;
}







