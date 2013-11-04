#include <iostream>
using namespace std;


class Point {
	double x_;
	double y_;
public:
	Point(double x=0.0,double y=0.0) 
	: x_(x),
	  y_(y)
	{
	}
/*
	Point() {
		x_=0.0;
		y_=0.0;
	}
*/
	double get_x() const {
		//x_=15.0;
		return x_;
	}
	
	double get_y() const {
		// return y_;
		
		return this->y_;
	}


	Point& set_x(double x) {
		x_=x;
		return *this;
	}

	Point& set_y(double y) {
		y_=y;
		return *this;
	}

};

int main() {
	int a=0;
	
	int b;
	b=0;
	
	const int c=42;
	//c=43;
	
	
	Point p1(2.0,2.0);
	Point p2;

	(((cout << p1.get_x()) << ',' )<< p1.get_y() )<< endl;
	cout << p2.get_x() << ',' << p2.get_y() << endl;

	Point p3(3.0);
	cout << p3.get_x() << ',' << p3.get_y() << endl;


	const Point cp(0.0,0.0);
	cp.get_x();

	Point p4;
	p4.set_x(15.0);
	p4.set_y(16.0);
	
	(p4.set_x(17.0)).set_y(18.0);
	
	cout << p4.get_x() << ',' << p4.get_y() << endl;
	

		
	return 0;
}








