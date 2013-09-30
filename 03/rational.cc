#include <iostream>
using namespace std;


class Rational {
	long num_;
	long den_;
	
	long gcd(long a,long b) {
		while(b!=0) {
			long temp=a;
			a=b;
			b=temp%a;
		}
		return a;
	}
	
	
	void normalize() {
		long d=gcd(num_,den_);
		num_/=d;
		den_/=d;	
	}
public:
	Rational(long num, long den) {
		num_=num;
		den_=den;
		normalize();
	}

	void print() {
		cout << "(" << num_ << "/" << den_ << ")";
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
	
	void neg() {
		num_=-num_;
	}
};


int main() {
	Rational r1(1,2);
	Rational r2(3,4);
	
	r1.print();
	r2.print();
	cout << endl;

	r1.add(r2);
	r1.print();
	cout << endl;
	
	//cout << r1.gcd(5,35) << ' ' << r1.gcd(15,35) << ' ' << r1.gcd(10,8) << endl;	
	
	return 0;
}

