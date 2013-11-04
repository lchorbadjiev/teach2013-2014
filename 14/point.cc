#include <iostream>
#include <fstream>
using namespace std;


class Point {
	double x_, y_;
public:
	Point(double x=0.0,double y=0.0)
	: x_(x), y_(y)
	{}
	
	double get_x() const {
		return x_;
	}

	double get_y() const {
		return y_;
	}
	
	void add(const Point& p) {
		x_+=p.get_x();
		y_+=p.get_y();
	}
	
	Point& operator+=(const Point& p) {
		x_+=p.get_x();
		y_+=p.get_y();
		return *this;
	}

	Point& operator-=(const Point& p) {
		x_-=p.get_x();
		y_-=p.get_y();
		return *this;
	}

	Point& operator*=(double a) {
		x_*=a;
		y_*=a;
		return *this;
	}

};

Point operator+(const Point& p1, const Point& p2) {
	Point res(p1);
	res+=p2;
	return res;
}

Point operator-(const Point& p1, const Point& p2) {
	Point res(p1);
	res-=p2;
	return res;
}

Point operator*(double a,const Point& p) {
	Point res(p);
	res*=a;
	return res;
}

Point operator*(const Point& p,double a) {
	return a*p;
}

Point operator-(const Point& p) {
	return -1*p;
}


ostream& operator<<(ostream& out,const Point& p) {
	out << "(" << p.get_x() << ", " << p.get_y() << ")";
	return out;
}


int main() {
	Point p1(10,20),p2(30,40),p3;

	cout << p1;// operator<<(cout,p1);

	cout << p1 << p2 << p2 << endl;

	ofstream out("ala-bala.txt");
	out << p1 << p2 << p3 << endl;
	
	
	p1.add(p2);
	(cout << "p1: ") << p1.get_x() << ", " << p1.get_y() << endl;

	p1+=p2;
	cout << "p1: " << p1.get_x() << ", " << p1.get_y() << endl;

	//p1.operator+=(p2);
	p3=p1+p2;
	cout << "p3: " << p3.get_x() << ", " << p3.get_y() << endl;

	p1-=p2;
	cout << "p1: " << p1.get_x() << ", " << p1.get_y() << endl;
	
	p3=p1-p2;
	cout << "p3: " << p3.get_x() << ", " << p3.get_y() << endl;
	
	p1*=2.0;
	cout << "p1: " << p1.get_x() << ", " << p1.get_y() << endl;

	p3=0.5*p1;
	cout << "p3: " << p3.get_x() << ", " << p3.get_y() << endl;
	p3=p1*0.5;
	cout << "p3: " << p3.get_x() << ", " << p3.get_y() << endl;
	
	
	p3=-p1;
	cout << "p3: " << p3.get_x() << ", " << p3.get_y() << endl;
	
	p3=(p1+p2)+p1;
	
	return 0;
}























