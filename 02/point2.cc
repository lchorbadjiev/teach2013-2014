#include <iostream>
using namespace std;

class point {
	double x_;
	double y_;

public:
	point(double x,double y) {
		x_=x;
		y_=y;
	}
	point() {
		x_=0.0;
		y_=0.0;
	}

	double get_x() {
		return x_;
	}
	double get_y() {
		return y_;
	}
	
	void set_x(double x) {
		x_=x;
	}
	void set_y(double y) {
		y_=y;
	}
	
	void add(point p) {
		x_+=p.x_;
		y_+=p.y_;
	}
	
};
int main() {
	point p1(10,20);
	point p2(30,40);
	point p3;
	cout << "p1.get_x(): " << p1.get_x() << "; "
		<< "p1.get_y(): " << p1.get_y() << endl;
	
	cout << "p2.get_x(): " << p2.get_x() << "; "
		<< "p2.get_y(): " << p2.get_y() << endl;

	p1.add(p2);
	
	cout << "p1.get_x(): " << p1.get_x() << "; "
		<< "p1.get_y(): " << p1.get_y() << endl;
	

	return 0;
}





