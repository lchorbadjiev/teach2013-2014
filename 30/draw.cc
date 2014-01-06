#include <iostream>
#include <vector>

using namespace std;


class Point {
	double x_, y_;
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


class Shape {
public:
	virtual void draw() = 0;
};

class Circle: public Shape {
	Point c_;
	double r_;
public:
	Circle(const Point& c, double r)
	: c_(c), r_(r)
	{}
	
	virtual void draw() {
		cout << "Circle{" << c_ << ',' << r_ << '}' << endl;
	}
};

class Rectangle: public Shape {
	Point bl_;
	Point tr_;
public:
	Rectangle(const Point& bl, const Point& tr)
	: bl_(bl), tr_(tr)
	{}
	
	virtual void draw() {
		cout << "Rectangle{" << bl_ << ',' << tr_ << '}' << endl;
	}
};


class CompositeShape: public Shape {
	vector<Shape*> shapes_;
public:

	void add_shape(Shape* sh) {
		shapes_.push_back(sh);
	}

	virtual void draw() {
		cout << "Composite{" << endl;
		for(vector<Shape*>::iterator it=shapes_.begin();
			it!=shapes_.end();++it) {
			
			(*it) ->draw();	
		}
		cout << "}" << endl;
	}
};

int main() {

	//Shape sh; 

	Circle c(Point(0,0),10);
	Rectangle r(Point(0,0), Point(10,10));
	CompositeShape cs;
	cs.add_shape(&c);
	cs.add_shape(&r);
	
	vector<Shape*> drawing;
	drawing.push_back(&c);
	drawing.push_back(&r);
	drawing.push_back(&cs);
	
	for(vector<Shape*>::iterator it=drawing.begin();
		it!=drawing.end();++it) {
		
		(*it) -> draw();	
	}
	
	return 0;
}

