#include <iostream>
using namespace std;

class Rational {
	long num_;
	long den_;

	long gcd(long a, long b) {
		while(b!=0) {
			long temp=a;
			a=b;
			b=temp%b;
		}
		return a;
	}

	void normalize() {
		long g=gcd(num_,den_);
		num_/=g;
		den_/=g;
	}

public:
	Rational(long num,long den) {
		num_=num;
		den_=den;
		normalize();
	}
	void print() {
		cout << '(' << num_ << '/' << den_ << ')' << endl;
	}
	void add(Rational r) {
		num_=num_*r.den_+den_*r.num_;
		den_=den_*r.den_;
		normalize();
	}
	void sub(Rational r) {
		num_=num_*r.den_-den_*r.num_;
		den_=den_*r.den_;
		normalize();
	}

	
};

int main() {
	Rational r1(1,2);
	Rational r2(3,4);
	
	r1.print();
	r2.print();

	r1.add(r2);
	r1.print();

/*
	cout << r1.gcd(10,2) << ' '
		<< r1.gcd(3,6) << ' ' 
		<< r1.gcd(144,12) << endl;
*/
	return 0;
}








