#include <iostream>
using namespace std;


class Point {
	double x_, y_;
/*
	Point(const Point& other)
	{}
*/

public:
	explicit Point(double x=0.0, double y=0.0)
	: x_(x),
	  y_(y)
	{}
	
	~Point(void) {
		cout << "~Point()" << endl;
	}
	

	Point(const Point& other)
	: x_(other.x_),
	  y_(other.y_)
	{
		cout << "Point(Point&)" << endl;
	}
	

	inline double get_x() const {
		// const Point * const this;
		// this->x_=15; ERRRROOOOR!!!!
		return x_;
	}

	double get_y() const;


	Point& operator+=(const Point other) {
		// p2+=p3; =>
		// this == &p2;
		// Point *const this;
		
		x_+=other.x_;
		y_+=other.y_;
		
		return *this;
	}

	

};


ostream& operator<<(ostream& out, const Point& p) {
	out << '(' << p.get_x() << ',' << p.get_y() << ')';

	return out;
}

inline double Point::get_y() const {
	return y_;
}

Point operator+(const Point& p1, const Point& p2) {
	Point res(p1);
	res+=p2;
	return res;
}



int main() {

	Point p1;
	p1.get_x();
	p1.get_y();

	Point p2(10,20);
	Point p3(30,40);
	p1 = p2 += p3;	
	
	(cout << p1) << p2 << endl;
	
	//(p1 + p2) = p3
	p3 = (p1 + p2) + p3 + Point(5);
	
	Point p4 = Point(5); Point(5);
	double a = 5;
	
	return 0;
}






