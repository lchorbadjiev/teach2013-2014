#include<algorithm>
#include<iostream>
#include<list>
using namespace std;

class less_than {
	int value_;
public:
	less_than(int v)
	: value_(v)
	{}

	bool operator()(int val) {
		return val < value_;
	}
};

class gt {
	int value_;
public:
	gt(int v)
	: value_(v)
	{}
	
	bool operator()(int val) {
		return val > value_;
	}
};

int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	list<int> l(a, a+10);
	
	less_than lt10(10);
	cout << lt10(1) << endl;
	cout << lt10(50) << endl;

	gt gt7(7);
	cout << gt7(3) << endl;
	cout << gt7(8) << endl;

	list<int>::iterator it=find_if(l.begin(), l.end(), gt7);
	if(it!=l.end()) {
		cout << "element found..." << endl;
		cout << "val=" << *it << endl;
	}

	it = find_if(l.begin(), l.end(), lt10);
	if(it!=l.end()) {
		cout << "element found..." << endl;
		cout << "val=" << *it << endl;
	}

	int c = count_if(l.begin(), l.end(), gt7);
	cout << "gt7: " << c << endl;
	
	c = count_if(l.begin(), l.end(), lt10);
	cout << "lt10: " << c << endl;
	
}

