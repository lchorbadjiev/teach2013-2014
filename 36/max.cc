#include <iostream>
#include <string>
using namespace std;

template<typename T>
T maxvalue(const T& a, const T& b) {
	return (a>b)?a:b;
}


int main() {
	cout << maxvalue<int>(10, 15) << endl;
	cout << maxvalue<double>(1.1, 0) << endl;
	cout << maxvalue<string>("zhello", "world") << endl;
	cout << maxvalue<string>("1000", "2") << endl;
	
	int a = 10;
	double e = 1.1;
	
	a=e;
	e=a;
	
	return 0;
}

