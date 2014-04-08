#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

class lt {
	int value_;
public:
	lt(int v)
	: value_(v)
	{}
	
	bool operator()(int val) {
		return val<value_;
	}

};

class gt {
	int value_;
public:
	gt(int v)
	:value_(v)
	{}
	
	bool operator()(int val) {
		return val > value_;
	}
};

class range {
	int l_;
	int r_;
public:
	range(int l, int r)
	: l_(l), r_(r)
	{}
	
	bool operator()(int val) {
		return val>l_ && val<r_;
	}

};


int main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	list<int> l(a, a+10);
	
	lt lt10(10);
	
	cout << lt10(3) << endl;
	cout << lt10(50) << endl;
	cout << lt10(10) << endl;

	gt gt7(7);
	cout << gt7(3) << endl;
	cout << gt7(7) << endl;
	cout << gt7(8) << endl;

	list<int>::iterator it;
	
	it=find_if(l.begin(), l.end(), gt(14));
	if(it!=l.end()) {
		cout << "element found" << endl;
		cout << "val=" << *it << endl;
	} else {
		cout << "element NOT found" << endl;
	}


	int c=0;
	c = count_if(l.begin(), l.end(), gt(3));
	cout << "count=" << c << endl;
	
	c = count_if(l.begin(), l.end(), range(3,15));
	cout << "count=" << c << endl;

	less<int> LT;
	
	cout << "less: " << LT(1,3) <<endl;	
	cout << "less: " << LT(3,1) <<endl;	
	
	return 0;
}

